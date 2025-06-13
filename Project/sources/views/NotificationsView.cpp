#include "NotificationsView.h"
#include <iostream>

void NotificationsView::printNotifications(const NotificationContainer& container) const {
    if (container.isListEmpty()) {
        std::cout << "No notifications to show.\n";
        return;
    }

    for (const auto& notification : container.getNotificationList()) {
        std::cout << "ID: " << notification.getId() << "\n";
        std::cout << "Message: " << notification.getMessage() << "\n";
        std::cout << "Date: " << notification.getDate() << "\n";
        std::cout << "Status: " << (notification.isRead() ? "Read" : "Unread") << "\n\n";
    }
}

void NotificationsView::printUnreadNotifications(const NotificationContainer& container) const {
    for (const auto& notification : container.getNotificationList()) {
        if (!notification.isRead()) {
            std::cout << "ID: " << notification.getId() << "\n";
            std::cout << "Message: " << notification.getMessage() << "\n";
            std::cout << "Date: " << notification.getDate() << "\n";
            std::cout << "Status: Unread\n\n";
        }
    }
}

Notification NotificationsView::getNotification() const {
    unsigned int id = Utils::getNumber("Enter notification ID");

    char* message;
    Utils::getString("Enter message", message, 1);

    char* date;
    Utils::getString("Enter date", date, 4);

    bool read;
    std::cout << "Is the notification read? (1 for yes, 0 for no): ";
    std::cin >> read;
    std::cin.ignore();  // limpar o buffer

    Notification n(id, message, date, read);

    delete[] message;
    delete[] date;

    return n;
}

