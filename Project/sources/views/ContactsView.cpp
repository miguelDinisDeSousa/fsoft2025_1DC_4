#include "ContactsView.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace Utils;

Contact ContactsView::getContact() {
    char* name = nullptr;
    char* phone = nullptr;
    char* email = nullptr;

    getString("Contact name (min 3 chars)", name, 3);
    getString("Phone number (min 5 chars)", phone, 5);
    getString("Email (min 5 chars)", email, 5);

    static unsigned int idCounter = 1;
    unsigned int id = idCounter++;

    Contact contact(id, name, phone, email);

    delete[] name;
    delete[] phone;
    delete[] email;

    return contact;
}

void ContactsView::printContacts(const list<Contact>& contacts) const {
    if (contacts.empty()) {
        cout << "\nNo contacts available.\n" << endl;
        return;
    }

    cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(20) << "Phone" << setw(30) << "Email" << endl;
    cout << string(76, '-') << endl;

    for (const auto& contact : contacts) {
        cout << left << setw(6) << contact.getId()
             << setw(20) << contact.getName()
             << setw(20) << contact.getPhone()
             << setw(30) << contact.getEmail() << endl;
    }

    cout << endl;
}

