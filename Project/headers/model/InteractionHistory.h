//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_INTERACTIONHISTORY_H
#define FSOFT2025_1DC_4_INTERACTIONHISTORY_H

#include <iostream>
#include <cstring>

#define INTERACTION_MAX_DATE_LEN 32
#define INTERACTION_MAX_TYPE_LEN 64
#define INTERACTION_MAX_CONTENT_LEN 256

class InteractionHistory {
private:
    char date[INTERACTION_MAX_DATE_LEN] = {'\0'};
    char type[INTERACTION_MAX_TYPE_LEN] = {'\0'};
    char content[INTERACTION_MAX_CONTENT_LEN] = {'\0'};

public:
    InteractionHistory() = default;
    InteractionHistory(const char*, const char*, const char*);

    // Getters
    const char* getDate() const;
    const char* getType() const;
    const char* getContent() const;

    // Setters
    void setDate(const char*);
    void setType(const char*);
    void setContent(const char*);
};

#endif //FSOFT2025_1DC_4_INTERACTIONHISTORY_H
