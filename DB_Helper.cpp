//
// Created by super on 13.04.2021.
//

#include "DB_Helper.h"
#include "SystemClasses/System.h"



list<Order> DB_Helper::readListOfOrders() {
    list<Order> listOfOrders;
    readListOfCars();
    readListOfDrivers();
    readListOfPassenger();
    readListOfAdmins();

    ifstream OrdersFile ("../DBs/OrdersDB");
    string line;
    if (OrdersFile.is_open())
    {
        while (getline (OrdersFile, line))
        {
            // id min1 hour1 day1 month1 year1  min2 hour2 day2 month2 year2  coordX coordY coordX coordY phonePassenger phoneDriver
            if(line.empty())break;
            vector<string> info = divideIntoWords(line);
            int id = stoi(info[0]);
            Date startDate(stoi(info[2]),stoi(info[1]),stoi(info[3]),stoi(info[4]), stoi(info[5]));
            Date endDate(stoi(info[7]),stoi(info[6]),stoi(info[8]),stoi(info[9]), stoi(info[10]));

            Location startLocation(stoi(info[11]),stoi(info[12]));
            Location endLocation(stoi(info[13]),stoi(info[14]));

            string phonePassenger = info[15];
            Passenger* passenger = PassengerGateway::findByPhoneNumber(phonePassenger);

            string phoneDriver = info[16];
            Driver* driver = DriverGateway::findByPhoneNumber(phoneDriver);

            string carNumber = info[17];
            Car* car = CarGateway::findCarByNumber(carNumber);

            int distance = Location::getDistance(startLocation, endLocation) * 100;
            int cost = (distance * car->getRate()) / 1000;

            Order order(startDate, endDate, startLocation, endLocation, passenger,driver, car,cost,distance);
            order.setId(id);
            Order::setCommonId(id); // the last order will be have the latest ID

            listOfOrders.push_back(order);

            PassengerGateway::addOrderToPassengerById(passenger, &listOfOrders.back()); // adding read order to passengers
            DriverGateway::addOrderToDriverById(driver, &listOfOrders.back()); // adding read order to driver
        }
        OrdersFile.close();
        return listOfOrders;
    }
    else{
        cout << "Problems with opening file";
        return list<Order>();
    }
}

void DB_Helper::writeListOfOrders() {
    ofstream OrdersFile("../DBs/OrdersDB");
    string line;
    if(OrdersFile.is_open()){
        list<Order> listOfOrder = System::getListOfAllOrders();
        for(const Order& order: listOfOrder){
            // min1 hour1 day1 month1 year1  min2 hour2 day2 month2 year2  coordX coordY coordX coordY phonePassenger phoneDriver
            OrdersFile << order.getId() << " " << order.getStartDate().getMinutes() << " " << order.getStartDate().getHours() << " " <<
                    order.getStartDate().getDay() << " " << order.getStartDate().getMonth() << " " << order.getStartDate().getYear() << " " <<
                    order.getEndDate().getMinutes() << " " << order.getEndDate().getHours() << " " << order.getEndDate().getDay() << " " <<
                    order.getEndDate().getMonth()  << " " << order.getEndDate().getYear() << " " << order.getStartLocation().getCoordinateX()  << " " <<
                    order.getStartLocation().getCoordinateY()  << " " << order.getEndLocation().getCoordinateX()  << " " <<
                    order.getEndLocation().getCoordinateY() << " " << order.getPassenger()->getPhoneNumber()  << " " << order.getDriver()->getPhoneNumber() << " " << order.getCar()->getNumber() << "\n";

        }
        OrdersFile.close();
    }
    else{
        cout << "Problems with opening file";
    }
}


void  DB_Helper::readListOfCars() {
    ifstream CarsFile ("../DBs/CarsDB");
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

void DB_Helper::writeListOfCars() {
    //ofstream CarsFile ("DBs/CarsDB",ios_base::app);
    ofstream CarsFile ("../DBs/CarsDB");
    string line;
    if (CarsFile.is_open())
    {
        for(Car& car: CarGateway::getListOfEconomy())
            CarsFile << car.getNumber() << " " << car.getModel() << " " << car.getColor() << " " << Car::carTypeToString(car.getType()) << endl;
        for(Car& car: CarGateway::getListOfComfort())
            CarsFile << car.getNumber() << " " << car.getModel() << " " << car.getColor() << " " << Car::carTypeToString(car.getType()) << endl;
        for(Car& car: CarGateway::getListOfComfortPlus())
            CarsFile << car.getNumber() << " " << car.getModel() << " " << car.getColor() << " " << Car::carTypeToString(car.getType()) << endl;
        for(Car& car: CarGateway::getListOfBusiness())
            CarsFile << car.getNumber() << " " << car.getModel() << " " << car.getColor() << " " << Car::carTypeToString(car.getType()) << endl;

    }
    else{
        cout << "Problems with opening file";
    }
}




void DB_Helper::readListOfDrivers() {
    ifstream DriversFile ("../DBs/DriversDB");
    string line;
    if (DriversFile.is_open())
    {
        while (getline (DriversFile, line))
        {
            if(line.empty())break;
            string name, phoneNumber, password;
            vector<int> idOfOrders;
            vector<string> pinnedCarsId;

            unsigned int indexOfLastSlash = 0;
            unsigned int indexOfPreviousSlash = 0;

            while(indexOfLastSlash != line.length()-1) {
                indexOfPreviousSlash = indexOfLastSlash;
                indexOfLastSlash = line.find('/', indexOfLastSlash+1);

                unsigned int indexOfFirstLetter = indexOfPreviousSlash+1;
                unsigned int lengthOfWord = indexOfLastSlash - indexOfFirstLetter;


                string info = line.substr(indexOfFirstLetter, lengthOfWord);
                auto words = divideIntoWords(info);

                if(info.find('{') != string::npos) {

                    info.erase(info.begin(), info.begin() + info.find('{') + 1);
                    info.erase(info.end() - 1);

                    if(words[0] == "Orders") {
                        vector<int> orders = divideIntoNumbers(info);
                        for (auto orderId : orders) {
                            idOfOrders.push_back(orderId);
                        }
                    }
                    else if(words[0] == "Cars"){
                        vector<string> cars = divideIntoWords(info);
                        for(const auto& carId: cars){
                            pinnedCarsId.push_back(carId);
                        }
                    }
                }
                else{
                    if(words[0] == "Name"){
                        name = words[1];
                    }
                    else if(words[0] == "Phone"){
                        phoneNumber = words[1];
                    }
                    else if(words[0] == "Password"){
                        password = words[1];
                    }

                }
            }

            Driver* driver = DriverGateway::addDriver(name,phoneNumber,password);
            for(const auto& carNumber: pinnedCarsId){
                driver->pinCar(CarGateway::findCarByNumber(carNumber));
            }
            for(int id: idOfOrders){
                driver->addIdOfOrder(id); // reading only id because orders are not read
            }
        }
        DriversFile.close();
    }
    else{
        cout << "Problems with opening file";
    }
}

void DB_Helper::writeListOfDrivers() {
    ofstream DriversFile ("../DBs/DriversDB");
    if (DriversFile.is_open())
    {
        list<Driver> listOfDrivers = DriverGateway::getMutableListOfAllDrivers();
        for(Driver& driver: listOfDrivers) {
            DriversFile << Driver::serialize(driver) << "\n";
        }

    }
    else{
        cout << "Problems with opening file";
    }
}



void DB_Helper::readListOfPassenger() {
    ifstream PassengersFile ("../DBs/PassengersDB");
    string line;
    if (PassengersFile.is_open())
    {
        while (getline (PassengersFile, line))
        {
            if(line.empty())break;
            string name, phoneNumber, password;
            vector<int> idOfOrders;
            vector<Location> pinnedLocations;

            unsigned int indexOfLastSlash = 0;
            unsigned int indexOfPreviousSlash = 0;

            while(indexOfLastSlash != line.length()-1) {
                indexOfPreviousSlash = indexOfLastSlash;
                indexOfLastSlash = line.find('/', indexOfLastSlash+1);

                unsigned int indexOfFirstLetter = indexOfPreviousSlash+1;
                unsigned int lengthOfWord = indexOfLastSlash - indexOfFirstLetter;


                string info = line.substr(indexOfFirstLetter, lengthOfWord);
                auto words = divideIntoWords(info);

                if(info.find('{') != string::npos){
                    if(words[0] == "PinnedAddresses"){
                        info.erase(info.begin(), info.begin() + info.find('{') + 1);
                        info.erase(info.end() - 1);

                        vector<string> locations = divideIntoWords(info);
                        for (const auto& location : locations) {
                            pinnedLocations.push_back(Location::deserialize(location));
                        }
                    }
                    else {
                        info.erase(info.begin(), info.begin() + info.find('{') + 1);
                        info.erase(info.end() - 1);

                        vector<int> orders = divideIntoNumbers(info);
                        for (auto orderId : orders) {
                           idOfOrders.push_back(orderId);
                        }
                    }
                }
                else{
                    if(words[0] == "Name"){
                        name = words[1];
                    }
                    else if(words[0] == "Phone"){
                        phoneNumber = words[1];
                    }
                    else if(words[0] == "Password"){
                        password = words[1];
                    }

                }
            }

            Passenger* passenger = PassengerGateway::addPassenger(name,phoneNumber,password);
            for(int id: idOfOrders){
                passenger->addIdOfOrder(id); // reading only id because orders are not read
            }
            for(const auto& location: pinnedLocations){
                passenger->addPinnedAddress(location);
            }

        }
        PassengersFile.close();
    }
    else{
        cout << "Problems with opening file";
    }
}

void DB_Helper::writeListOfPassenger() {
    ofstream PassengerFile ("../DBs/PassengersDB");
    if (PassengerFile.is_open())
    {
        list<Passenger> listOfPassenger = PassengerGateway::getMutableListOfAllPassengers();
        for(const Passenger& passenger:listOfPassenger) {
            PassengerFile << Passenger::serialize(passenger) << "\n";
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

void DB_Helper::readListOfAdmins() {
    ifstream AdminsFile ("../DBs/AdminsDB");
    string line;
    if (AdminsFile.is_open())
    {
        while (getline (AdminsFile, line))
        {
            if(line.empty())break;
            string name, phoneNumber, password;

            unsigned int indexOfLastSlash = 0;
            unsigned int indexOfPreviousSlash = 0;

            while(indexOfLastSlash != line.length()-1) {
                indexOfPreviousSlash = indexOfLastSlash;
                indexOfLastSlash = line.find('/', indexOfLastSlash+1);

                unsigned int indexOfFirstLetter = indexOfPreviousSlash+1;
                unsigned int lengthOfWord = indexOfLastSlash - indexOfFirstLetter;


                string info = line.substr(indexOfFirstLetter, lengthOfWord);
                auto words = divideIntoWords(info);
                if(words[0] == "Name"){
                    name = words[1];
                }
                else if(words[0] == "Phone"){
                    phoneNumber = words[1];
                }
                else if(words[0] == "Password"){
                    password = words[1];
                }
            }

            AdminGateway::addAdmin(name,phoneNumber,password);


        }
        AdminsFile.close();
    }
    else{
        cout << "Problems with opening file";
    }
}

void DB_Helper::writeListOfAdmins() {
    ofstream AdminFile ("../DBs/AdminsDB");
    if (AdminFile.is_open())
    {
        list<Admin> listOfAdmins = AdminGateway::getMutableListOfAllAdmins();
        for(const Admin& admin:listOfAdmins) {
            AdminFile << Admin::serialize(admin) << "\n";
        }
    }
    else{
        cout << "Problems with opening file";
    }
}







