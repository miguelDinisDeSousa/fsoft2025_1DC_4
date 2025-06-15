//
// Created by carlo on 04/06/2025.
//

#ifndef FSOFT2025_1DC_4_CONTACTCONTAINER_H
#define FSOFT2025_1DC_4_CONTACTCONTAINER_H


#include <list>
#include "Contact.h"
#include "Utils.h"

class ContactContainer {
private:
    std::list<Contact> contacts;
    unsigned int biggestID = 0;

public:
    void addContact(Contact &contact);

    void addContactForGroup(Contact &contact);

    int removeContact(Contact& contact, FilterType filter);
    void listContacts();
    bool isContactUnique(Contact& contact);

    void getUniqueId(Contact *contact);

    bool isListEmpty();
    std::list<Contact>& getContactList();
    bool existsContactWithID(unsigned int& id);
    Contact& getContactFromID(unsigned int& id);

    Contact &getContactFromName(const char *name);

    void listContactsPaged(int page, int pageSize) const;

    bool existsContactWithID(unsigned int id);
};

#endif //FSOFT2025_1DC_4_CONTACTCONTAINER_H



