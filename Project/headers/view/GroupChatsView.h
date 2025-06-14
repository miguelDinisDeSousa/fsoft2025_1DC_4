
#include "GroupChatContainer.h"

class GroupChatsView {
private:
    GroupChatContainer chats;

public:
    GroupChatsView(const GroupChatContainer& container);
    void displayChats() const;
    void handleUserInput(const std::string& input);
};
