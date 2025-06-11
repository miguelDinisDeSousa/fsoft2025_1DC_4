#include "ContactView.h"
#include <iostream>

ContactView::ContactView(const Contact& contact, const InteractionHistoryContainer& interactions) 
    : contact(contact), interactions(interactions) {}

void ContactView::interactionsMenu() const {
    std::cout << "### Menu Contact ###\n\n";
    std::cout << "Name: " << contact.getName() << "\n";
    std::cout << "Phone: " << contact.getPhone() << "\n";
    std::cout << "\nPick one option:\n";
    std::cout << "b - Go back to contacts Menu\n";
    std::cout << "m - Go back to main Menu\n";
    std::cout << "e - Edit\n";
    std::cout << "d - Delete\n";
    std::cout << "1 - Interactions History\n";
}

std::string ContactView::getInput() const {
    std::string input;
    std::cout << "Enter your choice: ";
    std::getline(std::cin, input);
    return input;
}