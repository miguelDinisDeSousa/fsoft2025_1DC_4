#ifndef FSOFT2025_1DC_4_INTERACTIONHISTORYCONTAINER_H
#define FSOFT2025_1DC_4_INTERACTIONHISTORYCONTAINER_H

#include <list>
#include "InteractionHistory.h"
#include "Utils.h"

class InteractionHistoryContainer {
private:
    std::list<InteractionHistory> interactions;

public:
    void addInteraction(const InteractionHistory&);
    int removeInteraction(const InteractionHistory&, FilterType filter);
    void listInteractions() const;
    bool isInteractionUnique(const InteractionHistory&) const;
    bool isListEmpty() const;


    std::list<InteractionHistory>& getInteractionList();


    const std::list<InteractionHistory>& getInteractions() const;
};

#endif //FSOFT2025_1DC_4_INTERACTIONHISTORYCONTAINER_H

