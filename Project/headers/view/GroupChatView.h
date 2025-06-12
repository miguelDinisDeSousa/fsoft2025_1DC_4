#ifndef GROUPCHATVIEW_H
#define GROUPCHATVIEW_H

#include <iostream>
#include <list>
#include "GroupChat.h"

class GroupChatView {
public:
    void displayGroups(const std::list<Group>& groups) const;
    void displayGroupMembers(const Group& group) const;
    Group getGroup() const;

};

#endif // GROUPCHATVIEW_H

