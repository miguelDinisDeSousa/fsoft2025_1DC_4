#include "ContactsView.h"
#include <iostream>
#include <algorithm>

ContactsView::ContactsView(const ContactContainer& contacts) : contacts(contacts) {}

void ContactsView::contactMenu() const {
    printContacts();
}

void ContactsView::printContacts() const {
    std::cout << "### Contacts Menu ###\n\n";
    
    auto contactList = contacts.getContacts();
    int start = currentPage * CONTACTS_PER_PAGE;
    int end = std::min(start + CONTACTS_PER_PAGE, static_cast<int>(contactList.size()));
    
    for (int i = start; i < end; i++) {
        std::cout << (i - start) << " - " << contactList[i].getName() << "\n";
    }
    
    std::cout << "\nPick one option:\n";
    std::cout << "m - Go back to main menu\n";
    std::cout << "f - Search Contact\n";
    std::cout << "a - Add contact\n";
    std::cout << "0-9 - Select contact\n";
    std::cout << "Enter - Go to next 10 contacts\n";
    std::cout << "Tab - Go to previous 10 contacts\n";
    std::cout << "5 - Go to start of the list\n";
    std::cout << "6 - Go to end of the list\n";
}

std::string ContactsView::handleInput(const std::string& input) {
    if (input == "\n") nextPage();
    else if (input == "\t") prevPage();
    else if (input == "5") firstPage();
    else if (input == "6") lastPage();
    return input;
}

Chat ContactsView::findContact(const std::string& query) const {
    // Implementation depends on your Chat search functionality
    throw NotFoundEntityException("Contact not found: " + query);
}

// Navigation methods
void ContactsView::nextPage() {
    int totalPages = (contacts.getContacts().size() + CONTACTS_PER_PAGE - 1) / CONTACTS_PER_PAGE;
    if (currentPage < totalPages - 1) currentPage++;
}

void ContactsView::prevPage() {
    if (currentPage > 0) currentPage--;
}

void ContactsView::firstPage() {
    currentPage = 0;
}

void ContactsView::lastPage() {
    int totalPages = (contacts.getContacts().size() + CONTACTS_PER_PAGE - 1) / CONTACTS_PER_PAGE;
    currentPage = totalPages - 1;
}
