//
// Created by Student on 17/07/2023.
//

#ifndef LAB2DATE_DATE_H
#define LAB2DATE_DATE_H


class Date {

public:
    Date();

    void setDay(int _day);

    void setMonth(int _month);

    void setYear(int _year);

    int GetDay();

    int GetMonth();

    int GetYear();

    void today();

    Date (int _day, int _month, int _year);

    void print();


    void printMonth(int _month) ;

    int numOfDays(int _month);

    bool isLeapYear(int _year);

    ~Date();

    void printTomorrow();

private:
    int day;
    int month;
    int year;

};


#endif //LAB2DATE_DATE_H
