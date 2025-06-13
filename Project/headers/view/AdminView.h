#ifndef FSOFT2025_1DC_4_ADMINVIEW_H
#define FSOFT2025_1DC_4_ADMINVIEW_H

#include <list>
#include "Administrator.h"
#include "Contact.h"
#include "GroupChat.h"
#include "AdministratorContainer.h"

class AdminView {
public:
    void displayProfile(const Administrator& admin) const;
    void displayContacts(const std::list<Contact>& contacts) const;
    void displayGroups(const std::list<Group>& groups) const;
    void createAdmin(AdministratorContainer& container);
    void removeUser(AdministratorContainer& container);
    void listUsers(const AdministratorContainer& container) const;
};

#endif // FSOFT2025_1DC_4_ADMINVIEW_H
