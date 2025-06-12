#ifndef MESSAGE_VIEW_H
#define MESSAGE_VIEW_H

#include "Message.h"
#include "Utils.h"

class MessageView {
public:
    void displayHeader(const std::string& chatName) const;
    Message getMessageInput() const;
};

#endif // MESSAGE_VIEW_H
