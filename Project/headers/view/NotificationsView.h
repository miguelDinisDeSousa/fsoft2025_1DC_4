#ifndef NOTIFICATIONS_VIEW_H
#define NOTIFICATIONS_VIEW_H

#include "NotificationContainer.h"
#include <string>

class NotificationsView {
private:
    const NotificationContainer& notifications;
    int currentPage = 0;
    const int NOTIFICATIONS_PER_PAGE = 10;
public:
    explicit NotificationsView(const NotificationContainer& notifications);
    void chatMenu() const;
    void printNotifications() const;
    std::string handleInput(const std::string& input);
    
    // Navigation
    void nextPage();
    void prevPage();
    void firstPage();
    void lastPage();
};

#endif // NOTIFICATIONS_VIEW_H