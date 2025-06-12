#include <iostream>
#include <cstring>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "Utils.h"
#include "InvalidDataException.h"

#define MAX_LENGHT 100

int Utils::getNumber(const char* message){
    int inputNumber = -1;
    cout << endl << message << ": ";
    bool failed = false;
    do {
        cin >> inputNumber;
        if((failed = cin.fail())) {
            cout << "\nThe value should only contain numbers. Please try again: ";
            inputNumber = -1;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(failed);

    return inputNumber;
}

void Utils::getString(const char* message, char*& result, size_t minimumCharacters){
    char inputString[MAX_LENGHT];
    cout << endl << message << ": ";
    cin.getline(inputString, sizeof(inputString));

    size_t resultLen = strlen(inputString);
    if(resultLen < minimumCharacters) {
        throw InvalidDataException("Input length does not follow the requirements");
    }

    resultLen++;
    result = new char[resultLen];
    if(resultLen > 1) {
        strncpy(result, inputString, resultLen);
    }
    result[resultLen - 1] = '\0';
}

double Utils::getDouble(const char* message){
    double inputNumber = 0.0;
    cout << endl << message << ": ";
    bool failed = false;
    do {
        cin >> inputNumber;
        if((failed = cin.fail())) {
            cout << "\nThe value should only contain numbers. Please try again: ";
            inputNumber = 0.0;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(failed);

    return inputNumber;
}

void Utils::getCurrentDate(unsigned int& day, unsigned int& month, unsigned int& year) {
    time_t currentTimestamp = time(nullptr);
    struct tm* localTime = localtime(&currentTimestamp);

    day = static_cast<unsigned int>(localTime->tm_mday);
    month = static_cast<unsigned int>(localTime->tm_mon + 1);
    year = static_cast<unsigned int>(localTime->tm_year + 1900);
}

OperatingSystem Utils::getCurrentOS() {
#ifdef _WIN32
    return WINDOWS_OS;
#elif __unix__ || __linux__ || __APPLE__
    return UNIX_OS;
#else
    return UNKNOWN_OS;
#endif
}

void Utils::clearOutput() {
    OperatingSystem os = Utils::getCurrentOS();
    switch(os) {
        case UNIX_OS:
            std::system("clear");
            break;
        case WINDOWS_OS:
            std::system("cls");
            break;
        default:
            std::cout << std::string(50, '\n');
            break;
    }
}
