#ifndef UTILS_CLASS_INCLUDE
#define UTILS_CLASS_INCLUDE

#include <cstring>
#include <vector>

typedef enum {
    UNIX_OS = 0,
    WINDOWS_OS,
    UNKNOWN_OS
} OperatingSystem;

typedef enum {
    FILTER_ID = 0,
    FILTER_NAME,
    FILTER_CONTENT,
    FILTER_ADDRESS,
    FILTER_USER,
    FILTER_NONE,
    FILTER_TYPE,
    FILTER_DATE,
    FILTER_UNKNOWN = -1
} FilterType;

namespace Utils {
    char getCharIfAllowed(std::vector<char> allowedChars);
    int getNumber(const char*);
    void getString(const char*, char*&, size_t = 1);
    double getDouble(const char*);
    void clearOutput();
    void getCurrentDate(unsigned int&, unsigned int&, unsigned int&);
    OperatingSystem getCurrentOS();  // <- Adicionada esta função
}

#endif // UTILS_CLASS_INCLUDE

