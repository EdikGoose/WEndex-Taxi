//
// Created by super on 10.04.2021.
//

#ifndef WENDEX_TAXI_DRIVER_H
#define WENDEX_TAXI_DRIVER_H


#include "User.h"

class Driver: public User {
private:
    //Car* car;
public:
    Driver(const string &name, const string &phoneNumber, const string &password);

};


#endif //WENDEX_TAXI_DRIVER_H
