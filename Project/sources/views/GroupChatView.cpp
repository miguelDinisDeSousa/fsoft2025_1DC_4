#include "GroupChatView.h"
#include "GroupChat.h"
#include "Message.h"
#include "GroupChatContainer.h"
#include "Utils.h"
#include <vector>

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
void GroupChatView::displayChat(Group & currentChat) const {
    std::cout << "#### " << currentChat.getName() << " ####\n\n";

    std::vector<Message> messages = currentChat.getMessages().getMessages();
    int start = currentPage * MESSAGES_PER_PAGE;
    int end = std::min(start + MESSAGES_PER_PAGE, static_cast<int>(messages.size()));

    for (int i = start; i < end; i++) {
        const Message& msg = messages[i];

        // Format time
        char timeBuf[20];
        std::strftime(timeBuf, sizeof(timeBuf), "%H:%M", std::localtime(&msg.getDate()));

        std::cout << "[" << timeBuf << "] "
                  << msg.getSender().getName() << ": "
                  << msg.getContent() << "\n";
    }

    std::cout << "\nPick one option:\n";
    std::cout << "b - Go back to chats\n";
    std::cout << "s - Settings\n";
    std::cout << "d <num> - Delete message (admin/sender)\n";
    std::cout << "Enter - View older messages\n";
    std::cout << "Type your message and press Enter to send\n";
}


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

Group GroupChatView::getGroup() const {
    char* name;
    Utils::getString("Enter group name", name, 3);

    unsigned int count = static_cast<unsigned int>(Utils::getNumber("Enter number of participants"));

    Group group;
    try {
        group.setName(name);
        group.setNrParticipants(count);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    delete[] name;
    return group;
}
