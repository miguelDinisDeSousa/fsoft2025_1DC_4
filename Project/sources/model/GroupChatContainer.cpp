//
// Created by carlo on 09/06/2025.
//
#include "GroupChatContainer.h"
#include "GroupChat.h"
#include <iostream>
#include <cstring>
#include "DuplicatedDataException.h"
#include "InvalidDataException.h"
#include "Utils.h"

void GroupChatContainer::addGroup(Group& group) {
    if (strlen(group.getName()) < 3) {
        throw InvalidDataException("Não é possível criar grupo: o nome deve ter pelo menos 3 caracteres.");
    }

    if (!isGroupUnique(group)) {
        throw DuplicatedDataException("Já existe um grupo com o nome fornecido.");
    }

    groups.push_back(group);
}

int GroupChatContainer::removeGroup(Group& group, FilterType filter) {
    if (groups.empty()) {
        return 0;
    }

    if (filter != FILTER_NAME) {
        return 0;
    }

    int removed = 0;
    for (auto it = groups.begin(); it != groups.end(); ) {
        switch (filter) {
            case FILTER_NAME:
                if (strcmp(it->getName(), group.getName()) == 0) {
                    group = *it;
                    it = groups.erase(it);
                    removed++;
                } else {
                    ++it;
                }
                break;
        }
    }

    return removed;
}

void GroupChatContainer::listGroups() {
    if (groups.empty()) {
        std::cout << "Não existem grupos registados.\n";
        return;
    }

    for (const auto& group : groups) {
        std::cout << "Grupo: " << group.getName()
                  << " | Nº Participantes: " << group.getNrParticipants() << std::endl;
    }
}

bool GroupChatContainer::isGroupUnique(Group& group) {
    for (const auto& g : groups) {
        if (strcmp(g.getName(), group.getName()) == 0) {
            return false;
        }
    }
    return true;
}

bool GroupChatContainer::isListEmpty() {
    return groups.empty();
}

std::list<Group>& GroupChatContainer::getGroupList() {
    return groups;
}

bool GroupChatContainer::existsGroupWithName(const char* groupName) {
    if (groups.empty() || strlen(groupName) == 0) {
        return false;
    }

    for (auto& g : groups) {
        if (strcmp(g.getName(), groupName) == 0) {
            std::cout << "\nGrupo encontrado com nome: " << groupName << std::endl;
            return true;
        }
    }

    return false;
}

Group& GroupChatContainer::getGroupByName(const char* groupName) {
    for (auto& g : groups) {
        if (strcmp(g.getName(), groupName) == 0) {
            return g;
        }
    }

    throw InvalidDataException("Não foi possível encontrar o grupo com o nome fornecido.");
}
