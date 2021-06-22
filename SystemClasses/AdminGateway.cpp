//
// Created by super on 25.04.2021.
//

#include "AdminGateway.h"


Admin *AdminGateway::addAdmin(const string &name, const string &phoneNumber, const string &password) {
    listOfAllAdmins.emplace_back(name,phoneNumber,password);
    return &listOfAllAdmins.back();
}


list<Admin> &AdminGateway::getMutableListOfAllAdmins() {
    return listOfAllAdmins;
}

Admin *AdminGateway::findByPhoneNumber(const string& phoneNumber) {
    for(auto& admin: listOfAllAdmins){
        if(admin.getPhoneNumber() == phoneNumber){
            return &admin;
        }
    }
    return nullptr;
}

const list<Admin> &AdminGateway::getListOfAllAdmins() {
    return listOfAllAdmins;
}
