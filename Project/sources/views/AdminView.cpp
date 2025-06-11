
#include "AdminView.h"
#include <iostream>

void AdminView::display() const {
    std::cout << "#### Admin Menu ###\n\n";
    std::cout << "Pick one option:\n";
    std::cout << "a - Create Admin Profile\n";
    std::cout << "d - Delete Admin Profile\n";
    std::cout << "m - Go back to main menu\n";
}

std::string AdminView::getInput() const {
    std::string input;
    std::cout << "Enter your choice (a/d/m): ";
    std::getline(std::cin, input);
    return input;
}
