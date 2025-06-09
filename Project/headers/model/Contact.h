//
// Created by carlo on 31/05/2025.
//

#ifndef FSOFT2025_1DC_4_CONTACT_H
#define FSOFT2025_1DC_4_CONTACT_H


#include <iostream>
#include <cstring>
#include <list>

#define CONTACT_MAX_NAME_LEN 64
#define CONTACT_MAX_EMAIL_LEN 64
#define CONTACT_MAX_PHONE_LEN 16

class Contact {
private:
    unsigned int id = 0;
    char name[CONTACT_MAX_NAME_LEN] = {'\0'};
    char phone[CONTACT_MAX_PHONE_LEN] = {'\0'};
    char email[CONTACT_MAX_EMAIL_LEN] = {'\0'};

public:
    Contact() = default;
    Contact(unsigned int&, const char*, const char*, const char*);

    // Getters
    unsigned int getId() const;
    const char* getName() const;
    const char* getPhone() const;
    const char* getEmail() const;

    // Setters
    void setId(unsigned int&);
    void setName(const char*);
    void setPhone(const char*);
    void setEmail(const char*);
};


#endif //FSOFT2025_1DC_4_CONTACT_H
