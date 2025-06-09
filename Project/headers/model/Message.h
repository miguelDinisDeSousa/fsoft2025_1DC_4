//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_MESSAGE_H
#define FSOFT2025_1DC_4_MESSAGE_H


#include <iostream>
#include <cstring>

#define MESSAGE_MAX_CONTENT_LEN 256
#define MESSAGE_MAX_DATE_LEN 32

class Message {
private:
    unsigned int id = 0;
    char content[MESSAGE_MAX_CONTENT_LEN] = {'\0'};
    char date[MESSAGE_MAX_DATE_LEN] = {'\0'};
    unsigned int sender = 0;
    unsigned int receiver = 0;

public:
    Message() = default;
    Message(unsigned int&, const char*, const char*, unsigned int&, unsigned int&);

    // Getters
    unsigned int getId() const;
    const char* getContent() const;
    const char* getDate() const;
    unsigned int getSender() const;
    unsigned int getReceiver() const;

    // Setters
    void setId(unsigned int&);
    void setContent(const char*);
    void setDate(const char*);
    void setSender(unsigned int&);
    void setReceiver(unsigned int&);
};


#endif //FSOFT2025_1DC_4_MESSAGE_H
