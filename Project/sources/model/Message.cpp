//
// Created by carlo on 31/05/2025.
//
#include "Message.h"
#include "InvalidDataException.h"
#include "DataConsistencyException.h"

Message::Message(unsigned int& id, const char* content, Contact& sender) : sender(sender) {
    setId(id);
    setContent(content);
}

// Getters
unsigned int Message::getId() const {
    return this->id;
}

const char* Message::getContent() const {
    return this->content;
}

struct tm *Message::getDate() const {
    return localtime(&date);
}

Contact& Message::getSender() const {
    return this->sender;
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


void Message::setSender(Contact& sender) {
    this->sender = sender;
}
