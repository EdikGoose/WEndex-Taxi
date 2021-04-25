#include <iostream>
#include "Users/Passenger.h"
#include "Users/Driver.h"
#include "Date.h"
#include "Output.h"
#include "Cars/Car.h"
#include "Cars/ComfortCar.h"
#include "SystemClasses/System.h"
#include "Cars/EconomyCar.h"
#include <thread>
#include <ctime>
#include "DB_Helper.h"


using namespace std;



int main() {
    srand((unsigned) time(nullptr)); // for unique random


    Location startLocation(0,0);
    Location endLocation(6,8);

    //Initialize all types of cars
    Car* BusinessCar = System::registerCar("TESLA","RED","1AAA55",CarType::BUSINESS);
    Car* EconomyCar = System::registerCar("LADA","BLACK","7ABC23",CarType::ECONOMY);
    Car* ComfortCar = System::registerCar("RENO","WHITE","9JGC25",CarType::COMFORT);
    Car* ComfortPlus = System::registerCar("HYUNDAI","GREEN","1KJE83",CarType::COMFORTPLUS);

    //Initialize passengers
    Passenger* passenger1 = System::registerPassenger("ZuevPassenger","+7927351398","13531");
    Passenger* passenger2 = System::registerPassenger("MikePassenger","+7977456398","10531");

    //Initialize drivers
    Driver* driver1 = System::registerDriver("ShilovDriver","+79348566923","13435"); driver1->pinCar(BusinessCar);
    Driver* driver2 = System::registerDriver("IvanovDriver","+79134593485","13435"); driver2->pinCar(EconomyCar);
    Driver* driver3 = System::registerDriver("RezaDriver","+79278345012","1536"); driver3->pinCar(ComfortCar);
    Driver* driver4 = System::registerDriver("KonyuhovDriver","+79123874589","5317"); driver4->pinCar(ComfortPlus);


    //Do some orders. For do preOrder we need two locations, passenger which is doing the order, and needed type of cars
    System::preOrder(startLocation, endLocation, passenger1, CarType::BUSINESS);
    System::preOrder(startLocation, endLocation,passenger2, CarType::COMFORTPLUS);

    System::preOrder(startLocation, endLocation, passenger1, CarType::BUSINESS); // will be rejected, because there are no free drivers

    /*
    Date neededTime = Date::getCurrentDate()+2; // wait 2 minutes before driver end the order
    while(Date::getCurrentDate()<=neededTime);
    */

    System::preOrder(startLocation, endLocation, passenger1, CarType::BUSINESS); // will be confirmed


    //print all checks of orders
    list<Order> listOfOrder = System::getListOfAllOrders();
    for(Order& order: listOfOrder) {
        Output::printCheckOfOrder(&order);
    }


    return 0;
}
