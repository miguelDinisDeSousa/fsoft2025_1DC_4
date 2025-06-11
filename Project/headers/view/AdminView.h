#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "Administrator.h"
#include <string>

class AdminView {
private:
    Administrator& admin;
public:
    explicit AdminView(Administrator& admin);
    void adminMenu() const;
    std::string getInput() const;
};

#endif // ADMIN_VIEW_H