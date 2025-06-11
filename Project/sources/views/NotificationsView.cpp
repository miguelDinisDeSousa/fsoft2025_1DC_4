#include "NotificationsView.h"
#include <iostream>
#include <ctime>

NotificationsView::NotificationsView(const NotificationContainer& notifications) 
    : notifications(notifications) {}

void NotificationsView::chatMenu() const {
    printNotifications();
}

void NotificationsView::printNotifications() const {
    std::cout << "#### Notifications (max: 300) ####\n\n";
    
    auto notificationList = notifications.getNotifications();
    int start = currentPage * NOTIFICATIONS_PER_PAGE;
    int end = std::min(start + NOTIFICATIONS_PER_PAGE, static_cast<int>(notificationList.size()));
    
    for (int i = start; i < end; i++) {
        const auto& notification = notificationList[i];
        std::time_t t = notification.getMessage().getDate();
        std::tm* now = std::localtime(&t);
        char timeBuf[20];
        std::strftime(timeBuf, sizeof(timeBuf), "%d/%m - %Hh%M", now);
        
        std::cout << (i - start) << " - " << notification.getMessage().getSender().getName()
                  << " sent a message in " << notification.getChat().getName()
                  << " (" << timeBuf << ")\n";
    }
    
    std::cout << "\nPick one option:\n";
    std::cout << "m - Go back to main menu\n";
    std::cout << "0-9 - Select chat\n";
    std::cout << "Enter - Go to next 10 notifications\n";
    std::cout << "Tab - Go to previous 10 notifications\n";
    std::cout << "5 - Go to start of the list\n";
    std::cout << "6 - Go to end of the list\n";
}

std::string NotificationsView::handleInput(const std::string& input) {
    if (input == "\n") nextPage();
    else if (input == "\t") prevPage();
    else if (input == "5") firstPage();
    else if (input == "6") lastPage();
    return input;
}

// Navigation methods (similar to ContactsView)