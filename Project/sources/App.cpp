

#include "ContactContainer.h"
#include "GroupChatContainer.h"
#include "MessageContainer.h"
#include "NotificationContainer.h"
#include "App.h"

ContactContainer& App::getContactContainer() {
    return contactContainer;
}

GroupChatContainer& App::getGroupChatContainer() {
    return groupChatContainer;
}

MessageContainer& App::getMessageContainer() {
    return messageContainer;
}

NotificationContainer& App::getNotificationContainer() {
    return notificationContainer;
}
