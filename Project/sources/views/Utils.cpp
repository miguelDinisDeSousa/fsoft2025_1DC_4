#include <iostream>
#include <cstring>
#include <limits>
#include <ctime>

using namespace std;

#include "Utils.h"
#include "GlobalVariables.h"
#include "InvalidDataException.h"
#define MAX_LENGHT 100

int Utils::getNumber(const char* message){
    int inputNumber = -1;
    cout<< endl << message <<": ";
    bool failed = false;
    do {
        cin >> inputNumber;
        if((failed = cin.fail())) {

            cout << "\nThe value should only contain numbers. Please try again: ";
            inputNumber = -1;
        }

        //clear the input buffer and ask for a re-input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(failed);

    //In case we find some errors on the input
    return inputNumber;
}

void Utils::getString(const char* message, char*& result, size_t minimumCharacters){
    char inputString[MAX_LENGHT];
    cout<< endl << message <<": ";
    cin.getline(inputString, sizeof(inputString));

    size_t resultLen = strlen(inputString);
    if(resultLen < minimumCharacters) {
        throw InvalidDataException("Input length does not follow the requirements");
    }

    resultLen++;

    //This has to be freed afterwards
    result = new char[resultLen];

    if(resultLen > 1) {
        strncpy(result, inputString, resultLen);
    }
    //making sure the string is null terminated
    result[resultLen-1] = '\0';
}

void Utils::clearOutput() {
    switch(operatingSystem) {
        case UNIX_OS:
            std::system("clear");
            break;
        case WINDOWS_OS:
            std::system("cls");
            break;
        default:
            break;
    }
}

double Utils::getDouble(const char* message){
    double inputNumber = 0.0;
    cout<< endl << message <<": ";
    bool failed = false;
    do {
        cin >> inputNumber;
        if((failed = cin.fail())) {

            cout << "\nThe value should only contain numbers. Please try again: ";
            inputNumber = 0.0;
        }

        //clear the input buffer and ask for a re-input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while(failed);

    //In case we find some errors on the input
    return inputNumber;
}

void Utils::getCurrentDate(unsigned int& day, unsigned int& month, unsigned int& year) {
    time_t currentTimestamp = time(nullptr);
    struct tm* localTime = localtime(&currentTimestamp);

    day = static_cast<unsigned int>(localTime->tm_mday);
    month = static_cast<unsigned int>(localTime->tm_mon + 1);
    year = static_cast<unsigned int>(localTime->tm_year + 1900);
}