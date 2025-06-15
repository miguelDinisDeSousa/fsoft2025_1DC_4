#include "MessageView.h"
#include <iostream>

void MessageView::displayHeader(const std::string& chatName) const {
    std::cout << "#### " << chatName << " ####\n\n";
    std::cout << "Type your message below:\n";
}

Message MessageView::getMessageInput() const {
    unsigned int id = Utils::getNumber("Enter message ID");
    //unsigned int sender = Utils::getNumber("Enter sender ID");
    Contact sender = Contact();
    unsigned int receiver = Utils::getNumber("Enter receiver ID");

    char* content;
    Utils::getString("Enter message content", content, 1);

    char* date;
    Utils::getString("Enter message date", date, 4);  // ou usar Utils::getCurrentDate() se preferires gerar a data automaticamente

    Message msg(id, content, &sender);

    delete[] content;
    delete[] date;

    return msg;
}
