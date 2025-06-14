//
// Created by carlo on 31/05/2025.
//
#include <iostream>
#include <cstring>
#include "Administrator.h"
#include "InvalidDataException.h"
#include "DataConsistencyException.h"
#include "DuplicatedDataException.h"

Administrator::Administrator(unsigned int& id, const char* name, const char* email, const char* phone, const char* address) {
    setId(id);
    setName(name);
    setEmail(email);
    setPhone(phone);
    setAddress(address);
}

void Administrator::setAddress(const char* address) {
    if (!address) throw InvalidDataException("Invalid pointer to address.");
    size_t len = strlen(address);
    if (len < 10 || len > ADMIN_MAX_ADDRESS_LEN) {
        throw DataConsistencyException("Address must be between 10 and 128 characters.");
    }
    strncpy(this->address, address, ADMIN_MAX_ADDRESS_LEN);
    this->address[ADMIN_MAX_ADDRESS_LEN - 1] = '\0';
}

// List Getters
std::list<Group>& Administrator::getGroups() {
    return this->groups;
}

std::list<Notification>& Administrator::getNotifications() {
    return this->notifications;
}

std::list<Contact>& Administrator::getContacts() {
    return this->contacts;
}

std::list<Message>& Administrator::getMessages() {
    return this->messages;
}

const char* Administrator::getAddress() const {
    return this->address;
}

// Adders
void Administrator::addGroup(const Group& group) {
    this->groups.push_back(group);
}

void Administrator::addNotification(const Notification& notification) {
    this->notifications.push_back(notification);
}

void Administrator::addContact(const Contact& contact) {
    // Verifica se já existe um contacto com o mesmo ID (opcional)
    for (auto& c : contacts) {
        if (c.getId() == contact.getId()) {
            throw DuplicatedDataException("Contact with the same ID already exists.");
        }
    }
    this->contacts.push_back(contact);
}

void Administrator::addMessage(const Message& message) {
    this->messages.push_back(message);
}
