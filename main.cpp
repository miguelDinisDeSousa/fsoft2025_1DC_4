#include <iostream>

#include "App.h"
#include "Controller.h"
#include "Utils.h"

OperatingSystem operatingSystem = UNKNOWN_OS;
bool isAdmin = false;
const char* adminPassword = "admin123"; // Palavra-passe hardcoded

void addBaseData(App& app) {
    // === Obter todos os containers globais ===
    AdministratorContainer& adminContainer = app.getAdminContainer();
    ContactContainer& contactContainer = app.getContactContainer();
    GroupChatContainer& groupChatContainer = app.getGroupChatContainer();
    MessageContainer& messageContainer = app.getMessageContainer();
    NotificationContainer& notificationContainer = app.getNotificationContainer();

    // === Criar administradores ===
    unsigned int id1 = 1, id2 = 2, id3 = 3;

    Administrator admin1(id1, "Carlos Mendes", "carlos@example.com", "912345678", "Rua Alfa 1");
    Administrator admin2(id2, "Inês Duarte", "ines@example.com", "913456789", "Rua Beta 2");
    Administrator admin3(id3, "Rui Oliveira", "rui@example.com", "914567890", "Rua Gama 3");

    adminContainer.addAdministrator(admin1);
    adminContainer.addAdministrator(admin2);
    adminContainer.addAdministrator(admin3);

    // === Criar contactos e adicionar ao admin1 e ao container global ===
    unsigned int cid1 = 101, cid2 = 102;
    Contact c1(cid1, "Joana Costa", "910000001", "joana@example.com");
    Contact c2(cid2, "Marco Silva", "910000002", "marco@example.com");

    admin1.addContact(c1);
    admin1.addContact(c2);

    contactContainer.addContact(c1);
    contactContainer.addContact(c2);
    contactContainer.addContact(admin1);
    contactContainer.addContact(admin2);
    contactContainer.addContact(admin3);


    // === Criar grupo com membros e adicionar ===



     unsigned int groupParticipants = 5;
     std::string baseName = "Team ";

    for (unsigned int  i = 1; i <= 100; i++) {


        // Create group name with index
        std::string groupName = baseName + std::to_string(i);

        // Create and populate the group
        Group group((groupName.c_str()), groupParticipants, &contactContainer, &contactContainer);
        unsigned int messageId1 = id1 + 3*i;
        Message newMessage1 = Message(messageId1, "Olá o meu nome é Ines Duarte", &admin2);
        group.getMessages()->addMessage(newMessage1);

        unsigned int messageId2 = id2 + 3*i;
        Message newMessage2 = Message(messageId2, "Olá o meu nome é Joana Costa",&c1);
        group.getMessages()->addMessage(newMessage2);

        unsigned int messageId3 = id3 + 3*i;
        Message newMessage3 = Message(messageId3, "Olá o meu nome é Marco Silva", &c2);
        group.getMessages()->addMessage(newMessage3);

        // Add to admin and container
        admin1.addGroup(group);
        groupChatContainer.addGroup(group);

    }


    Group group("Equipa Técnica", groupParticipants, &contactContainer, &contactContainer);

    admin1.addGroup(group);
    groupChatContainer.addGroup(group);

    // === Criar notificação associada ao grupo ===
    unsigned int notifId = 1;
    Notification notif(notifId, "Reunião às 10h", "2025-06-12", false);
    notif.setGroup(group);

    admin1.addNotification(notif);
    notificationContainer.addNotification(notif);

}


int main() {
#ifdef _WIN32
    operatingSystem = WINDOWS_OS;
#elif __linux__ || __APPLE__
    operatingSystem = UNIX_OS;
#else
    operatingSystem = UNKNOWN_OS;
#endif

    App app;
    addBaseData(app);

    std::cout << "== Application Menu ==\n";
    std::cout << "1. Login as Admin\n";
    std::cout << "0. Exit\n";

    int option = -1;
    std::cin >> option;
    std::cin.ignore(); // limpar buffer

    if (option == 1) {
        char* passwordInput = nullptr;
        try {
            Utils::getString("Enter admin password", passwordInput, 4);
            if (strcmp(passwordInput, adminPassword) != 0) {
                throw InvalidDataException("Incorrect admin password.");
            }
            delete[] passwordInput;
            std::cout << "\nLogin successful!\n\n";

            Controller controller(app);
            controller.run();
        } catch (InvalidDataException& e) {
            delete[] passwordInput;
            std::cout << "\nError: " << e.what() << "\n";
            return 1;
        }
    }

    return 0;
}



