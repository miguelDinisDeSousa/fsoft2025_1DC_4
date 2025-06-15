//
// Created by carlo on 11/06/2025.
//

#ifndef FSOFT2025_1DC_4_CONTROLLER_H
#define FSOFT2025_1DC_4_CONTROLLER_H

#include "App.h"
#include "ContactsView.h"
#include "GroupChatView.h"
#include "MessageView.h"
#include "NotificationsView.h"
#include "View.h"
#include "AdminView.h"

class Controller{
private:
    App& app;
    View view;
    ContactsView contactsView;
    GroupChatView groupChatView;
    MessageView messageView;
    NotificationsView notificationsView;
    AdminView adminView;
public:
    void setApp(App&);
    explicit Controller(App&);
    void run();
    void runContacts();
    void runChats();

    bool runChat(Group &chat);

    bool runChatSettings(Group &chat);

    void runMessages();
    void runNotifications();
    void runAdmin();
};

#endif