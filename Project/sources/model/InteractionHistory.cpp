//
// Created by carlo on 31/05/2025.
//
#include "InteractionHistory.h"
#include "InvalidDataException.h"
#include "DataConsistencyException.h"

InteractionHistory::InteractionHistory(const char* date, const char* type, const char* content) {
    setDate(date);
    setType(type);
    setContent(content);
}

// Getters
const char* InteractionHistory::getDate() const {
    return this->date;
}

const char* InteractionHistory::getType() const {
    return this->type;
}

const char* InteractionHistory::getContent() const {
    return this->content;
}

// Setters
void InteractionHistory::setDate(const char* date) {
    if (!date) throw InvalidDataException("Invalid pointer to date.");
    size_t len = strlen(date);
    if (len < 4 || len > INTERACTION_MAX_DATE_LEN) {
        throw DataConsistencyException("Date must be between 4 and 32 characters.");
    }
    strncpy(this->date, date, INTERACTION_MAX_DATE_LEN);
    this->date[INTERACTION_MAX_DATE_LEN - 1] = '\0';
}

void InteractionHistory::setType(const char* type) {
    if (!type) throw InvalidDataException("Invalid pointer to type.");
    size_t len = strlen(type);
    if (len < 3 || len > INTERACTION_MAX_TYPE_LEN) {
        throw DataConsistencyException("Type must be between 3 and 64 characters.");
    }
    strncpy(this->type, type, INTERACTION_MAX_TYPE_LEN);
    this->type[INTERACTION_MAX_TYPE_LEN - 1] = '\0';
}

void InteractionHistory::setContent(const char* content) {
    if (!content) throw InvalidDataException("Invalid pointer to content.");
    size_t len = strlen(content);
    if (len < 1 || len > INTERACTION_MAX_CONTENT_LEN) {
        throw DataConsistencyException("Content must be between 1 and 256 characters.");
    }
    strncpy(this->content, content, INTERACTION_MAX_CONTENT_LEN);
    this->content[INTERACTION_MAX_CONTENT_LEN - 1] = '\0';
}
