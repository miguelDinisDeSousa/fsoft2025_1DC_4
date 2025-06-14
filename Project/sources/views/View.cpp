#include <iostream>
#include "View.h"
#include "Utils.h"

using namespace std;
using namespace Utils;

int View::AppMenu(bool admin, bool clear) {
    if (clear) clearOutput();
    bool first = true;
    int opcao = -1;

    if (admin) {
        do {
            if (!first) clearOutput();
            cout << "== Application Menu (Admin) ==\n"
                 << "1. Admin Menu\n"
                 << "2. Contact Menu\n"
                 << "3. Group Chat Menu\n"
                 << "4. Notification Menu\n"
                 << "5. Logout\n"
                 << "0. Exit\n";
            opcao = getNumber("Option");
            first = false;
        } while (opcao < 0 || opcao > 6);
    } else {
        do {
            if (!first) clearOutput();
            cout << "== Application Menu ==\n"
                 << "1. Login as Admin\n"
                 << "0. Exit\n";
            opcao = getNumber("Option");
            first = false;
        } while (opcao != 0 && opcao != 1);
    }

    return opcao;
}

int View::AdminMenu(bool admin, bool clear) {
    if (clear) clearOutput();
    bool first = true;
    int opcao = -1;

    do {
        if (!first) clearOutput();

        cout << "== Admin Menu ==\n";
        if (admin) {
            cout << "1. Register Admin\n"
                 << "2. Delete Admin\n"
                 << "3. Select Admin\n"
                 << "0. Back\n";
        } else {
            cout << "1. Register Admin\n"
                 << "3. Select Admin\n"
                 << "0. Back\n";
        }

        opcao = getNumber("Option");
        first = false;
    } while (opcao < 0 || opcao > 3);

    return opcao;
}

int View::ContactMenu(bool clear) {
    if (clear) clearOutput();
    bool first = true;
    int opcao = -1;

    do {
        if (!first) clearOutput();

        cout << "== Contact Menu ==\n"
             << "1. Add Contact\n"
             << "2. Remove Contact\n"
             << "3. List Contacts\n"
             << "0. Back\n";

        opcao = getNumber("Option");
        first = false;
    } while (opcao < 0 || opcao > 3);

    return opcao;
}

/*
int View::MessageMenu(bool clear) {
    if (clear) clearOutput();
    bool first = true;
    int opcao = -1;

    do {
        if (!first) clearOutput();

        cout << "== Message Menu ==\n"
             << "1. Add Message\n"
             << "2. Remove Message\n"
             << "3. List Messages\n"
             << "0. Back\n";

        opcao = getNumber("Option");
        first = false;
    } while (opcao < 0 || opcao > 3);

    return opcao;
}
*/

int View::GroupChatMenu(bool clear) {
    if (clear) clearOutput();
    bool first = true;
    int opcao = -1;

    do {
        if (!first) clearOutput();

        cout << "== Group Chat Menu ==\n"
             << "1. Create Group\n"
             << "2. Remove Group\n"
             << "3. List Groups\n"
             << "0. Back\n";

        opcao = getNumber("Option");
        first = false;
    } while (opcao < 0 || opcao > 3);

    return opcao;
}

int View::NotificationMenu(bool clear) {
    if (clear) clearOutput();
    bool first = true;
    int opcao = -1;

    do {
        if (!first) clearOutput();

        cout << "== Notification Menu ==\n"
             << "1. Add Notification\n"
             << "2. Remove Notification\n"
             << "3. List Notifications\n"
             << "0. Back\n";

        opcao = getNumber("Option");
        first = false;
    } while (opcao < 0 || opcao > 3);

    return opcao;
}

