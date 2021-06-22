//
// Created by super on 10.04.2021.
//

#include "Passenger.h"
#include "../Cars/CarType.h"
#include "../SystemClasses/DriverGateway.h"
#include "../DB_Helper.h"

Passenger::Passenger(const string &name, const string &phoneNumber, const string &password) : User(name, phoneNumber,
                                                                                                   password) {
    paymentMethod = PaymentMethod::CARD;
}

void Passenger::addPinnedAddress(const Location &location) {
    pinnedAddresses.push_back(location);
    DB_Helper::writeListOfPassenger();

}

void Passenger::addCard(const Card &card) {
    listOfCards.push_back(card);
}

string Passenger::serialize(const Passenger& passenger) {
    string passengerStr = "/Name " + passenger.getName() + "/Phone " + passenger.getPhoneNumber() + "/Password " + passenger.getPassword() +
            "/Orders {";
    for(auto order: passenger.getOrderHistoryId()){
        passengerStr += to_string(order);
        passengerStr += " ";
    }
    passengerStr += "}";

    passengerStr += "/";

    passengerStr += "PinnedAddresses {";
    for(const auto& address: passenger.getPinnedAddresses()){
        passengerStr += Location::serialize(address);
        passengerStr += " ";
    }
    passengerStr += "}";

    passengerStr += "/";

    string stringAnswer = passenger.isBlocked ? "true" : "false";

    passengerStr += "IsBanned? "+stringAnswer;

    passengerStr += "/";

    return passengerStr;

}

const list<Location> &Passenger::getPinnedAddresses() const {
    return pinnedAddresses;
}



bool Passenger::canMakeOrder() {
    Order* lastOrder = getOrderHistory().back();
    if(orderHistory.empty() || Date::getCurrentDate() >= lastOrder->getEndDate()){
        return true;
    }
    return false;
}
