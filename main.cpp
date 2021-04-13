#include <iostream>
#include "Users/Passenger.h"
#include "Users/Driver.h"
#include "Date.h"
#include "Output.h"
#include "Cars/Car.h"
#include "Cars/ComfortCar.h"
#include "SystemClasses/System.h"
#include "Cars/EconomyCar.h"
#include <ctime>

using namespace std;

int main() {
    srand((unsigned) time(nullptr)); // for unique random

    Location location1(5,6);
    Location location2(19,15);
    Location location3(41,10);

    Car* comfortCar1 = System::registerCar("LADA", "RED", "a355c", CarType::COMFORT);
    Car* comfortCar2 = System::registerCar("BMW", "BLUE", "a355c", CarType::ECONOMY);


    System::registerDriver("Mike","891385","135df", comfortCar1);
    System::registerDriver("Zuev","891385","135df", comfortCar2);
    Passenger* passenger = System::registerPassenger("Eduard","13524","135f");


    System::preOrder(location1,location2,passenger,CarType::COMFORT);


    list<Order> orders = System::getListOfAllOrders();

    for(Order& order: orders){
        Output::printInfoAboutOrder(&order);
    }












    return 0;
}
