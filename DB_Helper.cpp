//
// Created by super on 13.04.2021.
//

#include "DB_Helper.h"
#include "SystemClasses/System.h"



list<Order> DB_Helper::readListOfOrders() {
    readListOfCars();
    readListOfDrivers();
    readListOfPassenger();

    ifstream OrdersFile ("DBs/CarsDB");
    string line;
    if (OrdersFile.is_open())
    {
        while (getline (OrdersFile, line))
        {
            // min1 hour1 day1 month1 year1  min2 hour2 day2 month2 year2  coordX coordY coordX coordY phonePassenger phoneDriver
            if(line.empty())break;
            vector<string> info = divideIntoWords(line);
            Date startDate(stoi(info[0]),stoi(info[1]),stoi(info[2]),stoi(info[3]), stoi(info[4]));
            Date endDate(stoi(info[5]),stoi(info[6]),stoi(info[7]),stoi(info[8]), stoi(info[9]));

            Location startLocation(stoi(info[10]),stoi(info[11]));
            Location endLocation(stoi(info[12]),stoi(info[13]));

            string phonePassenger = info[14];
            Passenger* passenger = PassengerGateway::findByPhoneNumber(phonePassenger);

            string phoneDriver = info[15];
            Driver* driver = DriverGateway::findByPhoneNumber(phoneDriver);
            int distance = Location::getDistance(startLocation, endLocation) * 100;
            int cost = (distance * driver->getCar()->getRate()) / 1000;



        }
        OrdersFile.close();
    }
    else{
        cout << "Problems with opening file";
    }
}

void DB_Helper::writeListOfOrders(const Order &order) {

}


void  DB_Helper::readListOfCars() {
    ifstream CarsFile ("DBs/CarsDB");
    string line;
    if (CarsFile.is_open())
    {
        while (getline (CarsFile,line))
        {
            if(line.empty())break;
            vector<string> info = divideIntoWords(line);
            string number = info[0];
            string model = info[1];
            string color = info[2];
            CarType carType = Car::stringToCarType(info[3]);
            CarGateway::addCar(model,color,number,carType);
        }
        CarsFile.close();
    }
    else{
        cout << "Problems with opening file";
    }
}

void DB_Helper::writeListOfCars(const Car& car) {
    ofstream CarsFile ("DBs/CarsDB",ios_base::app);
    string line;
    if (CarsFile.is_open())
    {
        CarsFile << car.getNumber() << " " << car.getModel() << " " << car.getColor() << " " << Car::carTypeToString(car.getType()) << endl;
    }
    else{
        cout << "Problems with opening file";
    }
}




void DB_Helper::readListOfDrivers() {
    ifstream DriversFile ("DBs/DriversDB");
    string line;
    getline (DriversFile, line); // do not know why, but it put 2 linebreaks on the start
    getline (DriversFile, line);
    if (DriversFile.is_open())
    {
        while (getline (DriversFile, line))
        {
            if(line.empty())break;
            vector<string> info = divideIntoWords(line);
           // name phone password numberOfCar
            string name = info[0];
            string phoneNumber = info[1];
            string password = info[2];
            string numberOfCar = info[3];
            Car* refToCar = CarGateway::findCarByNumber(numberOfCar);

            Driver* driver = DriverGateway::addDriver(name,phoneNumber,password,refToCar);

            string orders;
            getline(DriversFile, orders);
            vector<int> idOfOrders = divideIntoNumbers(orders);
            for(int& id: idOfOrders){
                driver->addIdOfOrder(id);
            }

        }
        DriversFile.close();
    }
    else{
        cout << "Problems with opening file";
    }
}

void DB_Helper::writeListOfDrivers() {
    ofstream DriversFile ("DBs/DriversDB");
    if (DriversFile.is_open())
    {
        list<Driver> listOfDrivers = DriverGateway::getListOfAllDrivers();
        for(Driver& driver: listOfDrivers) {
            DriversFile << driver.getName() << " " << driver.getPhoneNumber() << " " << driver.getPassword() << " "
                        << driver.getCar()->getNumber() << "\n";
            for (const Order *order: driver.getOrderHistory()) {
                DriversFile << order->getId() << " ";
            }
            DriversFile << " " << "\n";
        }

    }
    else{
        cout << "Problems with opening file";
    }
}



void DB_Helper::readListOfPassenger() {
    ifstream DriversFile ("DBs/PassengersDB");
    string line;
    if (DriversFile.is_open())
    {
        while (getline (DriversFile, line))
        {
            if(line.empty())break;
            vector<string> info = divideIntoWords(line);
            // name phone password numberOfCar
            string name = info[0];
            string phoneNumber = info[1];
            string password = info[2];

            Passenger* passenger = PassengerGateway::addPassenger(name,phoneNumber,password);

            string orders;
            getline(DriversFile, orders);
            vector<int> idOfOrders = divideIntoNumbers(orders);
            for(int& id: idOfOrders){
                passenger->addIdOfOrder(id);
            }

        }
        DriversFile.close();
    }
    else{
        cout << "Problems with opening file";
    }
}

void DB_Helper::writeListOfPassenger() {
    ofstream PassengerFile ("DBs/PassengersDB");
    if (PassengerFile.is_open())
    {
        list<Passenger> listOfPassenger = PassengerGateway::getListOfAllPassengers();
        for(Passenger& passenger:listOfPassenger) {
            PassengerFile << passenger.getName() << " " << passenger.getPhoneNumber() << " " << passenger.getPassword()
                          << "\n";
            for (const Order *order: passenger.getOrderHistory()) {
                PassengerFile << order->getId() << " ";
            }
            PassengerFile << " " << "\n";
        }
    }
    else{
        cout << "Problems with opening file";
    }
}



vector<string> DB_Helper::divideIntoWords(const string &line) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

vector<int> DB_Helper::divideIntoNumbers(const string &line) {
    vector<int> numbers;
    stringstream ss(line);
    int number;
    while (ss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}







