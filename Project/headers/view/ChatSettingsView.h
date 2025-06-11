
#include "Chat.h"

class ChatSettingsView {
private:
    Chat currentChat;

public:
    ChatSettingsView(const Chat& chat);
    void displaySettings() const;
    void handleUserInput(const std::string& input);
};
