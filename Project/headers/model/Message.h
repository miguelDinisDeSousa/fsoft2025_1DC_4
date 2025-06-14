//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_MESSAGE_H
#define FSOFT2025_1DC_4_MESSAGE_H

#include <iostream>
#include "Contact.h"

#define MESSAGE_MAX_CONTENT_LEN 256
#define MESSAGE_MAX_DATE_LEN 32

class Message {
private:
    unsigned int id = 0;
    char content[MESSAGE_MAX_CONTENT_LEN] = {'\0'};
    time_t date = time(nullptr);;
    Contact* sender;

public:
    Message() = default;

    Message(unsigned int &id, const char *content, Contact *sender);

    // Getters
    unsigned int getId() const;
    const char* getContent() const;

    struct tm *getDate() const;
    Contact* getSender() const;

    // Setters
    void setId(unsigned int&);
    void setContent(const char*);
    void setSender(Contact*);

};


#endif //FSOFT2025_1DC_4_MESSAGE_H
