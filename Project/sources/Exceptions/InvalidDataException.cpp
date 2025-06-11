#include <cstring>
#include "InvalidDataException.h"

InvalidDataException::InvalidDataException(char* reason) {
    strncpy(this->reason, reason, EXCEPTION_REASON_MAX_LEN);
    this->reason[EXCEPTION_REASON_MAX_LEN-1] = '\0';
}

InvalidDataException::InvalidDataException(const char* reason) {
    strncpy(this->reason, reason, EXCEPTION_REASON_MAX_LEN);
    this->reason[EXCEPTION_REASON_MAX_LEN-1] = '\0';
}

const char* InvalidDataException::what() {
    return this->reason;
}
