//
// Created by carlo on 04/06/2025.
//
#include "ContactContainer.h"

#include <algorithm>

#include "Contact.h"
#include <iostream>
#include <cstring>
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"

void ContactContainer::addContact(Contact& contact) {
    if (strlen(contact.getName()) < 3 || strlen(contact.getEmail()) < 5) {
        throw InvalidDataException("Can't create contact because fields do not follow the requirements");
    }

    if (contact.getId() == 0) {
        contact.setId(++biggestID);
    }

    if (!this->isContactUnique(contact)) {
        throw DuplicatedDataException("A contact already exists with the data provided");
    }

    contacts.push_back(contact);
}

int ContactContainer::removeContact(Contact& contact, FilterType filter) {
    if (contacts.empty()) {
        return 0;
    }

    if (filter != FILTER_ID && filter != FILTER_NAME) {
        return 0;
    }

    int removed = 0;

    for (auto it = contacts.begin(); it != contacts.end();) {
        switch (filter) {
            case FILTER_ID:
                if (it->getId() == contact.getId()) {
                    removed++;
                    it = contacts.erase(it);
                } else {
                    ++it;
                }
                break;

            case FILTER_NAME:
                if (strcmp(it->getName(), contact.getName()) == 0) {
                    removed++;
                    it = contacts.erase(it);
                } else {
                    ++it;
                }
                break;

            default:
                ++it;
                break;
        }
    }

    return removed;
}

void ContactContainer::listContacts() {
    if (contacts.empty()) {
        return;
    }

    for (auto& contact : contacts) {
        std::cout << "Contact name: " << contact.getName() << std::endl;
    }
}

bool ContactContainer::isContactUnique(Contact& contact) {
    for (auto& existing : contacts) {
        if (existing.getId() == contact.getId() || strcmp(existing.getEmail(), contact.getEmail()) == 0) {
            return false;
        }
    }
    return true;
}

bool ContactContainer::isListEmpty() {
    return contacts.empty();
}

std::list<Contact>& ContactContainer::getContactList() {
    return contacts;
}

bool ContactContainer::existsContactWithID(unsigned int& id) {
    if (contacts.empty() || id == 0) {
        return false;
    }

    for (auto& contact : contacts) {
        if (contact.getId() == id) {
            std::cout << "\nContact found with ID: " << id << std::endl;
            return true;
        }
    }

    return false;
}

Contact& ContactContainer::getContactFromID(unsigned int& id) {
    for (auto& contact : contacts) {
        if (contact.getId() == id) {
            return contact;
        }
    }

    throw InvalidDataException("Could not get contact object from the given ID");
}

Contact& ContactContainer::getContactFromName(const char* name) {
    for (auto& contact : contacts) {
        std::cout << contact.getName() ;
        if (std::strcmp(contact.getName(), name) == 0) {
            return contact;

        }
    }

    throw InvalidDataException("\n Could not get contact object from the given Name \n");
}

