//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_NOTIFICATION_H
#define FSOFT2025_1DC_4_NOTIFICATION_H


#include <iostream>
#include <cstring>
#include "GroupChat.h"

#define NOTIFICATION_MAX_MSG_LEN 256
#define NOTIFICATION_MAX_DATE_LEN 32

class Notification {
private:
    unsigned int id = 0;
    char message[NOTIFICATION_MAX_MSG_LEN] = {'\0'};
    char date[NOTIFICATION_MAX_DATE_LEN] = {'\0'};
    bool read = false;
    Group group;

public:
    Notification() = default;
    Notification(unsigned int&, const char*, const char*, bool);

    // Getters
    unsigned int getId() const;
    const char* getMessage() const;
    const char* getDate() const;
    bool isRead() const;
    Group getGroup() const;

    // Setters
    void setId(unsigned int&);
    void setMessage(const char*);
    void setDate(const char*);
    void setRead(bool);
    void setGroup(const Group&);
};


#endif //FSOFT2025_1DC_4_NOTIFICATION_H
