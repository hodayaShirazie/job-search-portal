#include <iostream>
#include "CV.h"
//#include "Candidate.h"
#include "Administrator.h"
#include <stdlib.h>
#include <cstring>
#include "Employer.h"
#include "Job.h"



//void setConsoleColor(WORD c)
//{
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
//}



//git link: https://github.com/hodayaShirazie/job-search-portal.git







bool checkValidDate(int day, int month, int year) {

    if (year < 1924 || year > 2006) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth;
    if (month == 2) {

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }

    if (day < 1 || day > daysInMonth) {
        return false;
    }

    return true;

}





void set_birth_datee()
{



//        int input;
//        std::cout << "Enter an integer: ";
//        while(!(std::cin >> input)) {
//
//        }
//        std::cout << "You entered the integer: " << input << std::endl;








//    delete [] birthDate;

    int d,m,y;
    cout<<"date: enter month, day and year"<<endl;
    while(!(cin >> m) || !(cin >> d) || !(cin >> y)) //if input is not integer

    {
        cout << "Invalid input.try again \n";
        cin.clear();// Clear the buffer
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignore the rest of the input line to avoid infinite loop
    }

    while(!checkValidDate(d,m,y)) {
        int d,m,y;
        cout<<"invalid date, please enter -valid-: month, day and year"<<endl;
        cin >> m >> d >> y;
    }
    char buffer[10] = "";
    strcat(buffer, to_string(m).c_str());
    strcat(buffer, ".");
    strcat(buffer, to_string(d).c_str());
    strcat(buffer, ".");
    strcat(buffer, to_string(y).c_str());


//    birthDate = new char[strlen(buffer) + 1];
//    strcpy(birthDate, buffer);

}







void ph_id()
{

    bool valid = false;

    char buffer[80];

//    delete [] phoneNumber;
//    cin.ignore();
    cout << "phone number" << endl;
    cin.getline(buffer, 80);

    while (!valid) {
        bool onlyDigits = true;

        for (int i = 0; buffer[i] != '\0'; ++i)
            if (buffer[i] < '0' || buffer[i] > '9')
                onlyDigits = false;

        if (strlen(buffer) == 10 && buffer[0] == '0' && onlyDigits)
            valid = true;
        else {
            cout << "invalid phone number, enter again" << endl;
            cin.getline(buffer, 80);

        }
    }



//    phoneNumber = new char[strlen(buffer) + 1];
//    strcpy(phoneNumber, buffer);







//    while (!valid) {
//        for (int i = 0; buffer[i] != '\0'; ++i)
//            if(buffer[i] < '0' || buffer[i] > '9')
//                onlyDigits = false;
//
//        if(strlen(buffer) == 9 && onlyDigits)
//            valid = true;
//        else{
//            cout << "invalid id, try again" << endl;
//            cin.getline(buffer, 80);
//        }
//
//    }
//    cout << buffer;
////    id = new char[strlen(buffer) + 1];
////    strcpy(id, buffer);

}


int main() {


//    set_birth_datee();


//    set_passwords();

//char h[20] = "hod aya";
//if(checkFirstNameAndLastName(h))
//    cout << "valid\n";
//else
//    cout << "---------not valid\n";

//if(checkValidDate(23,1,2024))
//    cout << "valid\n";
//else
//    cout << "---------not valid\n";

    Administrator a;
    a.enterSystem();
//    a.print();


/*

CV:
098765432 #summary# sum  #experience# poiu  #education# oiuy  #licenses# jhytg  #skills# uytrd  #awards# uytr  #name# TOM  #email# tom@ll.il  #endl#

098765432 #summary# none  #experience# none  #education# none  #licenses# none  #skills# none  #awards# none  #name# Adam  #email# adam.co@gmail.com  #endl#
098765432 4  9  26  27  3  7  endl
c 098765432 9909 hodaya shirazie 0987786756 0547337292 98/8/990
 098765432 4  endl

-personal details-
 c 213445665 WQ1212wq Jhon mark jhon-t1994@gmail.org 0546657867 12.3.1994 hi there, I'm John, on a job portal seeking my next tech challenge. With my profile updated and applications sent, I'm ready for the next big step in my career.
e 098765432 Qq112211 adam levi adam@gmail.com 0987786755

 -------cv----
 213445665 #summary# none #experience# Junior Software Developer, Tech Innovations Inc., 2019-2021. Worked on developing and maintaining high-traffic web applications. #education# B.Sc. in Computer Science, University of Tech, 2019 #licenses# Licensed Professional Engineer (P.E.), Civil Engineering, Board of Professional Engineers, License #12345, Acquired 2022 #skills# Languages: Java, Python, JavaScript #awards# Tools: Git, Docker, Jenkins #name# Jhon mark #email# jhon-t1994@gmail.org #endl#



 */


    return 0;
}



