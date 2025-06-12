//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_GROUPCHAT_H
#define FSOFT2025_1DC_4_GROUPCHAT_H

#include <iostream>
#include <cstring>
#include "MessageContainer.h"

#define GROUP_MAX_NAME_LEN 64

class Group {
private:
    char name[GROUP_MAX_NAME_LEN] = {'\0'};
    unsigned int nr_participants = 0;
    MessageContainer messages;

public:
    Group() = default;
    Group(const char*, unsigned int&);

    // Getters
    const char* getName() const;
    unsigned int getNrParticipants() const;
    MessageContainer getMessages();

    // Setters
    void setName(const char*);
    void setNrParticipants(unsigned int&);
    void setMessages(MessageContainer messages);
};


#endif //FSOFT2025_1DC_4_GROUPCHAT_H
