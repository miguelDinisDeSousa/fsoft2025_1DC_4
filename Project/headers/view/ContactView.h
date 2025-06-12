#ifndef CONTACT_VIEW_H
#define CONTACT_VIEW_H

#include "Contact.h"
#include "InteractionHistory.h"
#include <string>

class ContactView {
private:
    const Contact& contact;
    const InteractionHistory& interactions;
public:
    ContactView(const Contact& contact, const InteractionHistory& interactions);
    void interactionsMenu() const;
    std::string getInput() const;
};

#endif // CONTACT_VIEW_H
