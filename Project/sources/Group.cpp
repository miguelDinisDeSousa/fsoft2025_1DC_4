//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_GROUP_H
#define FSOFT2025_1DC_4_GROUP_H

#include "Group.h"
#include "InvalidDataException.h"
#include "DataConsistencyException.h"

Group::Group(const char* name, unsigned int& nr_participants) {
    setName(name);
    setNrParticipants(nr_participants);
}

// Getters
const char* Group::getName() const {
    return this->name;
}

unsigned int Group::getNrParticipants() const {
    return this->nr_participants;
}

// Setters
void Group::setName(const char* name) {
    if (!name) {
        throw InvalidDataException("Invalid pointer to name.");
    }

    size_t len = strlen(name);
    if (len < 3 || len > GROUP_MAX_NAME_LEN) {
        throw DataConsistencyException("Group name must be between 3 and 64 characters.");
    }

    strncpy(this->name, name, GROUP_MAX_NAME_LEN);
    this->name[GROUP_MAX_NAME_LEN - 1] = '\0';
}

void Group::setNrParticipants(unsigned int& count) {
    if (count < 2) {
        throw DataConsistencyException("A group must have at least 2 participants.");
    }

    this->nr_participants = count;
}


#endif //FSOFT2025_1DC_4_GROUP_H