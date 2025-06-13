#include <cstring>
#include "DataConsistencyException.h"

DataConsistencyException::DataConsistencyException(char* reason) {
    strncpy(this->reason, reason, EXCEPTION_REASON_MAX_LEN);
    this->reason[EXCEPTION_REASON_MAX_LEN-1] = '\0';
}

DataConsistencyException::DataConsistencyException(const char* reason) {
    strncpy(this->reason, reason, EXCEPTION_REASON_MAX_LEN);
    this->reason[EXCEPTION_REASON_MAX_LEN-1] = '\0';
}

const char* DataConsistencyException::what() {
    return this->reason;
}