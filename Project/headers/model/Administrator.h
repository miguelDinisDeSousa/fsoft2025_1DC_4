//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_ADMINISTRATOR_H
#define FSOFT2025_1DC_4_ADMINISTRATOR_H


#include <iostream>
#include <cstring>
#include <list>
#include "GroupChat.h"
#include "Notification.h"
#include "Contact.h"
#include "Message.h"

#define ADMIN_MAX_NAME_LEN 64
#define ADMIN_MAX_EMAIL_LEN 64
#define ADMIN_MAX_PHONE_LEN 16
#define ADMIN_MAX_ADDRESS_LEN 128

class Administrator {
private:
    unsigned int admin_id = 0;
    char name[ADMIN_MAX_NAME_LEN] = {'\0'};
    char email[ADMIN_MAX_EMAIL_LEN] = {'\0'};
    char phone[ADMIN_MAX_PHONE_LEN] = {'\0'};
    char address[ADMIN_MAX_ADDRESS_LEN] = {'\0'};

    std::list<Group> groups;
    std::list<Notification> notifications;
    std::list<Contact> contacts;
    std::list<Message> messages; // mensagens enviadas

public:
    Administrator() = default;
    Administrator(unsigned int&, const char*, const char*, const char*, const char*);

    // Getters
    unsigned int getId() const;
    const char* getName() const;
    const char* getEmail() const;
    const char* getPhone() const;
    const char* getAddress() const;

    // Setters
    void setId(unsigned int&);
    void setName(const char*);
    void setEmail(const char*);
    void setPhone(const char*);
    void setAddress(const char*);

    // List accessors
    std::list<Group>& getGroups();
    std::list<Notification>& getNotifications();
    std::list<Contact>& getContacts();
    std::list<Message>& getMessages();

    // Add methods
    void addGroup(const Group&);
    void addNotification(const Notification&);
    void addContact(const Contact&);
    void addMessage(const Message&);
};


#endif //FSOFT2025_1DC_4_ADMINISTRATOR_H
