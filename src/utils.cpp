#include "../include/utils.h"
#include <regex>
#include <iostream>

std::string getDomainFromURL(const std::string& url) {
    std::regex domainRegex(R"((?:https?:\/\/)?(?:www\.)?([^\/]+))");
    std::smatch match;
    std::string domain;
    
    if (std::regex_search(url, match, domainRegex) && match.size() > 1) {
        domain = match[1].str();
    } else {
        domain = "unknown";
    }
    
    std::regex illegalChars("[\\/:*?\"<>|]");
    domain = std::regex_replace(domain, illegalChars, "_");
    
    std::cout << "URL extraite: " << url << " => domaine: " << domain << std::endl;
    return domain;
}
