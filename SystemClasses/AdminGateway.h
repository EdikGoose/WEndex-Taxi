//
// Created by super on 25.04.2021.
//

#ifndef WENDEX_TAXI_ADMINGATEWAY_H
#define WENDEX_TAXI_ADMINGATEWAY_H

#include "../Users/Admin.h"

class AdminGateway {
    friend class System;
    friend class DB_Helper;
private:
    static inline list<Admin> listOfAllAdmins = {};
    static Admin* addAdmin(const string &name, const string &phoneNumber, const string &password);
    static Admin* findByPhoneNumber(const string& phoneNumber);
    static list<Admin> &getMutableListOfAllAdmins();

public:
    static const list<Admin> &getListOfAllAdmins();



};


#endif //WENDEX_TAXI_ADMINGATEWAY_H
