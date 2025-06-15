#include "AdminView.h"
#include <iostream>

using namespace std;

void AdminView::displayProfile(const Administrator& admin) const {
    cout << "\n=== Administrator Profile ===" << endl;
    cout << "ID: " << admin.getId() << endl;
    cout << "Name: " << admin.getName() << endl;
    cout << "Email: " << admin.getEmail() << endl;
    cout << "Phone: " << admin.getPhone() << endl;
    cout << "Address: " << admin.getAddress() << endl;
    cout << "=============================\n" << endl;
}

void AdminView::displayContacts(const std::list<Contact>& contacts) const {
    cout << "\n=== Contact List ===" << endl;
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
        return;
    }
    for (const auto& contact : contacts) {
        cout << "ID: " << contact.getId()
             << " | Name: " << contact.getName()
             << " | Phone: " << contact.getPhone()
             << " | Email: " << contact.getEmail()
             << endl;
    }
    cout << "====================\n" << endl;
}

/*
void AdminView::displayGroups(const std::list<Group>& groups) const {
    cout << "\n=== Group List ===" << endl;
    if (groups.empty()) {
        cout << "No groups available." << endl;
        return;
    }
    for (const auto& group : groups) {
        cout << "Group Name: " << group.getName() << " | Members: " << group.getMembers().size() << endl;
    }
    cout << "==================\n" << endl;
}
*/

void AdminView::createAdmin(AdministratorContainer& container) {
    unsigned int id = Utils::getNumber("Enter ID");

    char* name;
    Utils::getString("Enter name", name, 5);

    char* email;
    Utils::getString("Enter email", email, 5);

    char* phone;
    Utils::getString("Enter phone", phone, 5);

    char* address;
    Utils::getString("Enter address", address, 10);

    try {
        Administrator admin(id, name, email, phone, address);
        container.addAdministrator(admin);
        std::cout << "Administrator created successfully!\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    delete[] name;
    delete[] email;
    delete[] phone;
    delete[] address;
}

void AdminView::removeUser(AdministratorContainer& container) {
    unsigned int id = Utils::getNumber("Enter ID of admin to remove");

    int removed = container.removeAdministrator(id);
    if (removed)
        std::cout << "Administrator removed successfully.\n";
    else
        std::cout << "Administrator not found.\n";
}

void AdminView::listUsers(const AdministratorContainer& container) const {
    container.listAdministrators();
}


