//
// Created by super on 11.04.2021.
//

#include "Date.h"

Date::Date(int hours, int minutes, int day, int month, int year) : minutes(minutes), hours(hours), day(day),
                                                                     month(month), year(year) {}

Date Date::operator+(int termMinutes) {
    Date newDate = *this;
    int termHours = termMinutes/60; // calculating hours in minutes
    termMinutes = termMinutes%60;
    if(newDate.minutes+termMinutes >= 60){
        newDate.hours+=(newDate.minutes+termMinutes)/60;
        newDate.minutes = (newDate.minutes+termMinutes)%60;
    }
    else{
        newDate.minutes = newDate.minutes+termMinutes;
    }
    if(newDate.hours+termHours >= 24){
        newDate.hours = (newDate.hours+termHours)%24;
        newDate.day++;
    }
    else{
        newDate.hours = newDate.hours+termHours;
    }
    if(newDate.day > daysInMonths[newDate.month-1]){ // each months have own number of days. We do -1 because massive starts with zero index.
        newDate.day = day%daysInMonths[newDate.month-1] + 1;
        newDate.month++;
    }
    if(newDate.month > 12){
        newDate.month = newDate.month%12;
        newDate.year++;
    }
    return newDate;
}

int Date::getMinutes() const {
    return minutes;
}

int Date::getHours() const {
    return hours;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

Date Date::getCurrentDate() {
    time_t t = std::time(nullptr);   // get time now
    tm* now = std::localtime(&t);
    return Date(now->tm_hour, now->tm_min, now->tm_mday, now->tm_mon, 1900+now->tm_year);
}

bool Date::operator>(Date date) const {
    if(minutes + hours*60 + day*24*60 + month*daysInMonths[month-1]*24*60 + year*365*24*60 >
    date.getMinutes()*60 + date.getDay()*24*60 + date.getMonth()*daysInMonths[date.getMonth()-1]*24*60 + date.getYear()*365*24*60){
        return true;
    }
    else{
        return false;
    }

}

