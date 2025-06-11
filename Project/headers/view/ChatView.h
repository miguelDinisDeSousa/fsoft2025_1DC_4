
#include "Chat.h"

class ChatView {
private:
    Chat currentChat;

public:
    ChatView(const Chat& chat);
    void displayChat() const;
    void handleUserInput(const std::string& input);
};
