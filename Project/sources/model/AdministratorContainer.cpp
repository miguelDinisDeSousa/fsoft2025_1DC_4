#include "AdministratorContainer.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include <iostream>
#include <cstring>

void AdministratorContainer::addAdministrator(const Administrator& admin) {
    if (existsAdminWithID(admin.getId())) {
        throw DuplicatedDataException("Administrator with the same ID already exists.");
    }
    admins.push_back(admin);
}

int AdministratorContainer::removeAdministrator(unsigned int id) {
    for (auto it = admins.begin(); it != admins.end(); ++it) {
        if (it->getId() == id) {
            admins.erase(it);
            return 1;
        }
    }
    return 0;
}

bool AdministratorContainer::existsAdminWithID(unsigned int id) const {
    for (const auto& admin : admins) {
        if (admin.getId() == id) {
            return true;
        }
    }
    return false;
}

Administrator& AdministratorContainer::getAdministratorByID(unsigned int id) {
    for (auto& admin : admins) {
        if (admin.getId() == id) {
            return admin;
        }
    }
    throw InvalidDataException("Administrator with the specified ID not found.");
}

std::list<Administrator>& AdministratorContainer::getAdministratorList() {
    return admins;
}

bool AdministratorContainer::isListEmpty() const {
    return admins.empty();
}

void AdministratorContainer::listAdministrators() const {
    if (admins.empty()) {
        std::cout << "No administrators registered.\n";
        return;
    }

    for (const auto& admin : admins) {
        std::cout << "ID: " << admin.getId() << " | Name: " << admin.getName()
                  << " | Email: " << admin.getEmail() << " | Phone: " << admin.getPhone()
                  << " | Address: " << admin.getAddress() << "\n";
    }
}

