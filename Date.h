//
// Created by super on 11.04.2021.
//

#ifndef WENDEX_TAXI_DATE_H
#define WENDEX_TAXI_DATE_H

#include <iostream>
#include <ctime>

using namespace std;

static int daysInMonths[] = { // keep how many days in each month
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31,
};

class Date {
private:
    int minutes = 0;
    int hours = 0;
    int day = 0;
    int month = 0;
    int year = 0;
public:
    Date() = default;

    Date(int hours, int minutes, int day, int month, int year);

    /**
     * In our program we have summation only hours and minutes, because trip cannot be longer than one day.
     * Let we do not have leap year.
     * @param termDate
     * @return
     */
    Date operator+(int termMinutes);

    bool operator>=(Date date) const;
    bool operator<=(Date date) const;
    bool operator!=(Date date) const;
    Date& operator=(Date date);


    /**
     * Use ctime library to get present date
     */
    static Date getCurrentDate();


    [[nodiscard]] int getMinutes() const;

    [[nodiscard]] int getHours() const;

    [[nodiscard]] int getDay() const;

    [[nodiscard]] int getMonth() const;

    [[nodiscard]] int getYear() const;

    bool isNull() const;
};


#endif //WENDEX_TAXI_DATE_H
