//
// Created by super on 10.04.2021.
//

#include "User.h"
#include "../DB_Helper.h"

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

void User::addIdOfOrder(int id) {
    orderHistoryID.push_back(id);
}

const list<int> &User::getOrderHistoryId() const {
    return orderHistoryID;
}

const string &User::getPassword() const {
    return password;
}


