#include "InteractionsView.h"
#include <iostream>
#include <ctime>

InteractionsView::InteractionsView(const InteractionHistoryContainer& interactions) 
    : interactions(interactions) {}

std::string InteractionsView::handleInput(const std::string& input) {
    if (input == "\n") nextPage();
    else if (input == "\t") prevPage();
    else if (input == "5") firstPage();
    else if (input == "6") lastPage();
    return input;
}

// Navigation methods
void InteractionsView::nextPage() {
    int totalPages = (interactions.getInteractions().size() + INTERACTIONS_PER_PAGE - 1) / INTERACTIONS_PER_PAGE;
    if (currentPage < totalPages - 1) currentPage++;
}

void InteractionsView::prevPage() {
    if (currentPage > 0) currentPage--;
}

void InteractionsView::firstPage() {
    currentPage = 0;
}

void InteractionsView::lastPage() {
    int totalPages = (interactions.getInteractions().size() + INTERACTIONS_PER_PAGE - 1) / INTERACTIONS_PER_PAGE;
    currentPage = totalPages - 1;
}