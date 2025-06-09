//
// Created by carlo on 31/05/2025.
//
#include "Message.h"
#include "InvalidDataException.h"
#include "DataConsistencyException.h"

Message::Message(unsigned int& id, const char* content, const char* date, unsigned int& sender, unsigned int& receiver) {
    setId(id);
    setContent(content);
    setDate(date);
    setSender(sender);
    setReceiver(receiver);
}

// Getters
unsigned int Message::getId() const {
    return this->id;
}

const char* Message::getContent() const {
    return this->content;
}

const char* Message::getDate() const {
    return this->date;
}

unsigned int Message::getSender() const {
    return this->sender;
}

unsigned int Message::getReceiver() const {
    return this->receiver;
}

// Setters
void Message::setId(unsigned int& id) {
    this->id = id;
}

void Message::setContent(const char* content) {
    if (!content) throw InvalidDataException("Invalid pointer to content.");
    size_t len = strlen(content);
    if (len < 1 || len > MESSAGE_MAX_CONTENT_LEN) {
        throw DataConsistencyException("Message content must be between 1 and 256 characters.");
    }
    strncpy(this->content, content, MESSAGE_MAX_CONTENT_LEN);
    this->content[MESSAGE_MAX_CONTENT_LEN - 1] = '\0';
}

void Message::setDate(const char* date) {
    if (!date) throw InvalidDataException("Invalid pointer to date.");
    size_t len = strlen(date);
    if (len < 4 || len > MESSAGE_MAX_DATE_LEN) {
        throw DataConsistencyException("Date must be between 4 and 32 characters.");
    }
    strncpy(this->date, date, MESSAGE_MAX_DATE_LEN);
    this->date[MESSAGE_MAX_DATE_LEN - 1] = '\0';
}

void Message::setSender(unsigned int& sender) {
    this->sender = sender;
}

void Message::setReceiver(unsigned int& receiver) {
    this->receiver = receiver;
}
