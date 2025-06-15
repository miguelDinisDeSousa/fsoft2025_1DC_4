#ifndef CHAT_SETTINGS_VIEW_H
#define CHAT_SETTINGS_VIEW_H

#include "GroupChat.h"
#include "ContactContainer.h"
#include <string>

class  GroupChatSettingsView {
private:
    GroupChat& chat;
    int currentPage = 0;
    const int MEMBERS_PER_PAGE = 10;
public:
    explicit  GroupChatSettingsView(GroupChat& chat);
    void printMembers() const;
    ContactContainer getMembers() const;
    ContactContainer getAdminMembers() const;
    std::string handleInput(const std::string& input);
    void handleMemberRemoval(const std::string& memberId);

    // Navigation
    void nextPage();
    void prevPage();
    void firstPage();
    void lastPage();
};

#endif // CHAT_SETTINGS_VIEW_H
