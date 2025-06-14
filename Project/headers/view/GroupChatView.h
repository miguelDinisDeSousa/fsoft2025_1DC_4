#ifndef GROUPCHATVIEW_H
#define GROUPCHATVIEW_H

#include <iostream>
#include <list>
#include "GroupChat.h"
#include "GroupChatContainer.h"

class GroupChatView {
public:
    char displayChats(GroupChatContainer &container, int currentPage) const;

    static char displayChat(Group &currentChat, int currentPage) ;

    void displayGroups(const std::list<Group>& groups) const;
    void displayGroupMembers(const Group& group) const;
    Group getGroup() const;

};

#endif // GROUPCHATVIEW_H

