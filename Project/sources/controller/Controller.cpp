#include "Controller.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "Utils.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using namespace Utils;

Controller::Controller(App& app) : app(app) {}

void Controller::setApp(App& newApp) {
    this->app = newApp;
}

void Controller::run() {
    bool isAdmin = false;
    int option = -1;

    while (true) {
        Utils::clearOutput();
        option = view.AppMenu(isAdmin);

        if (!isAdmin) {
            switch (option) {
                case 1: {
                    char* passwordInput = nullptr;
                    try {
                        Utils::clearOutput();
                        Utils::getString("\nEnter admin password", passwordInput, 5);

                        if (strcmp(passwordInput, "admin123") == 0) {
                            isAdmin = true;
                            Utils::clearOutput();
                            std::cout << "\nLogin successful!\n";
                        } else {
                            Utils::clearOutput();
                            std::cout << "\nIncorrect password.\n";
                        }

                        delete[] passwordInput;
                    } catch (...) {
                        delete[] passwordInput;
                        Utils::clearOutput();
                        std::cout << "\nLogin error.\n";
                    }
                    break;
                }
                case 0:
                    return;
            }
        } else {
            switch (option) {
                case 1:
                    Utils::clearOutput();
                    runAdmin();
                    break;
                case 2:
                    Utils::clearOutput();
                    runContacts();
                    break;
                case 3:
                    Utils::clearOutput();
                    runChats();
                    break;
                case 4:
                    Utils::clearOutput();
                    runNotifications();
                    break;
                case 5:
                    isAdmin = false;
                    Utils::clearOutput();
                    std::cout << "\nLogged out.\n";
                    break;
                case 0:
                    return;
                default:
                    Utils::clearOutput();
                    std::cout << "\nInvalid option.\n";
                    break;
            }
        }
    }
}

void Controller::runContacts() {
    ContactContainer& container = app.getContactContainer();
    int option;
    while ((option = view.ContactMenu()) != 0) {
        switch (option) {
            case 1: {
                Contact contact = contactsView.getContact();
                container.addContact(contact);
                break;
            }
            case 2: {
                Contact contact = contactsView.getContact();
                container.removeContact(contact, FILTER_ID);
                break;
            }
            case 3: {
                container.listContacts();
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            default:
                break;
        }
    }
}

void Controller::runAdmin() {
    int option;
    while ((option = view.AdminMenu(false)) != 0) {
        switch (option) {
            case 1:
                adminView.createAdmin(app.getAdminContainer());
                break;
            case 2:
                adminView.removeUser(app.getAdminContainer());
                break;
            case 3:
                adminView.listUsers(app.getAdminContainer());
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            default:
                break;
        }
    }
}

void Controller::runChats() {
    GroupChatContainer& container = app.getGroupChatContainer();
    int currentPage = 0;
    while (true) {
        char option = groupChatView.displayChats(container, currentPage);

        if (option == 'm') {
            return;
        } else if (option == 'a') {
            Group group = groupChatView.getGroup(app.getAdminContainer().getAdministratorByID(1));
            container.addGroup(group);
        } else if (option == '-' && currentPage >= 10) {
            currentPage -= 10;

        } else if (option == '-' || option == 's') {
            currentPage = 0;

        } else if (option == '+') {
            currentPage += 10;

        }  else if (option == 'S' && container.getGroupList().size() > 10) {
            currentPage = container.getGroupList().size() - 1 - 10;

        } else if (option == 'f') {

            char* chatName = nullptr;
            Utils::getString("Write Group name:", chatName, 0);
            if (container.existsGroupWithName(chatName)) {
                Group searchedGroup = container.getGroupByName(chatName);
                Controller::runChat(searchedGroup);
            } else {
                std::cout << "No Group by that name \n";
            }


        } else if ((int)option >= '0' && (int)option <= '9') {
            int optionInt = (int) option - '0';
            std::vector<Group> chats(container.getGroupList().begin(), container.getGroupList().end());
            Group selectedGroup = chats[optionInt + currentPage];
            bool goBackMainMenu = Controller::runChat(selectedGroup);
            if (goBackMainMenu) {
                return;
            }
        }
    }
}


bool Controller::runChat(Group &chat) {
    int currentPage = 0;
    while (true) {
        char option = GroupChatView::displayChat(chat, currentPage);

        if (option == 'b') {
            return false;
        } else if (option == 'm') {
            return true;
        } else if (option == '-' && currentPage >= 10) {
            currentPage -= 10;

        } else if (option == '-' || option == 's') {
            currentPage = 0;

        } else if (option == '+') {
            currentPage += 10;

        }  else if (option == 'S' && chat.getMessages()->getMessages().size() > 10) {
            currentPage = chat.getMessages()->getMessages().size() - 1 - 10;

        }  else if ((int)option >= '0' && (int)option <= '9') {

            int optionInt = (int) option - '0';
            std::vector<Message> messages(chat.getMessages()->getMessages().begin(), chat.getMessages()->getMessages().end());
            chat.getMessages()->removeMessageById(messages[optionInt].getId(), 1);

        } else if (option == 'e') {

        } else if (option == 'N') {
            char* messageText = nullptr;
            Utils::getString("Write your Message:", messageText, 3);
            unsigned int newMessageId = app.getMessageContainer().getMessageList().size() + 1;
            Message *newMessage = new Message(newMessageId, messageText,
                                              &app.getAdminContainer().getAdministratorByID(1));
            chat.getMessages()->addMessage(*newMessage);
            app.getMessageContainer().addMessage(*newMessage);
        }
    }
}

void Controller::runNotifications() {
    NotificationContainer& container = app.getNotificationContainer();
    int option;
    while ((option = view.NotificationMenu()) != 0) {
        switch (option) {
            case 1: {
                Notification notification = notificationsView.getNotification();
                container.addNotification(notification);
                break;
            }
            case 2: {
                Notification notification = notificationsView.getNotification();
                container.removeNotification(notification, FILTER_ID);
                break;
            }
            case 3: {
                container.listNotifications();
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            default:
                break;
        }
    }
}
