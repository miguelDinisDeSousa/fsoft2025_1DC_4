//
// Created by carlo on 31/05/2025.
//

#include "Notification.h"
#include "InvalidDataException.h"
#include "DataConsistencyException.h"

Notification::Notification(unsigned int& id, const char* message, const char* date, bool read) {
    setId(id);
    setMessage(message);
    setDate(date);
    setRead(read);
}

// Getters
unsigned int Notification::getId() const {
    return this->id;
}

const char* Notification::getMessage() const {
    return this->message;
}

const char* Notification::getDate() const {
    return this->date;
}

bool Notification::isRead() const {
    return this->read;
}

// Setters
void Notification::setId(unsigned int& id) {
    this->id = id;
}

void Notification::setMessage(const char* msg) {
    if (!msg) {
        throw InvalidDataException("Invalid pointer to message.");
    }

    size_t len = strlen(msg);
    if (len < 1 || len > NOTIFICATION_MAX_MSG_LEN) {
        throw DataConsistencyException("Message must be between 1 and 256 characters.");
    }

    strncpy(this->message, msg, NOTIFICATION_MAX_MSG_LEN);
    this->message[NOTIFICATION_MAX_MSG_LEN - 1] = '\0';
}

void Notification::setDate(const char* date) {
    if (!date) {
        throw InvalidDataException("Invalid pointer to date.");
    }

    size_t len = strlen(date);
    if (len < 4 || len > NOTIFICATION_MAX_DATE_LEN) {
        throw DataConsistencyException("Date must be between 4 and 32 characters.");
    }

    strncpy(this->date, date, NOTIFICATION_MAX_DATE_LEN);
    this->date[NOTIFICATION_MAX_DATE_LEN - 1] = '\0';
}

void Notification::setRead(bool read) {
    this->read = read;
}

