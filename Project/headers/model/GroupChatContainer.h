//
// Created by carlo on 09/06/2025.
//

#ifndef FSOFT2025_1DC_4_GROUPCHATCONTAINER_H
#define FSOFT2025_1DC_4_GROUPCHATCONTAINER_H

#include <list>
#include "GroupChat.h"
#include "Utils.h" // para FilterType

class GroupChatContainer {
private:
    std::list<Group> groups;
    unsigned int biggestID = 0;

public:
    void addGroup(Group&);
    int removeGroup(Group&, FilterType filter);
    void listGroups();
    bool isGroupUnique(Group&);
    bool isListEmpty();
    std::list<Group>& getGroupList();
    bool existsGroupWithName(const char* groupName);
    Group& getGroupByName(const char* groupName);
};

#endif //FSOFT2025_1DC_4_GROUPCHATCONTAINER_H

