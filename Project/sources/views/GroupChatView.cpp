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
#define CONTACTS_PER_GROUP_CREATION  10
#define MEMBERS_PER_PAGE  10

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

    MessageContainer *messages = currentChat.getMessages();
    messages->listMessagesPaged(currentPage, MESSAGES_PER_PAGE);

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

    if (currentChat.getMembers()->getContactList().empty()) {
        std::cout << "No members in this group.\n";
        return 'b'; // Go back
    }

    const std::vector<char> allowedChars = {'b', 'm','0','1','2','3','4','5','6','7','8','9','+', '-', 's', 'S','n', 'a', 'e'};
    ContactContainer *members = currentChat.getMembers();


    std::cout <<"#### Chat Settings ###\n\n";

    members->listContactsPaged(currentPage, CONTACTS_PER_GROUP_CREATION);

    // Show options
    std::cout << "\nPick one option:\n";
    std::cout << "b - Back to chat\n";
    std::cout << "m - Main Menu\n";
    std::cout << "+ - Next 10 members\n";
    std::cout << "- - Previous 10 members\n";
    std::cout << "s - Start of list\n";
    std::cout << "S - End of list\n";
    std::cout << "0-9 - Remove member\n";
    std::cout << "n - Change group name\n";
    std::cout << "a - Add member\n";
    std::cout << "e - Add admin\n";

    return Utils::getCharIfAllowed(allowedChars);

}


char GroupChatView::addElementsToGroup(ContactContainer * members, int numberOfEles) const {

    std::cout << "\nYou have added\n";
    members->listContacts();

    if (numberOfEles == members->getContactList().size()) {
        const std::vector<char> allowedChars = {
            'y',
            'N',
        };
        std::cout << "\nPick one option:\n";
        std::cout << "You have reached the max occupancy of this group\n";
        std::cout << "y - Confirm Members Added\n";
        std::cout << "N - Cancel Members Added\n";

        return Utils::getCharIfAllowed(allowedChars);

    } else {
        const std::vector<char> allowedChars = {
            'y',
            'N',
            '0','1','2','3','4','5','6','7','8','9',
            '+',
            '-',
            's',
            'S'
        };

        std::cout << "\nPick one option:\n";
        std::cout << "y - Confirm Members Added\n";
        std::cout << "N - Cancel Members Added\n";
        std::cout << "+ - Go to next 10 contacts\n";
        std::cout << "- - Go to previous 10 contacts\n";
        std::cout << "s - Go to start of the contact list\n";
        std::cout << "S - Go to end of the contact list\n";
        std::cout << "0-9 - Add Contact to the Group\n";

        return Utils::getCharIfAllowed(allowedChars);
    }
}

Group GroupChatView::createGroup(Contact& admin, ContactContainer* allContacts) const {
    // Get group name
    char* name;
    Utils::getString("Enter group name", name, 3);

    // Get participant count
    unsigned int count = static_cast<unsigned int>(Utils::getNumber("Enter number of participants (including admin)"));

    // Create containers for members and admins
    ContactContainer members;
    ContactContainer admins;

    // Always add admin as first member and admin
    members.addContact(admin);
    admins.addContact(admin);

    int currentPage = 0;
    bool creationConfirmed = false;

    while (!creationConfirmed) {
        // Display current page of contacts
        std::cout << "\n--- Select Members (Page " << (currentPage/CONTACTS_PER_GROUP_CREATION + 1) << ") ---\n";

        int displayIndex = 0;
        auto contactList = allContacts->getContactList();
        auto it = contactList.begin();
        std::advance(it, currentPage);

        // Display contacts for current page
        for (; it != contactList.end() && displayIndex < CONTACTS_PER_GROUP_CREATION; ++it, ++displayIndex) {

            if (members.existsContactWithID(it->getId())) {
                std::cout << displayIndex << " - " << it->getName() << " (already added)\n";
            } else {
                std::cout << displayIndex << " - " << it->getName() << "\n";
            }
        }

        // Show current selection status
        std::cout << "\nCurrent members (" << members.getContactList().size() << "/" << count << "):\n";
        for (const auto& member : members.getContactList()) {
            std::cout << "  " << member.getName() << "\n";
        }

        // Get user input
        char optionChar = addElementsToGroup(&members, count);

        // Handle navigation
        if (optionChar == '-' && currentPage >= CONTACTS_PER_GROUP_CREATION) {
            currentPage -= CONTACTS_PER_GROUP_CREATION;
        }
        else if (optionChar == 's') {
            currentPage = 0;
        }
        else if (optionChar == '+') {
            if (currentPage + CONTACTS_PER_GROUP_CREATION < contactList.size()) {
                currentPage += CONTACTS_PER_GROUP_CREATION;
            }
        }
        else if (optionChar == 'S') {
            currentPage = contactList.size() - (contactList.size() % CONTACTS_PER_GROUP_CREATION);
            if (currentPage == contactList.size()) {
                currentPage -= CONTACTS_PER_GROUP_CREATION;
            }
        }
        // Handle member selection
        else if (optionChar >= '0' && optionChar <= '9') {
            int selectedIndex = currentPage + (optionChar - '0');

            if (selectedIndex < contactList.size()) {
                auto selectedIt = contactList.begin();
                std::advance(selectedIt, selectedIndex);

                try {
                    if (!members.existsContactWithID(selectedIt->getId())) {
                        members.addContact(*selectedIt);
                        std::cout << "Added: " << selectedIt->getName() << "\n";
                    } else {
                        std::cout << selectedIt->getName() << " is already a member.\n";
                    }
                } catch ( DuplicatedDataException& e) {
                    std::cout << e.what() << "\n";
                }
            } else {
                std::cout << "Invalid selection!\n";
            }
        }
        // Handle confirmation
        else if (optionChar == 'y') {
            if (members.getContactList().size() >= 2) { // At least admin + 1 member
                creationConfirmed = true;
            } else {
                std::cout << "You need at least 1 member besides the admin.\n";
            }
        }
        // Handle cancellation
        else if (optionChar == 'N') {
            delete[] name;
            throw std::runtime_error("Group creation cancelled");
        }
    }


    Group group(name, count, members, admins);
    delete[] name;

    return group;
}
