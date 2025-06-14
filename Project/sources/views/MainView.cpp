
#include "MainView.h"
#include <iostream>

void MainView::display() const {
    std::cout << "### Main Menu ###\n\n";
    std::cout << "Pick one option:\n\n";
    std::cout << "0.Contacts Menu\n";
    std::cout << "1.Notifications\n";
    std::cout << "2.Chats\n";
    std::cout << "3.Administrator Menu\n";
}

std::string MainView::getInput() const {
    std::string input;
    std::cout << "Enter your choice (0-3): ";
    std::getline(std::cin, input);
    return input;
}
