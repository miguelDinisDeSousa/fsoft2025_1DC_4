
#ifndef FSOFT2025_1DC_4_APP_H
#define FSOFT2025_1DC_4_APP_H


#include "ContactContainer.h"
#include "GroupChatContainer.h"
#include "MessageContainer.h"
#include "NotificationContainer.h"
#include "AdministratorContainer.h"

class App {
private:
    ContactContainer contactContainer;
    GroupChatContainer groupChatContainer;
    MessageContainer messageContainer;
    NotificationContainer notificationContainer;
    AdministratorContainer adminContainer;
public:
    ContactContainer& getContactContainer();
    GroupChatContainer& getGroupChatContainer();
    MessageContainer& getMessageContainer();
    NotificationContainer& getNotificationContainer();
    AdministratorContainer& getAdminContainer();


};

#endif //FSOFT2025_1DC_4_APP_H
