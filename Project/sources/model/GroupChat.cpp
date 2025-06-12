#include "GroupChat.h"
#include "InvalidDataException.h"
#include "DataConsistencyException.h"
#include <cstring> // Para strlen, strncpy

// Construtor
Group::Group(const char* name, unsigned int& nr_participants) {
    setName(name);
    setNrParticipants(nr_participants);
}

// Getters
const char* Group::getName() const {
    return this->name;
}

unsigned int Group::getNrParticipants() const {
    return static_cast<unsigned int>(this->members.size());
}

std::list<Contact>& Group::getMembers() {
    return this->members;
}

const std::list<Contact>& Group::getMembers() const {
    return this->members;
}

// Setters
void Group::setName(const char* name) {
    if (!name) {
        throw InvalidDataException("Invalid pointer to name.");
    }

    size_t len = strlen(name);
    if (len < 3 || len > GROUP_MAX_NAME_LEN) {
        throw DataConsistencyException("Group name must be between 3 and 64 characters.");
    }

    strncpy(this->name, name, GROUP_MAX_NAME_LEN);
    this->name[GROUP_MAX_NAME_LEN - 1] = '\0';
}

void Group::setNrParticipants(unsigned int& count) {
    if (count < 2) {
        throw DataConsistencyException("A group must have at least 2 participants.");
    }

    // Não altera diretamente — apenas valida.
}

// Membros
void Group::addMember(const Contact& contact) {
    for (const auto& member : members) {
        if (member.getId() == contact.getId()) {
            throw DataConsistencyException("Contact is already in the group.");
        }
    }
    members.push_back(contact);
}

void Group::removeMember(const char* contactName) {
    if (!contactName) {
        throw InvalidDataException("Invalid pointer to contact name.");
    }

    for (auto it = members.begin(); it != members.end(); ++it) {
        if (strcmp(it->getName(), contactName) == 0) {
            members.erase(it);
            return;
        }
    }

    throw InvalidDataException("Contact with the given name not found in the group.");
}


