//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_ADMINISTRATOR_H
#define FSOFT2025_1DC_4_ADMINISTRATOR_H

#include <list>
#include "GroupChat.h"
#include "Notification.h"
#include "Contact.h"  // Already included
#include "Message.h"

#define ADMIN_MAX_NAME_LEN 64
#define ADMIN_MAX_EMAIL_LEN 64
#define ADMIN_MAX_PHONE_LEN 16
#define ADMIN_MAX_ADDRESS_LEN 128

class Administrator : public Contact {
private:
    char address[ADMIN_MAX_ADDRESS_LEN] = {'\0'};
    std::list<Group> groups;
    std::list<Notification> notifications;
    std::list<Contact> contacts;
    std::list<Message> messages;

public:
    Administrator() = default;
    Administrator(unsigned int& id, const char* name, const char* email,
                 const char* phone, const char* address);

    // Getter/Setter for address only (inherits others from Contact)
    const char* getAddress() const;
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