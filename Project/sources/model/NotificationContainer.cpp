//
// Created by carlo on 09/06/2025.
//
#include "NotificationContainer.h"
#include "Notification.h"
#include <iostream>
#include <cstring>
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"

void NotificationContainer::addNotification(Notification& notification) {
    if (strlen(notification.getMessage()) < 5 || strlen(notification.getDate()) < 4) {
        throw InvalidDataException("Can't create notification because fields do not follow the requirements");
    }

    if (notification.getId() == 0) {
        notification.setId(++biggestID);
    }

    if (!this->isNotificationUnique(notification)) {
        throw DuplicatedDataException("A notification already exists with the data provided");
    }

    notifications.push_back(notification);
}

int NotificationContainer::removeNotification(Notification& notification, FilterType filter) {
    if (notifications.empty()) {
        return 0;
    }

    if (filter != FILTER_ID && filter != FILTER_NAME) {
        return 0;
    }

    int removed = 0;

    for (auto it = notifications.begin(); it != notifications.end(); ) {
        switch (filter) {
            case FILTER_ID:
                if (it->getId() == notification.getId()) {
                    removed++;
                    it = notifications.erase(it);
                } else {
                    it++;
                }
                break;
            case FILTER_NAME:
                if (strcmp(it->getMessage(), notification.getMessage()) == 0) {
                    removed++;
                    it = notifications.erase(it);
                } else {
                    it++;
                }
                break;
        }
    }

    return removed;
}

void NotificationContainer::listNotifications() {
    if (notifications.empty()) {
        return;
    }

    for (auto it = notifications.begin(); it != notifications.end(); it++) {
        std::cout << "Notification ID: " << it->getId() << std::endl;
        std::cout << "Message: " << it->getMessage() << std::endl;
        std::cout << "Date: " << it->getDate() << std::endl;
        std::cout << "Group: " << it->getGroup().getName() << std::endl;
        std::cout << "Read: " << (it->isRead() ? "Yes" : "No") << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
}

bool NotificationContainer::isNotificationUnique(Notification& notification) {
    if (notifications.empty()) {
        return true;
    }

    for (auto& it : notifications) {
        if (it.getId() == notification.getId() || strcmp(it.getMessage(), notification.getMessage()) == 0) {
            return false;
        }
    }

    return true;
}

bool NotificationContainer::isListEmpty() const {
    return notifications.empty();
}

const std::list<Notification>& NotificationContainer::getNotificationList() const {
    return notifications;
}

bool NotificationContainer::existsNotificationWithID(unsigned int& id) {
    if (notifications.empty() || id == 0) {
        return false;
    }

    for (auto& it : notifications) {
        if (it.getId() == id) {
            std::cout << "\nNotification found with ID: " << id << std::endl;
            return true;
        }
    }

    return false;
}

Notification& NotificationContainer::getNotificationByID(unsigned int& id) {
    for (auto& it : notifications) {
        if (it.getId() == id) {
            return it;
        }
    }

    throw InvalidDataException("Could not get notification object from the given ID");
}

std::list<Notification> NotificationContainer::getNotificationsByGroupName(const char* groupName) {
    std::list<Notification> result;

    for (auto& it : notifications) {
        if (strcmp(it.getGroup().getName(), groupName) == 0) {
            result.push_back(it);
        }
    }

    return result;
}
