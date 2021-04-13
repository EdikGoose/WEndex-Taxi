//
// Created by super on 10.04.2021.
//

#include "User.h"

const string &User::getName() const {
    return name;
}

double User::getRating() const {
    return rating;
}

const string &User::getPhoneNumber() const {
    return phoneNumber;
}

void User::addOrder(Order* order) {
    orderHistory.push_back(order);
}

const list<Order *> &User::getOrderHistory() const {
    return orderHistory;
}
