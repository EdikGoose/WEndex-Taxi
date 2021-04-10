cmake_minimum_required(VERSION 3.17)
project(WEndex_Taxi)

set(CMAKE_CXX_STANDARD 20)

add_executable(WEndex_Taxi main.cpp Users/User.cpp Users/User.h Users/Passenger.cpp Users/Passenger.h Users/Driver.cpp Users/Driver.h Payment/Card.cpp Payment/Card.h Payment/PaymentMethod.h Location.cpp Location.h OrderClasses/Order.cpp OrderClasses/Order.h)