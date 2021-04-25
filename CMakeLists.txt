cmake_minimum_required(VERSION 3.17)
project(WEndex_Taxi)

set(CMAKE_CXX_STANDARD 20)

add_executable(WEndex_Taxi main.cpp Users/User.cpp Users/User.h Users/Passenger.cpp Users/Passenger.h Users/Driver.cpp Users/Driver.h Payment/Card.cpp Payment/Card.h Payment/PaymentMethod.h Location.cpp Location.h OrderClasses/Order.cpp OrderClasses/Order.h Date.cpp Date.h SystemClasses/PassengerGateway.cpp SystemClasses/PassengerGateway.h SystemClasses/DriverGateway.cpp SystemClasses/DriverGateway.h SystemClasses/System.cpp SystemClasses/System.h Cars/Car.cpp Cars/Car.h Cars/EconomyCar.cpp Cars/EconomyCar.h Cars/ComfortCar.cpp Cars/ComfortCar.h Cars/ComfortPlusCar.cpp Cars/ComfortPlusCar.h Cars/BusinessCar.cpp Cars/BusinessCar.h Output.cpp Output.h Cars/CarType.h SystemClasses/CarGateway.cpp SystemClasses/CarGateway.h DB_Helper.cpp DB_Helper.h Users/Admin.cpp Users/Admin.h SystemClasses/AdminGateway.cpp SystemClasses/AdminGateway.h)