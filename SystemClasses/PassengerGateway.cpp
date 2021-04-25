//
// Created by super on 11.04.2021.
//

#include "PassengerGateway.h"
#include "../DB_Helper.h"


Passenger* PassengerGateway::addPassenger(const string &name, const string &phoneNumber, const string &password) {
    listOfPassengers.push_back(Passenger(name,phoneNumber,password));
    return &listOfPassengers.back();

}

list<Passenger> &PassengerGateway::getMutableListOfAllPassengers() {
    return listOfPassengers;
}

void PassengerGateway::addOrder(Passenger *passenger, Order *order) {
    passenger->addOrder(order);
    passenger->addIdOfOrder(order->getId());
    DB_Helper::writeListOfPassenger();
}

Passenger *PassengerGateway::findByPhoneNumber(const string& phoneNumber) {
    for(Passenger& passenger: getMutableListOfAllPassengers()){
        if(passenger.getPhoneNumber() == phoneNumber)
            return &passenger;
    }
    return nullptr;
}

void PassengerGateway::addOrderToPassengerById(Passenger *passenger, Order *order) {
    for(int idOfOrder: passenger->getOrderHistoryId()){
        if(idOfOrder == order->getId()){
            passenger->addOrder(order);
        }
    }
}

const list<Passenger> &PassengerGateway::getListOfPassengers() {
    return listOfPassengers;
}



