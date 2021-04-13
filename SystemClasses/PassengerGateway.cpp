//
// Created by super on 11.04.2021.
//

#include "PassengerGateway.h"



Passenger* PassengerGateway::addPassenger(const string &name, const string &phoneNumber, const string &password) {
    listOfPassengers.push_back(Passenger(name,phoneNumber,password));
    return &listOfPassengers.back();

}

const list<Passenger> &PassengerGateway::getListOfAllPassengers() {
    return listOfPassengers;
}

void PassengerGateway::addOrder(Passenger *passenger, Order *order) {
    passenger->addOrder(order);
}
