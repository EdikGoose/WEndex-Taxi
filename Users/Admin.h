//
// Created by super on 25.04.2021.
//

#ifndef WENDEX_TAXI_ADMIN_H
#define WENDEX_TAXI_ADMIN_H

#include "User.h"
#include "Passenger.h"
#include "Driver.h"

class Admin {
private:
    string name;
    string phoneNumber;
    string password;

public:
    Admin(const string &name, const string &phoneNumber, const string &password);

    static string serialize(const Admin& admin);

    void blockPassenger(Passenger* passenger);

    void blockDriver(Driver* driver);

    void unblockPassenger(Passenger* passenger);

    void unblockDriver(Driver* driver);


    const string &getName() const;

    const string &getPhoneNumber() const;

    const string &getPassword() const;

    const Passenger* findPassenger(const string& phoneNumber);
    const Driver* findDriver(const string& phoneNumber);
    const Car* findCar(const string& numberOfCar);
};


#endif //WENDEX_TAXI_ADMIN_H
