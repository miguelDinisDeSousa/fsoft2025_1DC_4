#ifndef MESSAGE_VIEW_H
#define MESSAGE_VIEW_H

#include <string>

class MessageView {
public:
    void display(const std::string& chatName) const;
    std::string getMessageInput() const;
};

#endif // MESSAGE_VIEW_H
