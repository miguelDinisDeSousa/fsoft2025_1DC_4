#ifndef CONTACTS_VIEW_H
#define CONTACTS_VIEW_H

#include "ContactContainer.h"
#include <string>

class ContactsView {
private:
    const ContactContainer& contacts;
    int currentPage = 0;
    const int CONTACTS_PER_PAGE = 10;
public:
    explicit ContactsView(const ContactContainer& contacts);
    void contactMenu() const;
    void printContacts() const;
    std::string handleInput(const std::string& input);
    Chat findContact(const std::string& query) const;
    
    // Navigation
    void nextPage();
    void prevPage();
    void firstPage();
    void lastPage();
};

#endif // CONTACTS_VIEW_H