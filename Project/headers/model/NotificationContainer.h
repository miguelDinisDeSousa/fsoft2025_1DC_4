//
// Created by carlo on 09/06/2025.
//

#ifndef FSOFT2025_1DC_4_NOTIFICATIONCONTAINER_H
#define FSOFT2025_1DC_4_NOTIFICATIONCONTAINER_H


#include <list>
#include "Notification.h"
#include "Utils.h"

class NotificationContainer {
private:
    std::list<Notification> notifications;
    unsigned int biggestID = 0;

public:
    void addNotification(Notification&);
    int removeNotification(Notification&, FilterType filter);
    void listNotifications();
    bool isNotificationUnique(Notification&);
    bool isListEmpty();
    std::list<Notification>& getNotificationList();
    bool existsNotificationWithID(unsigned int&);
    Notification& getNotificationByID(unsigned int&);
    std::list<Notification> getNotificationsByGroupName(const char* groupName);
};


#endif //FSOFT2025_1DC_4_NOTIFICATIONCONTAINER_H
