#include "InteractionHistoryContainer.h"
#include <iostream>
#include <cstring>
#include "InvalidDataException.h"
#include "DuplicatedDataException.h"
#include "Utils.h"

void InteractionHistoryContainer::addInteraction(const InteractionHistory& interaction) {
    if (strlen(interaction.getDate()) < 4 || strlen(interaction.getType()) < 3) {
        throw InvalidDataException("Invalid interaction data.");
    }

    if (!this->isInteractionUnique(interaction)) {
        throw DuplicatedDataException("This interaction already exists.");
    }

    interactions.push_back(interaction);
}

int InteractionHistoryContainer::removeInteraction(const InteractionHistory& interaction, FilterType filter) {
    if (interactions.empty()) return 0;
    if (filter != FILTER_DATE && filter != FILTER_TYPE && filter != FILTER_CONTENT) return 0;

    int removed = 0;
    for (auto it = interactions.begin(); it != interactions.end();) {
        bool match = false;

        switch (filter) {
            case FILTER_DATE:
                match = strcmp(it->getDate(), interaction.getDate()) == 0;
                break;
            case FILTER_TYPE:
                match = strcmp(it->getType(), interaction.getType()) == 0;
                break;
            case FILTER_CONTENT:
                match = strcmp(it->getContent(), interaction.getContent()) == 0;
                break;
            default:
                break;
        }

        if (match) {
            it = interactions.erase(it);
            removed++;
        } else {
            ++it;
        }
    }

    return removed;
}

void InteractionHistoryContainer::listInteractions() const {
    if (interactions.empty()) {
        std::cout << "No interactions available.\n";
        return;
    }

    for (const auto& it : interactions) {
        std::cout << "Date: " << it.getDate() << "\n";
        std::cout << "Type: " << it.getType() << "\n";
        std::cout << "Content: " << it.getContent() << "\n\n";
    }
}

bool InteractionHistoryContainer::isInteractionUnique(const InteractionHistory& interaction) const {
    for (const auto& it : interactions) {
        if (strcmp(it.getDate(), interaction.getDate()) == 0 &&
            strcmp(it.getType(), interaction.getType()) == 0 &&
            strcmp(it.getContent(), interaction.getContent()) == 0) {
            return false;
        }
    }
    return true;
}

bool InteractionHistoryContainer::isListEmpty() const {
    return interactions.empty();
}

std::list<InteractionHistory>& InteractionHistoryContainer::getInteractionList() {
    return interactions;
}

const std::list<InteractionHistory>& InteractionHistoryContainer::getInteractions() const {
    return interactions;
}

