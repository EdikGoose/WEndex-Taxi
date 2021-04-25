//
// Created by super on 25.04.2021.
//

#ifndef WENDEX_TAXI_ADMIN_H
#define WENDEX_TAXI_ADMIN_H

#include "User.h"

class Admin : public User {


public:
    Admin(const string &name, const string &phoneNumber, const string &password);

    static string serialize(const Admin& admin);

    void blockPassenger(Passenger* passenger);

    void blockDriver(Driver* driver);
};


#endif //WENDEX_TAXI_ADMIN_H
