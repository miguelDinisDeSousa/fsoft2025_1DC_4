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

// Getters
unsigned int Administrator::getId() const {
    return this->admin_id;
}

const char* Administrator::getName() const {
    return this->name;
}

const char* Administrator::getEmail() const {
    return this->email;
}

const char* Administrator::getPhone() const {
    return this->phone;
}

const char* Administrator::getAddress() const {
    return this->address;
}

// Setters
void Administrator::setId(unsigned int& id) {
    this->admin_id = id;
}

void Administrator::setName(const char* name) {
    if (!name) throw InvalidDataException("Invalid pointer to name.");
    size_t len = strlen(name);
    if (len < 5 || len > ADMIN_MAX_NAME_LEN) {
        throw DataConsistencyException("Name must be between 5 and 64 characters.");
    }
    strncpy(this->name, name, ADMIN_MAX_NAME_LEN);
    this->name[ADMIN_MAX_NAME_LEN - 1] = '\0';
}

void Administrator::setEmail(const char* email) {
    if (!email) throw InvalidDataException("Invalid pointer to email.");
    size_t len = strlen(email);
    if (len < 5 || len > ADMIN_MAX_EMAIL_LEN) {
        throw DataConsistencyException("Email must be between 5 and 64 characters.");
    }
    strncpy(this->email, email, ADMIN_MAX_EMAIL_LEN);
    this->email[ADMIN_MAX_EMAIL_LEN - 1] = '\0';
}

void Administrator::setPhone(const char* phone) {
    if (!phone) throw InvalidDataException("Invalid pointer to phone.");
    size_t len = strlen(phone);
    if (len < 5 || len > ADMIN_MAX_PHONE_LEN) {
        throw DataConsistencyException("Phone number must be between 5 and 16 characters.");
    }
    strncpy(this->phone, phone, ADMIN_MAX_PHONE_LEN);
    this->phone[ADMIN_MAX_PHONE_LEN - 1] = '\0';
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
