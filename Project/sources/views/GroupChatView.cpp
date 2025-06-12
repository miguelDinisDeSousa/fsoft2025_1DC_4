#include "GroupChatView.h"
#include "GroupChat.h"
#include "MessageContainer.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Utils.h"
#include MESSAGES_PER_PAGE 10

GroupChatView::GroupChatView(const GroupChat& chat) : currentChat(chat) {}

void GroupChatView::displayChat() const {
    std::cout << "#### " << currentChat.getName() << " ####\n\n";
    
    MessageContainer messages = currentChat.getMessages();
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

void GroupChatView::handleInput(const std::string& input) {
    if (input == "b") {
        // Handled by controller
    } else if (input == "s") {
        // Handled by controller
    } else if (input == "\n") {
        nextPage();
    } else if (input == "\t") {
        prevPage();
    } else if (input == "5") {
        firstPage();
    } else if (input == "6") {
        lastPage();
    }
    // Message input handled separately
}

std::string GroupChatView::getMessageInput() const {
    std::cout << "Type your message or press 'b' to go back:\n";
    std::string input;
    std::getline(std::cin, input);
    return Utils::trim(input);
}

void GroupChatView::nextPage() {
    int totalPages = (currentChat.getMessages().getMessages().size() + MESSAGES_PER_PAGE - 1) / MESSAGES_PER_PAGE;
    if (currentPage < totalPages - 1) {
        currentPage++;
    }
}

void GroupChatView::prevPage() {
    if (currentPage > 0) {
        currentPage--;
    }
}

void GroupChatView::firstPage() {
    currentPage = 0;
}

void GroupChatView::lastPage() {
    int totalPages = (currentChat.getMessages().getMessages().size() + MESSAGES_PER_PAGE - 1) / MESSAGES_PER_PAGE;
    currentPage = totalPages - 1;
}
