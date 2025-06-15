#include "InteractionsView.h"
#include <iostream>
#include <ctime>

InteractionsView::InteractionsView(const InteractionHistory& interactions)
    : interactions(interactions) {}

void InteractionsView::display() {
    std::cout << "Interactions : \n\n";
    std::cout << interactions.getContent();
}
