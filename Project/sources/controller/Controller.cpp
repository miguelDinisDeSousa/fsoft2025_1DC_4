
#include "Controller.h"
#include "Exceptions.h"

void Controller::runChat(const std::string& chatId) {
    Chat chat = model.getChatContainer().getChat(chatId);
    ChatView view(chat);

    while (true) {
        view.displayChat();
        std::string input = view.getMessageInput();

        if (input == "b") {
            break;
        } else if (input == "s") {
            runChatSettings(chatId);
        } else if (input.rfind("d ", 0) == 0) {
            try {
                std::string messageId = input.substr(2);
                chat.deleteMessage(messageId, currentUser);
                model.saveChat(chat);
            } catch (const std::exception& e) {
                showError(e.what());
            }
        } else if (!input.empty()) {
            try {
                Message msg(input, currentUser, chat.getType());
                chat.sendMessage(msg);
                model.saveChat(chat);
            } catch (const std::exception& e) {
                showError(e.what());
            }
        }
    }
}

void Controller::runChatSettings(const std::string& chatId) {
    Chat chat = model.getChatContainer().getChat(chatId);
    ChatSettingsView view(chat);

    while (true) {
        view.displaySettings();
        std::string input = getInput();

        if (input == "b") {
            break;
        } else if (input == "m") {
            returnToMain();
        } else if (std::isdigit(input[0])) {
            try {
                std::string memberId = view.getSelectedMemberId();
                chat.removeMember(memberId);
                model.saveChat(chat);
                showMessage("Member removed");
            } catch (const std::exception& e) {
                showError(e.what());
            }
        } else if (input == "n") {
            std::string newName = getInput("Enter new group name: ");
            chat.setName(newName);
            model.saveChat(chat);
            showMessage("Group name updated");
        } else {
            view.handleInput(input);
        }
    }
}
