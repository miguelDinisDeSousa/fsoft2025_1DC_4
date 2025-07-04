//
// Created by carlo on 04/06/2025.
//
#include "MessageContainer.h"

#include <algorithm>
#include <ctime>

#include "Message.h"

void MessageContainer::addMessage(Message& message) {
    if (strlen(message.getContent()) < 3) {
        throw InvalidDataException("Can't create message because content is too short");
    }

    if (message.getId() == 0) {
        message.setId(++biggestID);
    }

    if (!this->isMessageUnique(message)) {
        throw DuplicatedDataException("A message already exists with the data provided");
    }

    messages.push_back(message);
}

int MessageContainer::removeMessage(Message& message, FilterType filter) {
    if (messages.empty()) {
        return 0;
    }

    if (filter != FILTER_ID && filter != FILTER_CONTENT) {
        return 0;
    }

    int removed = 0;

    for (auto it = messages.begin(); it != messages.end(); ) {
        switch (filter) {
            case FILTER_ID:
                if (it->getId() == message.getId()) {
                    removed++;
                    it = messages.erase(it);
                } else {
                    ++it;
                }
                break;
            case FILTER_CONTENT:
                if (strcmp(it->getContent(), message.getContent()) == 0) {
                    removed++;
                    it = messages.erase(it);
                } else {
                    ++it;
                }
                break;
        }
    }

    return removed;
}

void MessageContainer::listMessages() {
    if (messages.empty()) {
        std::cout << "No messages available.\n";
        return;
    }

    for (const auto& msg : messages) {
        std::cout << "Message ID: " << msg.getId()
                  << ", Content: " << msg.getContent()
                  << ", Date: " << msg.getDate()
                  << ", Sender: " << msg.getSender()
                  << std::endl;
    }
}

bool MessageContainer::isMessageUnique(Message& message) {
    for (const auto& m : messages) {
        if (m.getId() == message.getId() || strcmp(m.getContent(), message.getContent()) == 0) {
            return false;
        }
    }
    return true;
}

bool MessageContainer::isListEmpty() {
    return messages.empty();
}

std::list<Message>& MessageContainer::getMessageList() {
    return messages;
}

const std::list<Message>& MessageContainer::getMessages() const {
    return messages;
}

void MessageContainer::setMessages(const std::list<Message>& newMessages) {
    messages = newMessages;
}

bool MessageContainer::existsMessageWithID(unsigned int& id) {
    for (const auto& msg : messages) {
        if (msg.getId() == id) {
            std::cout << "\nMessage found with ID: " << id << std::endl;
            return true;
        }
    }
    return false;
}

Message& MessageContainer::getMessageFromID(unsigned int& id) {
    for (auto& msg : messages) {
        if (msg.getId() == id) {
            return msg;
        }
    }
    throw InvalidDataException("Could not get message object from the given ID");
}

bool MessageContainer::removeMessageById(unsigned int id, unsigned int ownerId) {
    auto it = std::find_if(messages.begin(), messages.end(),
        [id](const Message& m) { return m.getId() == id; });

    if (it != messages.end()) {
        if (it->getSender() && it->getSender()->getId() == ownerId) {
            messages.erase(it);
            return true;
        }else {

            std::cout << "\n WARNING: You can only delete your messages \n";
        }

    }
    return false;
}


void MessageContainer::listMessagesPaged(int page , int pageSize) const {
    if (messages.empty()) {
        std::cout << "No messages available.\n";
        return;
    }

    int totalPages = (messages.size() + pageSize - 1) / pageSize;
    page = std::max(1, std::min(page, totalPages)); // Clamp to valid range
    int startIdx = (page - 1) * pageSize;
    int endIdx = std::min(startIdx + pageSize, static_cast<int>(messages.size()));

    std::cout << "--- Messages (Page " << page << "/" << totalPages << ") ---\n";


    auto it = messages.begin();
    std::advance(it, startIdx);

    for (int i = startIdx; i < endIdx; ++i, ++it) {
        char timeBuf[100];
        std::strftime(timeBuf, sizeof(timeBuf), "%H:%M", it->getDate());

        std::cout << (i % pageSize) << ". "
                  << (it->getSender() ? it->getSender()->getName() : "[Unknown]")
                  << " (" << timeBuf << "): "
                  << it->getContent() << "\n";
    }

}