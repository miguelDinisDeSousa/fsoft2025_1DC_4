#include "GroupChat.h"

#include <algorithm>

#include "InvalidDataException.h"
#include "DataConsistencyException.h"
#include <cstring> // Para strlen, strncpy

#include "ContactContainer.h"

// Construtor
Group::Group(const char* name, unsigned int& nr_participants, ContactContainer *members, ContactContainer* admins):
    members(members),
    admins(admins) {
    setName(name);
    setNrParticipants(nr_participants);
    messages = new MessageContainer();
}

// Getters
const char* Group::getName() const {
    return this->name;
}

unsigned int Group::getNrParticipants() const {
    return static_cast<unsigned int>(this->members->getContactList().size());
}

ContactContainer* Group::getMembers() {
    return this->members;
}

ContactContainer* Group::getAdmins()  {
    return this->admins;
}

 MessageContainer* Group::getMessages()  {
    return this->messages;
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

void Group::setMessages(MessageContainer* messages) {
    this->messages = messages;
}

void Group::setMembers(ContactContainer* members) {
    this->members = members;
}


void Group::setAdmins(ContactContainer* admins) {
    this->admins = admins;
}


// Membros
void Group::addMember(const Contact& contact) {
    ContactContainer& membersRef = *members;
    for (const auto& member : membersRef.getContactList()) {
        if (member.getId() == contact.getId()) {
            throw DataConsistencyException("Contact is already in the group.");
        }
    }
    members->getContactList().push_back(contact);
}

void Group::addAdmin(const Contact& contact) {
    ContactContainer& membersRef = *admins;
    for (const auto& member : membersRef.getContactList()) {
        if (member.getId() == contact.getId()) {
            throw DataConsistencyException("Contact is already admin in the group.");
        }
    }
    members->getContactList().push_back(contact);
}

void Group::removeMember(int contactId) {
    auto& contactList = members->getContactList();
    auto it = std::find_if(contactList.begin(), contactList.end(),
        [contactId](const Contact& c) { return c.getId() == contactId; });

    if (it != contactList.end()) {
        contactList.erase(it);
    } else {
        throw InvalidDataException("That contact is no member of the group");
    }
}


bool Group::isContactAdmin(const int contactId) {

    bool isAdmin = false;

    for (Contact possibleAdmin : this->admins->getContactList()) {
        if (possibleAdmin.getId() == contactId) {
            isAdmin = true;
            break;
        }
    }

    return isAdmin;
}

