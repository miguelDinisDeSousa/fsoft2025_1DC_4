#ifndef CONTACT_VIEW_H
#define CONTACT_VIEW_H

#include "Contact.h"
#include "InteractionHistoryContainer.h"
#include <string>

class ContactView {
private:
    const Contact& contact;
    const InteractionHistoryContainer& interactions;
public:
    ContactView(const Contact& contact, const InteractionHistoryContainer& interactions);
    void interactionsMenu() const;
    std::string getInput() const;
};

#endif // CONTACT_VIEW_H