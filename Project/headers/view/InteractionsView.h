#ifndef INTERACTIONS_VIEW_H
#define INTERACTIONS_VIEW_H

#include "InteractionHistoryContainer.h"
#include <string>

class InteractionsView {
private:
    const InteractionHistoryContainer& interactions;
    int currentPage = 0;
    const int INTERACTIONS_PER_PAGE = 10;
public:
    explicit InteractionsView(const InteractionHistoryContainer& interactions);
    std::string handleInput(const std::string& input);
    
    // Navigation
    void nextPage();
    void prevPage();
    void firstPage();
    void lastPage();
};

#endif // INTERACTIONS_VIEW_H