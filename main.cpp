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

    // === Criar grupo com membros e adicionar ===
    unsigned int groupParticipants = 2;
    Group group("Equipa Técnica", groupParticipants);
    group.addMember(c1);
    group.addMember(c2);

    admin1.addGroup(group);
    groupChatContainer.addGroup(group);

    // === Criar notificação associada ao grupo ===
    unsigned int notifId = 1;
    Notification notif(notifId, "Reunião às 10h", "2025-06-12", false);
    notif.setGroup(group);

    admin1.addNotification(notif);
    notificationContainer.addNotification(notif);

    // === Criar mensagem entre admin1 e contacto ===
    unsigned int msgId = 201, senderId = id1, receiverId = cid1;
    Message msg(msgId, "Bom dia, Joana!", "2025-06-12", senderId, receiverId);

    admin1.addMessage(msg);
    messageContainer.addMessage(msg);
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



