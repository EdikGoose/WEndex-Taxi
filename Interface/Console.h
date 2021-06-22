//
// Created by super on 26.04.2021.
//

#ifndef WENDEX_TAXI_CONSOLE_H
#define WENDEX_TAXI_CONSOLE_H


#include <iostream>
#include "../SystemClasses/System.h"
#include <vector>
#include "../Exceptions/IncorrectLoginException.h"
#include "../Exceptions/NoSuchUserException.h"
#include "../Exceptions/PassengerIsOnTripException.h"
#include "../Exceptions/PassengerBlockedException.h"
#include "../Output.h"

using namespace std;

class Console {
public:
    static void printMainMenu();

    static void printLoginForPassenger();
    static void printLoginForDriver();
    static void printLoginForAdmin();

    static vector<string> printLoginMessage();
    static vector<string> printRegistrationMessage();
    static int writeAnswer();
    static Location writeLocation();
    static void addNewPinnedLocation(Passenger* passenger);


    static void printRegistrationForPassenger();
    static void printRegistrationForDriver();
    static void printRegistrationForCar(Driver* driver);


    static void printOptionsForPassenger(Passenger* passenger);
    static void printOptionsForDriver(Driver* driver);
    static void printOptionsForAdmin(Admin * admin);

    static string writePhoneNumber();



    static void order(Passenger * passenger);

    static CarType stringToCarType(const string& stringCarType);


};


#endif //WENDEX_TAXI_CONSOLE_H
