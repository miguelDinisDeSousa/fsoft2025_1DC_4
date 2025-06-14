//
// Created by carlo on 04/06/2025.
//

#ifndef FSOFT2025_1DC_4_MESSAGECONTAINER_H
#define FSOFT2025_1DC_4_MESSAGECONTAINER_H


#include "Message.h"
#include "Utils.h"
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include <list>
#include <cstring>


class MessageContainer {
private:
    std::list<Message> messages;
    unsigned int biggestID = 0;

    bool isMessageUnique(Message& message);

public:
    MessageContainer() = default;

    void addMessage(Message& message);
    int removeMessage(Message& message, FilterType filter);
    void listMessages();
    bool isListEmpty();
    std::list<Message>& getMessageList();
    bool existsMessageWithID(unsigned int& id);
    Message& getMessageFromID(unsigned int& id);

    bool removeMessageById(unsigned int id, unsigned int ownerId);

    const std::list<Message>& getMessages() const;
    void setMessages(const std::list<Message>& newMessages);
};




#endif //FSOFT2025_1DC_4_MESSAGECONTAINER_H
