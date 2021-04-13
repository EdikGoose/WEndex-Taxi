//
// Created by super on 10.04.2021.
//

#include "Passenger.h"
#include "../Cars/CarType.h"
#include "../SystemClasses/DriverGateway.h"

Passenger::Passenger(const string &name, const string &phoneNumber, const string &password) : User(name, phoneNumber,
                                                                                                   password) {
    paymentMethod = PaymentMethod::CARD;
}

void Passenger::addPinnedAddress(const Location &location) {
    pinnedAddresses.push_back(location);
    //db
}

void Passenger::addCard(const Card &card) {
    listOfCards.push_back(card);
}

