#ifndef NOTIFICATIONSVIEW_H
#define NOTIFICATIONSVIEW_H

#include "NotificationContainer.h"
#include "Notification.h"
#include "Utils.h"

class NotificationsView {
public:
    void printNotifications(const NotificationContainer&) const;
    void printUnreadNotifications(const NotificationContainer&) const;
    Notification getNotification() const;
};

#endif // NOTIFICATIONSVIEW_H

