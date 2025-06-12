#include "GroupChatView.h"
#include "Utils.h"

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
