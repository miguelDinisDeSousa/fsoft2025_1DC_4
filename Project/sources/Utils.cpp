#include "Utils.h"
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<std::string> Utils::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Utils::saveToFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename, std::ios::app);
    if (file) {
        file << data << "\n";
    }
}

std::string Utils::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)), 
                        std::istreambuf_iterator<char>());
    return content;
}

bool Utils::fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

std::string Utils::trim(const std::string& str) {
    auto start = std::find_if_not(str.begin(), str.end(), ::isspace);
    auto end = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
    return (start < end) ? std::string(start, end) : "";
}
