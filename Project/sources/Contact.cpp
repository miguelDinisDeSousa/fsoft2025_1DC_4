//
// Created by carlo on 31/05/2025.
//

#include "Contact.h"
#include "InvalidDataException.h"
#include "DataConsistencyException.h"

Contact::Contact(unsigned int& id, const char* name, const char* phone, const char* email) {
    setId(id);
    setName(name);
    setPhone(phone);
    setEmail(email);
}

// Getters
unsigned int Contact::getId() const {
    return this->id;
}

const char* Contact::getName() const {
    return this->name;
}

const char* Contact::getPhone() const {
    return this->phone;
}

const char* Contact::getEmail() const {
    return this->email;
}

// Setters
void Contact::setId(unsigned int& id) {
    this->id = id;
}

void Contact::setName(const char* name) {
    if (!name) throw InvalidDataException("Invalid pointer to name.");
    size_t len = strlen(name);
    if (len < 3 || len > CONTACT_MAX_NAME_LEN) {
        throw DataConsistencyException("Name must be between 3 and 64 characters.");
    }
    strncpy(this->name, name, CONTACT_MAX_NAME_LEN);
    this->name[CONTACT_MAX_NAME_LEN - 1] = '\0';
}

void Contact::setPhone(const char* phone) {
    if (!phone) throw InvalidDataException("Invalid pointer to phone.");
    size_t len = strlen(phone);
    if (len < 5 || len > CONTACT_MAX_PHONE_LEN) {
        throw DataConsistencyException("Phone must be between 5 and 16 characters.");
    }
    strncpy(this->phone, phone, CONTACT_MAX_PHONE_LEN);
    this->phone[CONTACT_MAX_PHONE_LEN - 1] = '\0';
}

void Contact::setEmail(const char* email) {
    if (!email) throw InvalidDataException("Invalid pointer to email.");
    size_t len = strlen(email);
    if (len < 5 || len > CONTACT_MAX_EMAIL_LEN) {
        throw DataConsistencyException("Email must be between 5 and 64 characters.");
    }
    strncpy(this->email, email, CONTACT_MAX_EMAIL_LEN);
    this->email[CONTACT_MAX_EMAIL_LEN - 1] = '\0';
}
