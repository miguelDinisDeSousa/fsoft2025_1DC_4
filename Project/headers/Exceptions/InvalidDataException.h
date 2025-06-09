//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_INVALIDDATAEXCEPTION_H
#define FSOFT2025_1DC_4_INVALIDDATAEXCEPTION_H

#define EXCEPTION_REASON_MAX_LEN 128

#include <exception>

class InvalidDataException : public std::exception {
private:
    char reason[EXCEPTION_REASON_MAX_LEN];
public:
    InvalidDataException(const char*);
    InvalidDataException(char*);
    const char* what();
};

#endif //FSOFT2025_1DC_4_INVALIDDATAEXCEPTION_H
