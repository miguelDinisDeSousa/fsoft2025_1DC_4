#ifndef ADMINISTRATOR_CONTAINER_H
#define ADMINISTRATOR_CONTAINER_H

#include <list>
#include "Administrator.h"
#include "Utils.h"

class AdministratorContainer {
private:
    std::list<Administrator> admins;

public:
    void addAdministrator(const Administrator&);
    int removeAdministrator(unsigned int id);  // <- usa id, não o objeto inteiro
    bool existsAdminWithID(unsigned int) const;
    Administrator& getAdministratorByID(unsigned int);
    std::list<Administrator>& getAdministratorList();
    bool isListEmpty() const;
    void listAdministrators() const;
};

#endif // ADMINISTRATOR_CONTAINER_H
