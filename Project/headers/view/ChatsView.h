
#include "ChatContainer.h"

class ChatsView {
private:
    ChatContainer chats;

public:
    ChatsView(const ChatContainer& container);
    void displayChats() const;
    void handleUserInput(const std::string& input);
};
