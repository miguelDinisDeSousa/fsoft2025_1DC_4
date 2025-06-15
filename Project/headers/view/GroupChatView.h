#ifndef GROUPCHATVIEW_H
#define GROUPCHATVIEW_H

#include <iostream>
#include <list>

#include "AdministratorContainer.h"
#include "GroupChat.h"
#include "GroupChatContainer.h"

class GroupChatView {
public:
    char displayChats(GroupChatContainer &container, int currentPage) const;

    static char displayChat(Group &currentChat, int currentPage) ;

    char displayChatSettings(Group &currentChat, int currentPage);

    char addElementsToGroup(ContactContainer *members, int numberOfEles) const;

    void displayGroups(const std::list<Group>& groups) const;
    void displayGroupMembers(const Group& group) const;
    Group createGroup(Contact &admin, ContactContainer *allContacts) const;

};

#endif // GROUPCHATVIEW_H

