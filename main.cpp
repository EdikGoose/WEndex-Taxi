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
    Location location1(5,6);
    Location location2(19,15);

    DB_Helper::readListOfCars();
    Car* car = System::registerCar("EDIK","BLACK","666",CarType::ECONOMY);
    //DB_Helper::writeListOfCars(*car);
    list<EconomyCar> listOfEconomy = CarGateway::getListOfEconomy();
    for(EconomyCar economyCar:listOfEconomy){
        Output::printInfoAboutCar(&economyCar);
    }
    list<BusinessCar> listOfBusiness = CarGateway::getListOfBusiness();
    for(BusinessCar businessCar:listOfBusiness){
        Output::printInfoAboutCar(&businessCar);
    }

    Driver* driver = System::registerDriver("Iskan","1452456","1354",car);


    Passenger* passenger = System::registerPassenger("MikePassenger", "+79273","12345");



    System::preOrder(location1,location2,passenger,CarType::ECONOMY);

    DB_Helper::readListOfDrivers();
    list<Driver> listOfDriver = DriverGateway::getListOfAllDrivers();
    for(const Driver& driver1: listOfDriver){
        Output::printInfoAboutDriver(&driver1);
        for(int id: driver1.getOrderHistoryId()){
            cout << id << " ";
        }
    }


    DB_Helper::writeListOfPassenger();
    DB_Helper::writeListOfDrivers();


    DB_Helper::readListOfPassenger();
    list<Passenger> listOfPassengers = PassengerGateway::getListOfAllPassengers();
    for(const Passenger& passenger1: listOfPassengers){
        Output::printInfoAboutPassenger(&passenger1);
        for(int id: passenger1.getOrderHistoryId()){
            cout << id << " ";
        }
    }
    // доделать читку ордеров и тестить


    //DB_Helper::readListOfDrivers();
   /* srand((unsigned) time(nullptr)); // for unique random

    Location location1(5,6);
    Location location2(19,15);
    Location location3(41,10);

    Car* comfortCar1 = System::registerCar("LADA", "RED", "a355c", CarType::COMFORT);
    Car* comfortCar2 = System::registerCar("BMW", "BLUE", "a355c", CarType::ECONOMY);


    System::registerDriver("Mike","891385","135df", comfortCar1);
    //System::registerDriver("Zuev","891385","135df", comfortCar2);
    Passenger* passenger = System::registerPassenger("Eduard","13524","135f");


    System::preOrder(location1,location2,passenger,CarType::COMFORT);

    System::preOrder(location1,location2,passenger,CarType::COMFORT);

    int minutes = 25; // minutes in current time + 2min. It is needed for testing program

    while(Date::getCurrentDate().getMinutes()<36); // my minGW compiler does not have thread because I artificially wait 1 minute

    System::preOrder(location1,location2,passenger,CarType::COMFORT);


    list<Order> orders = System::getListOfAllOrders();

    for(Order& order: orders){
        Output::printInfoAboutOrder(&order);
    }

*/


    return 0;
}
