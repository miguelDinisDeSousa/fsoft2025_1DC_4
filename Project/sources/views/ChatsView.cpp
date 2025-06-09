#include "ChatsView.h"
#include <iostream>
#include <iomanip>
#include "Utils.h"

ChatsView::ChatsView(const ChatContainer& container) 
    : chatContainer(container) {}

void ChatsView::displayChats() const {
    std::cout << "#### Chats Menu ###\n\n";
    
    std::vector<Chat> chats = chatContainer.getChats();
    int start = currentPage * CHATS_PER_PAGE;
    int end = std::min(start + CHATS_PER_PAGE, static_cast<int>(chats.size()));
    
    for (int i = start; i < end; i++) {
        const Chat& chat = chats[i];
        std::cout << (i - start) << " - " << chat.getName() << "\n";
    }
    
    std::cout << "\nPick one option:\n";
    std::cout << "m - Go back to main menu\n";
    std::cout << "0-9 - Select Chat\n";
    std::cout << "Enter - Go to next 10 chats\n";
    std::cout << "Tab - Go to previous 10 chats\n";
    std::cout << "5 - Go to start of the list\n";
    std::cout << "6 - Go to end of the list\n";
    std::cout << "a - Create a new chat\n";
    std::cout << "s - Search Chat\n";
}

void ChatsView::handleInput(const std::string& input) {
    if (input == "\n") {
        nextPage();
    } else if (input == "\t") {
        prevPage();
    } else if (input == "5") {
        firstPage();
    } else if (input == "6") {
        lastPage();
    }
    // Other input handled by controller
}

void ChatsView::nextPage() {
    int totalPages = (chatContainer.getChats().size() + CHATS_PER_PAGE - 1) / CHATS_PER_PAGE;
    if (currentPage < totalPages - 1) {
        currentPage++;
    }
}

void ChatsView::prevPage() {
    if (currentPage > 0) {
        currentPage--;
    }
}

void ChatsView::firstPage() {
    currentPage = 0;
}

void ChatsView::lastPage() {
    int totalPages = (chatContainer.getChats().size() + CHATS_PER_PAGE - 1) / CHATS_PER_PAGE;
    currentPage = totalPages - 1;
}

std::string ChatsView::getSelectedChatId() const {
    std::vector<Chat> chats = chatContainer.getChats();
    int start = currentPage * CHATS_PER_PAGE;
    int index = start + std::stoi(selectedOption);
    if (index >= start && index < start + CHATS_PER_PAGE && index < chats.size()) {
        return chats[index].getId();
    }
    throw NotFoundEntityException("Invalid chat selection");
}