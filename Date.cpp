//
// Created by Student on 17/07/2023.
//

#include "Date.h"
#include <iostream>

enum {JANUARY = 1, FEBRUARY = 2, MARCH = 3, APRIL = 4, MAY = 5, JUNE = 6, JULY = 7, AUGUST = 8, SEPTEMBER = 9, OCTOBER =10, NOVEMBER = 11, DECEMBER = 12}months;

using namespace std;

Date::Date(){}

void Date::setDay(int _day)
{
    if( _day>0 && _day<32)
        day=_day;
    else
        today();
}

void Date:: setMonth(int _month)
{
    if( _month>1 && _month<13)
        month=_month;
    else
        today();
}

void Date:: setYear(int _year)
{
    year=_year;
}

int Date:: GetDay(){
    return day;
}

int Date:: GetMonth()
{
    return day;
}

int Date:: GetYear()
{
    return day;
}

void Date::today() {

    time_t rawtime;
    tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;

}

Date:: Date (int _day, int _month, int _year)
{
    setDay(_day);
    setMonth(_month);
    setYear(_year);
}

void Date:: print()
{
    cout<<"the date is: ";
    if(day < 10 )
        cout<< 0 ;

    cout  << day << "/" ;
    if(month < 10)
        cout<< 0 ;

    cout<< month << "/" << year << endl;
}

void Date:: printMonth(int _month)
{
    switch (month) {
        case JANUARY :
            cout << "Current month is:" << "JANUARY"<<endl;
            break;

        case FEBRUARY :
            cout << "Current month is:" << "FEBRUARY"<<endl;
            break;

        case MARCH:
            cout << "Current month is:" << "MARCH"<<endl;
            break;

        case APRIL :
            cout << "Current month is:" << "APRIL"<<endl;
            break;

        case MAY :
            cout << "Current month is:" << "MAY"<<endl;
            break;

        case JUNE :
            cout << "Current month is:" << "JUNE"<<endl;
            break;

        case JULY :
            cout << "Current month is:" << "JULY"<<endl;
            break;

        case AUGUST :
            cout << "Current month is:" << "AUGUST"<<endl;
            break;

        case SEPTEMBER :
            cout << "Current month is:" << "SEPTEMBER"<<endl;
            break;

        case OCTOBER :
            cout << "Current month is:" << "OCTOBER"<<endl;
            break;

        case NOVEMBER :
            cout << "Current month is:" << "NOVEMBER"<<endl;
            break;

        case DECEMBER :
            cout << "Current month is:" << "DECEMBER"<<endl;
            break;

        default:
            cout << "Month is invalid" << endl;

    }
}


int Date:: numOfDays(int _month)
{
    switch (_month) {
        case JANUARY :
            return 31;
            break;

        case FEBRUARY :
            return 28;
            break;

        case MARCH:
            return 31;
            break;

        case APRIL :
            return 30;
            break;

        case MAY :
            return 31;
            break;

        case JUNE :
            return 30;
            break;

        case JULY :
            return 31;
            break;

        case AUGUST :
            return 31;
            break;

        case SEPTEMBER :
            return 30;
            break;

        case OCTOBER :
            return  31;
            break;

        case NOVEMBER :
            return 30;
            break;

        case DECEMBER :
            return 31;
            break;

        default:
            return NULL;

    }
}

bool Date:: isLeapYear(int _year)
{
    if( (_year % 19 == 3) || (_year % 19 == 6) || (_year % 19 == 8) || (_year % 19 == 11) || (_year % 19 == 14) || (_year % 19 == 17) || (_year % 19 == 0))
        return true;
    return false;
}

Date::~Date()
{
    cout<<"day is: "<<day<<endl;
    cout<<"month is: "<<month<<endl;
    cout<<"year is: "<<year<<endl;
}

void Date::printTomorrow() {
    if (day > 0 && day < 28)
        day += 1;

    if (day == 28) {
        if (month == 2) {  // checking for february
            if ((year % 400 == 0) || (year % 100 != 0 || year % 4 == 0)) {  // leap year check in case of feb
                day = 29;
            } else {
                day = 1;
                month = 3;
            }
        } else {  // when it's not feb
            day += 1;
        }
    }
    if (day == 29) {  // last day check for feb
        if (month == 2) {
            day = 1;
            month = 3;
        } else {
            day += 1;
        }
    }

    if (day == 30) {  // last day check for april, june, september, november
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            day += 1;
        } else {
            day = 1;
            month += 1;
        }
    }
    if (day == 31) {  // last day of the month
        day = 1;
        if (month == 12) {  // checking for last day of the year
            year += 1;
            month = 1;
        } else {
            month += 1;
        }

    }

    print();
}










