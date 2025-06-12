
#include "GroupChat.h"

class GroupChatView {
private:
    GroupChat currentChat;

public:
    GroupChatView(const GroupChat& chat);
    void displayChat() const;
    void handleUserInput(const std::string& input);
};
