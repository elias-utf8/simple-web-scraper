#include "../include/CScraper.h"
#include "../include/utils.h"
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <regex>
#include <filesystem>
#include <errno.h>
#include <string.h>

namespace fs = std::filesystem;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

CScraper::CScraper(const std::string& url) : url(url) {}

bool CScraper::fetchHTML() {
    CURL* curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "[-] Erreur d'initialisation de curl" << std::endl;
        return false;
    }
    
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlContent);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
    
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    
    if (res != CURLE_OK) {
        std::cerr << "[-] Erreur curl: " << curl_easy_strerror(res) << std::endl;
        return false;
    }
    
    std::cout << "[+] Contenu HTML récupéré avec succès" << std::endl;
    return true;
}

bool CScraper::extractLinks() {
    std::regex linkRegex("<a\\s+[^>]*href\\s*=\\s*['\"]([^'\"]+)['\"][^>]*>");
    
    auto links_begin = std::sregex_iterator(htmlContent.begin(), htmlContent.end(), linkRegex);
    auto links_end = std::sregex_iterator();
    
    for (std::sregex_iterator i = links_begin; i != links_end; ++i) {
        std::smatch match = *i;
        if (match.size() > 1) {
            extractedLinks.push_back(match[1].str());
        }
    }
    
    if (extractedLinks.empty()) {
        std::cerr << "[-] Aucun lien n'a été extrait" << std::endl;
        return false;
    }
    
    std::cout << "[+] " << extractedLinks.size() << " liens ont été extraits" << std::endl;
    return true;
}

bool CScraper::saveToFile(const std::string& folderName) const {
    fs::path currentPath = fs::current_path();
    fs::path folderPath = currentPath / folderName;
    
    if (!fs::exists(folderPath)) {
        std::cout << "Le dossier n'existe pas, tentative de création: " << folderPath << std::endl;
        try {
            if (!fs::create_directory(folderPath)) {
                std::cerr << "[-] Impossible de créer le dossier: " << folderPath << std::endl;
                return false;
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "[-] Erreur lors de la création du dossier: " << e.what() << std::endl;
            return false;
        }
    }
    
    fs::path htmlFilePath = folderPath / "content.html";
    fs::path linksFilePath = folderPath / "links.txt";
    
    std::ofstream htmlFile(htmlFilePath.string());
    if (!htmlFile.is_open()) {
        std::cerr << "[-] Erreur lors de l'ouverture du fichier HTML: " << htmlFilePath << std::endl;
        std::cerr << "   Erreur: " << strerror(errno) << std::endl;
        return false;
    }
    
    std::ofstream linksFile(linksFilePath.string());
    if (!linksFile.is_open()) {
        std::cerr << "[-] Erreur lors de l'ouverture du fichier liens: " << linksFilePath << std::endl;
        std::cerr << "   Erreur: " << strerror(errno) << std::endl;
        htmlFile.close();
        return false;
    }
    
    htmlFile << htmlContent;
    for (const auto& link : extractedLinks) {
        linksFile << link << std::endl;
    }
    
    htmlFile.close();
    linksFile.close();
    
    std::cout << "[+] Fichiers sauvegardés avec succès dans " << folderPath << std::endl;
    return true;
}
