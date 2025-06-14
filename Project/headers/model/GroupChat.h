#ifndef FSOFT2025_1DC_4_GROUPCHAT_H
#define FSOFT2025_1DC_4_GROUPCHAT_H
#include "Contact.h"
#include "ContactContainer.h"
#include "MessageContainer.h"

#define GROUP_MAX_NAME_LEN 64

class Group {
private:
    char name[GROUP_MAX_NAME_LEN] = {'\0'};
    MessageContainer * messages;
    ContactContainer * members;
    ContactContainer * admins;

public:
    Group() = default;
    Group(const char *name, unsigned int &nr_participants, ContactContainer *members, ContactContainer *admins);

    // Getters
    const char* getName() const;
    unsigned int getNrParticipants() const;
    ContactContainer* getMembers();
    ContactContainer* getAdmins() ;
    MessageContainer* getMessages();

    // Setters
    void setName(const char*);
    void setNrParticipants(unsigned int&);
    void setMessages(MessageContainer* messages);
    void setMembers(ContactContainer* members);
    void setAdmins(ContactContainer* admins);

    // Member management
    void addMember(const Contact&);

    void addAdmin(const Contact &contact);

    void removeMember(int contactId);

    void removeAdmin(int contactId);

    //Verify if Contact is admin
    bool isContactAdmin(int contactId);
};

#endif //FSOFT2025_1DC_4_GROUPCHAT_H

