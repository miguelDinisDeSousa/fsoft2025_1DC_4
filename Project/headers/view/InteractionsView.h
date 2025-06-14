#ifndef INTERACTIONS_VIEW_H
#define INTERACTIONS_VIEW_H

#include "InteractionHistory.h"
#include <string>

class InteractionsView {
private:
    const InteractionHistory& interactions;
    int currentPage = 0;
    const int INTERACTIONS_PER_PAGE = 10;
public:
    explicit InteractionsView(const InteractionHistory& interactions);
    void display();
};

#endif // INTERACTIONS_VIEW_H
