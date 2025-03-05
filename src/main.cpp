#include <iostream>
#include <string>
#include <filesystem>
#include <chrono>
#include <fstream>

#include "../include/CScraper.h"
#include "../include/utils.h"

namespace fs = std::filesystem;

int createFolder(const std::string& folderName) {
    try {
        fs::path currentPath = fs::current_path();
        fs::path folderPath = currentPath / folderName;
        
        std::cout << "Tentative de création du dossier: " << folderPath << std::endl;
        
        if (fs::exists(folderPath)) {
            std::cout << "[+] Dossier déjà existant : " << folderPath << std::endl;
            return 1;
        }
        
        if (fs::create_directory(folderPath)) {
            std::cout << "[+] Dossier créé : " << folderPath << std::endl;
            return 1;
        } else {
            std::cerr << "[-] Échec de la création du dossier : " << folderPath << std::endl;
            return 0;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "[-] Erreur filesystem lors de la création du dossier : " << e.what() << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "[-] Exception lors de la création du dossier : " << e.what() << std::endl;
        return 0;
    }
}

int main(int argc, char* argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    
    try {
        std::string testFile = "test_access.txt";
        std::ofstream test(testFile);
        if (test.is_open()) {
            test << "Test d'accès en écriture" << std::endl;
            test.close();
            std::cout << "Test d'écriture réussi!" << std::endl;
            fs::remove(testFile);
        } else {
            std::cerr << "[-] Impossible d'écrire dans le répertoire courant. Vérifiez vos permissions." << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "[-] Exception lors du test d'écriture: " << e.what() << std::endl;
        return 1;
    }
    
    if (argc != 2) {
        std::cerr << "Utilisation : " << argv[0] << " <URL>" << std::endl;
        return 1;
    }

    std::string url = argv[1];
    std::string domain = getDomainFromURL(url);
    
    std::cout << "Domaine extrait: " << domain << std::endl;
    
    if (!createFolder(domain)) {
        std::cerr << "[-] Échec critique: Impossible de créer le dossier pour les résultats." << std::endl;
        return 1;
    }
    
    CScraper scraper(url);
    
    if (!scraper.fetchHTML()) {
        std::cerr << "[-] Échec de récupération du HTML." << std::endl;
        return 1;
    }
    
    if (!scraper.extractLinks()) {
        std::cerr << "[-] Échec d'extraction des liens." << std::endl;
        return 1;
    }
    
    if (!scraper.saveToFile(domain)) {
        std::cerr << "[-] Échec de sauvegarde des résultats." << std::endl;
        return 1;
    }
    
    std::cout << "[+] Opération réussie!" << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Temps d'exécution total : " << elapsed.count() << " secondes" << std::endl;

    return 0;
}
