#ifndef FSOFT2025_1DC_4_GROUPCHAT_H
#define FSOFT2025_1DC_4_GROUPCHAT_H

#include <iostream>
#include <cstring>
#include <list>
#include "Contact.h"

#define GROUP_MAX_NAME_LEN 64

class Group {
private:
    char name[GROUP_MAX_NAME_LEN] = {'\0'};
    std::list<Contact> members;

public:
    Group() = default;
    Group(const char*, unsigned int&);

    // Getters
    const char* getName() const;
    unsigned int getNrParticipants() const;
    std::list<Contact>& getMembers();
    const std::list<Contact>& getMembers() const;

    // Setters
    void setName(const char*);
    void setNrParticipants(unsigned int&); // Se quiser manter manualmente, opcional

    // Member management
    void addMember(const Contact&);
    void removeMember(const char* contactName);
};

#endif //FSOFT2025_1DC_4_GROUPCHAT_H

