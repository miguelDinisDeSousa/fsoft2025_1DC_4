#pragma once
#include <vector>
#include <string>
#include <fstream>

class Utils {
public:
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static void saveToFile(const std::string& filename, const std::string& data);
    static std::string readFromFile(const std::string& filename);
    static bool fileExists(const std::string& filename);
    static std::string trim(const std::string& str);
};
