#include <cstring>
#include "DuplicatedDataException.h"

DuplicatedDataException::DuplicatedDataException(char* reason) {
    strncpy(this->reason, reason, EXCEPTION_REASON_MAX_LEN);
    this->reason[EXCEPTION_REASON_MAX_LEN-1] = '\0';
}

DuplicatedDataException::DuplicatedDataException(const char* reason) {
    strncpy(this->reason, reason, EXCEPTION_REASON_MAX_LEN);
    this->reason[EXCEPTION_REASON_MAX_LEN-1] = '\0';
}

const char* DuplicatedDataException::what() {
    return this->reason;
}
