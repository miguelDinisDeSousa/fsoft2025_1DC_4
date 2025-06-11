//
// Created by carlo on 04/06/2025.
//

#ifndef FSOFT2025_1DC_4_UTILS_H
#define FSOFT2025_1DC_4_UTILS_H

#ifndef UTILS_CLASS_INCLUDE
#define UTILS_CLASS_INCLUDE
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <sstream>

typedef enum {
    UNIX_OS = 0,
    WINDOWS_OS,
    UNKNOWN_OS
} OperatingSystem;

typedef enum {
    FILTER_ID = 0,
    FILTER_NAME,
    FILTER_ADDRESS,
    FILTER_USER,
    FILTER_NONE,
    FILTER_UNKNOWN = -1
} FilterType;

namespace Utils {
    int getNumber(const char*);
    void getString(const char*, char*&, size_t = 1);
    double getDouble(const char*);
    void clearOutput();
    void getCurrentDate(unsigned int&, unsigned int&, unsigned int&);
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static void saveToFile(const std::string& filename, const std::string& data);
    static std::string readFromFile(const std::string& filename);
    static bool fileExists(const std::string& filename);
    static std::string trim(const std::string& str);
}

#endif

#endif //FSOFT2025_1DC_4_UTILS_H
