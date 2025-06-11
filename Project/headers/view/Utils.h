//
// Created by carlo on 04/06/2025.
//

#ifndef FSOFT2025_1DC_4_UTILS_H
#define FSOFT2025_1DC_4_UTILS_H

#ifndef UTILS_CLASS_INCLUDE
#define UTILS_CLASS_INCLUDE
#include <cstring>

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
    FILTER_CONTENT,
    FILTER_NONE,
    FILTER_UNKNOWN = -1
} FilterType;

namespace Utils {
    int getNumber(const char*);
    void getString(const char*, char*&, size_t = 1);
    double getDouble(const char*);
    void clearOutput();
    void getCurrentDate(unsigned int&, unsigned int&, unsigned int&);
}

#endif

#endif //FSOFT2025_1DC_4_UTILS_H
