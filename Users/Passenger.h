//
// Created by super on 10.04.2021.
//

#ifndef WENDEX_TAXI_PASSENGER_H
#define WENDEX_TAXI_PASSENGER_H


#include "User.h"
#include "../Payment/Card.h"
#include "../Payment/PaymentMethod.h"
#include "../Location.h"

class Passenger : public User {
private:
    PaymentMethod paymentMethod;
    list<Card> listOfCards;
    list<Location> pinnedAddresses;
public:
    Passenger(const string &name, const string &phoneNumber, const string &password);



};


#endif //WENDEX_TAXI_PASSENGER_H
