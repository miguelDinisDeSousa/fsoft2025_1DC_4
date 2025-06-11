#include "MessageView.h"
#include <iostream>

void MessageView::displayHeader(const std::string& chatName) const {
    std::cout << "#### " << chatName << " ####\n\n";
    std::cout << "Type your message below:\n";
}

std::string MessageView::getMessageInput() const {
    std::cout << "> ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}