//
// Created by super on 10.04.2021.
//

#ifndef WENDEX_TAXI_PASSENGER_H
#define WENDEX_TAXI_PASSENGER_H


#include "User.h"
#include "../Payment/Card.h"
#include "../Payment/PaymentMethod.h"
//#include "../SystemClasses/PassengerGateway.h"
#include "../Location.h"
#include "../Cars/CarType.h"

class Passenger : public User {
    friend class PassengerGateway; // it is friend class because with his help we will create Passenger objects
    friend class DB_Helper;
private:
    PaymentMethod paymentMethod;

    list<Card> listOfCards;
    list<Location> pinnedAddresses;

    bool isOnTrip = false;

    Passenger(const string &name, const string &phoneNumber, const string &password); // private constructor
public:
    void addPinnedAddress(const Location& location);


    void addCard(const Card& card);

    static string serialize(const Passenger& passenger);

    const list<Location> &getPinnedAddresses() const;

    bool canMakeOrder();

};


#endif //WENDEX_TAXI_PASSENGER_H
