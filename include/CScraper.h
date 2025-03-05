#ifndef CSCRAPER_H
#define CSCRAPER_H

#include <vector>
#include <string>
#include <regex>

class CScraper {
public:
    CScraper(const std::string& url);
    bool fetchHTML();
    bool extractLinks();
    bool saveToFile(const std::string& folderName) const;

private:
    std::string url;
    std::string htmlContent;
    std::vector<std::string> extractedLinks;
};

#endif // CSCRAPER_H
