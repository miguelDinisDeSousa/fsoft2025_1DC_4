#include "GroupChatSettingsView.h"
#include <iostream>
#include <iomanip>
#define MEMBERS_PER_PAGE 10

GroupChatSettingsView::GroupChatSettingsView(const Chat& chat) : currentChat(chat) {}

void GroupChatSettingsView::displaySettings() const {
    std::cout << "#### Chat Settings ####\n";
    std::cout << "Group: " << currentChat.getName() << "\n\n";
    std::cout << "Members:\n";

    std::vector<Contact> members = currentChat.getMembers().getContacts();
    int start = currentPage * MEMBERS_PER_PAGE;
    int end = std::min(start + MEMBERS_PER_PAGE, static_cast<int>(members.size()));

    for (int i = start; i < end; i++) {
        const Contact& member = members[i];
        std::string adminTag = currentChat.getAdmins().contains(member) ? " (admin)" : "";
        std::cout << (i - start) << " - " << member.getName() << adminTag << "\n";
    }

    std::cout << "\nPick one option:\n";
    std::cout << "b - Go back to chat\n";
    std::cout << "m - Go back to main menu\n";
    std::cout << "Enter - Next 10 members\n";
    std::cout << "Tab - Previous 10 members\n";
    std::cout << "5 - First page\n";
    std::cout << "6 - Last page\n";
    std::cout << "0-9 - Remove member (admin)\n";
    std::cout << "n - Change group name (admin)\n";
    std::cout << "a - Add member (admin)\n";
    std::cout << "e - Edit admin members (admin)\n";
}

void GroupChatSettingsView::handleInput(const std::string& input) {
    if (input == "\n") {
        nextPage();
    } else if (input == "\t") {
        prevPage();
    } else if (input == "5") {
        firstPage();
    } else if (input == "6") {
        lastPage();
    }
    // Other input handled by controller
}

std::string GroupChatSettingsView::getSelectedMemberId() const {
    std::vector<Contact> members = currentChat.getMembers().getContacts();
    int start = currentPage * MEMBERS_PER_PAGE;
    int index = start + std::stoi(selectedOption);
    if (index >= start && index < start + MEMBERS_PER_PAGE && index < members.size()) {
        return members[index].getId();
    }
    throw NotFoundEntityException("Invalid member selection");
}

void GroupChatSettingsView::nextPage() {
    int totalPages = (currentChat.getMembers().getContacts().size() + MEMBERS_PER_PAGE - 1) / MEMBERS_PER_PAGE;
    if (currentPage < totalPages - 1) {
        currentPage++;
    }
}

void GroupChatSettingsView::prevPage() {
    if (currentPage > 0) {
        currentPage--;
    }
}

void GroupChatSettingsView::firstPage() {
    currentPage = 0;
}

void GroupChatSettingsView::lastPage() {
    int totalPages = (currentChat.getMembers().getContacts().size() + MEMBERS_PER_PAGE - 1) / MEMBERS_PER_PAGE;
    currentPage = totalPages - 1;
}
