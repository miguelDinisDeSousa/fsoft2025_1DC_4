#ifndef CONTACTSVIEW_H
#define CONTACTSVIEW_H

#include <iostream>
#include <list>
#include "Contact.h"
#include "Utils.h"

class ContactsView {
public:
    Contact getContact();
    void printContacts(const std::list<Contact>& contacts) const;
    Contact findContactByName(const std::list<Contact>& contacts, const char* query) const;
};

#endif // CONTACTSVIEW_H
