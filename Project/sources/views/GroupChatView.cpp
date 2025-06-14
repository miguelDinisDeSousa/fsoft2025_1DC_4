#include "GroupChatView.h"

#include <ctime>

#include "GroupChat.h"
#include "Message.h"
#include "GroupChatContainer.h"
#include "Utils.h"
#include <vector>

#include "AdministratorContainer.h"

#define CHATS_PER_PAGE 10
#define MESSAGES_PER_PAGE 10

char GroupChatView::displayChats(GroupChatContainer& container, int currentPage) const {
    std::cout << "#### Chats Menu ###\n\n";
    const std::vector<char> allowedChars = {
        'm',
        '0','1','2','3','4','5','6','7','8','9',
        '+',
        '-',
        'a',
        's',
        'S',
        'f'
    };
    std::vector<Group> chats(container.getGroupList().begin(), container.getGroupList().end());


    if (chats.empty()) {
        std::cout << "No groups available.\n";
        std::cout << "\nPick one option:\n";
        std::cout << "m - Go back to main menu\n";
        std::cout << "a - Create a new chat\n";

        return Utils::getCharIfAllowed(allowedChars);
    } else {

        int start = currentPage;
        int end = std::min(start + CHATS_PER_PAGE, static_cast<int>(chats.size()));

        for (int i = currentPage; i < end; ++i) {
            std::cout << (i - currentPage) << " - " << chats[i].getName() << "\n";
        }

        std::cout << "\n\nPick one option:\n";
        std::cout << "m - Go back to main menu\n";
        std::cout << "0-9 - Select Chat\n";
        std::cout << "+ - Go to next 10 chats\n";
        std::cout << "- - Go to previous 10 chats\n";
        std::cout << "s - Go to start of the list\n";
        std::cout << "S - Go to end of the list\n";
        std::cout << "a - Create a new chat\n";
        std::cout << "f - Search Chat\n";

        return Utils::getCharIfAllowed(allowedChars);
    }
}

char GroupChatView::displayChat(Group & currentChat, int currentPage) {
    const std::vector<char> allowedChars = {
        'b', // Back to Chats Menu
        'm', // Back to Main Menu
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', // Delete message
        '+', // Next 10 messages
        '-', // Previous 10 messages
        's', // Start of chat
        'S', // End of chat
        'e', // Edit settings
        'N' // New message
    };
    std::cout << "#### " << currentChat.getName() << " ####\n\n";

    std::vector<Message> messages(currentChat.getMessages()->getMessages().begin(), currentChat.getMessages()->getMessages().end());

    int start = currentPage ;
    int end = std::min(start + MESSAGES_PER_PAGE, static_cast<int>(messages.size()));

    for (int i = start; i < end; i++) {

        char timeBuf[100];
        std::strftime(timeBuf, sizeof(timeBuf), "%H:%M", messages[i].getDate());
        std::cout << (i - currentPage) << " - " << messages[i].getSender()->getName() << "[" << timeBuf << "] " << ": " << messages[i].getContent() << "\n";

    }


    std::cout << "\n \n Pick one option: \n";
    std::cout << "b - Go back to Chats Menu\n";
    std::cout << "m - Go back to Main Menu\n";
    std::cout << "0-9 - Delete your message\n";
    std::cout << "+ - Go to next 10 messages\n";
    std::cout << "- - Go to previous 10 messages\n";
    std::cout << "s - Go to start of the chat\n";
    std::cout << "S - Go to end of the chat\n";
    std::cout << "e - Edit Chat Settings\n";
    std::cout << "N - Send a new Message\n";

    return Utils::getCharIfAllowed(allowedChars);
}

char GroupChatView::displayChatSettings(Group& currentChat, int currentPage) {
    const std::vector<char> allowedChars = {
        'b',
        'm',
        '0','1','2','3','4','5','6','7','8','9',
        '+',
        '-',
        's',
        'S',
        'n',
        'a',
        'e'
    };

    std::cout << "#### Chat Settings ###\n";

    // Display members
    std::cout << "Members:\n";
    std::vector<Contact> members(currentChat.getMembers()->getContactList().begin(), currentChat.getMembers()->getContactList().end());
    int start = currentPage;
    int end = std::min(start + CHATS_PER_PAGE, static_cast<int>(members.size()));


    for (int i = start; i < end; ++i) {
        std::cout << (i - start) << " - " << members[i].getName();
        if (currentChat.isContactAdmin(members[i].getId())) {
            std::cout << " (admin)";
        }
        std::cout << "\n";
    }

    std::cout << "\nPick one option:\n";
    std::cout << "b- Go back to chat\n";
    std::cout << "m - Go back to main Menu\n";
    std::cout << "+ - Go to next 10 members\n";
    std::cout << "- - Go to previous 10 members\n";
    std::cout << "s - Go to start of the list\n";
    std::cout << "S - Go to end of the list\n";
    std::cout << "0-9 - Remove member (admin)\n";
    std::cout << "n - Change group name (admin)\n";
    std::cout << "a - add member (admin)\n";
    std::cout << "e - Add admin members (admin)\n";


    return Utils::getCharIfAllowed(allowedChars);
}


/*
void GroupChatView::displayGroups(const std::list<Group>& groups) const {
    if (groups.empty()) {
        std::cout << "No groups available.\n";
        return;
    }

    std::cout << "\nList of Groups:\n";
    for (const auto& group : groups) {
        std::cout << "Group Name: " << group.getName()
                  << " | Participants: " << group.getNrParticipants() << "\n";
    }
}

void GroupChatView::displayGroupMembers(const Group& group) const {
    const auto& members = group.getMembers();
    if (members.empty()) {
        std::cout << "This group has no members.\n";
        return;
    }

    std::cout << "\nMembers of group '" << group.getName() << "':\n";
    for (const auto& member : members) {
        std::cout << "- " << member.getName() << " | Email: " << member.getEmail()
                  << " | Phone: " << member.getPhone() << "\n";
    }
}
*/

Group GroupChatView::getGroup(Contact& admin) const {
    char* name;
    Utils::getString("Enter group name", name, 3);

    unsigned int count = static_cast<unsigned int>(Utils::getNumber("Enter number of participants"));
    ContactContainer members;
    Group *group;
    members.addContact(admin);
    try {
        group = new Group(name, count, &members, &members);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    delete[] name;
    return *group;
}

