//
// Created by Student on 14/02/2024.
//
#include "Employer.h"
#include <iostream>
#include <cstring>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ios;


Employer :: Employer(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate)
{
    this->id = new char[strlen(id) + 1];
    strcpy(this->id,id);

    this->userName = new char[strlen(userName) + 1];
    strcpy(this->userName,userName);

    this->email = new char[strlen(email) + 1];
    strcpy(this->email,email);

    this->phoneNumber = new char[strlen(phoneNumber) + 1];
    strcpy(this->phoneNumber,phoneNumber);

    this->birthDate = new char[strlen(birthDate) + 1];
    strcpy(this->birthDate,birthDate);


}

//TODO check that name includes space, valid pass, valid date
Employer::Employer()
{

    char buffer[80];
    cin.ignore();

    //getting user-name
    cout << "username" << endl;
    cin.getline(buffer,80);
    while(strlen(buffer) > 20) {
        cout << "user name is up to 20 letters, try again" << endl;
        cin.getline(buffer,80);
    }
    userName = new char[strlen(buffer) + 1];
    strcpy(userName,buffer);

//    cin.ignore();
    //getting user id
    cout << "id" << endl;
    cin.getline(buffer,80);
    while(strlen(buffer) != 9) {
        cout << "invalid id, try again" << endl;
        cin.getline(buffer,80);
    }
    id = new char[strlen(buffer) + 1];
    strcpy(id,buffer);


    //getting user email
    cout << "email" << endl;
    cin.getline(buffer, 80);

    bool existsSign = false;
    bool validChar = true;
    bool invalidProfix = false;
    while (!validChar || !invalidProfix || !existsSign) {

        int lenEmail = strlen(buffer);

        //if email does not end with .org/.com/.il
        if ((buffer[lenEmail - 1] == 'm' && buffer[lenEmail - 2] == 'o' && buffer[lenEmail - 3] == 'c' &&
                buffer[lenEmail - 4] == '.')
            || (buffer[lenEmail - 1] == 'g' && buffer[lenEmail - 2] == 'r' && buffer[lenEmail - 3] == 'o' &&
                buffer[lenEmail - 4] == '.') ||
                (buffer[lenEmail - 1] == 'l' && buffer[lenEmail - 2] == 'i' && buffer[lenEmail - 3] == '.'))
            invalidProfix = true;


        //if email contains invalid characters
        for (int i = 0; buffer[i] != '\0' && validChar && invalidProfix; ++i)
        {
            if (!(buffer[i] >= 'a' && buffer[i] <= 'z' || buffer[i] >= 'A' && buffer[i] <= 'Z'))
                if (!(buffer[i] >= '0' && buffer[i] <= '9'))
                    if (!(buffer[i] == '-' || buffer[i] == '.'))
                        if (!(buffer[i] == '@')) {
                            validChar = false; //email is not valid
                        }else
                            existsSign = true;

        }
        if (!validChar || !invalidProfix || !existsSign) {
            cout << "invalid email, enter again" << endl;
            cin.getline(buffer, 80);
        }

    }

    email = new char[strlen(buffer) + 1];
    strcpy(email, buffer);


    //getting phone number
    cout << "phone number" << endl;
    cin.getline(buffer, 80);
    while(strlen(buffer) != 10 || buffer[0] != '0')
    {
        cout << "invalid phone number, enter again" << endl;
        cin.getline(buffer, 80);
    }
    phoneNumber = new char[strlen(buffer) + 1];
    strcpy(phoneNumber, buffer);

    //getting birth date
    cout << "birthDate" << endl;
    cin.getline(buffer,80);

    //TODO check validation

    birthDate = new char[strlen(buffer) + 1];
    strcpy(birthDate, buffer);

    //getting password
    cout << "password" << endl;
    cin.getline(buffer,80);

    //TODO check validation

    password = new char[strlen(buffer) + 1];
    strcpy(password, buffer);


//    //save registeration details in txt file
//    fstream file;
//    file.open("C:\\ObjectOrientedProgramming\\jobSearch\\personalDetails.txt\\",ios::app);
//    if(!file.is_open()) {
//        cout << "file could not be opened, check error" << endl;
//    }else{
//        file << "e " << id << " " << password << " " << userName << " " << email << " " << phoneNumber << " " << birthDate << endl;
//        file.close();
//    }


    cout << "create account" << endl;


}

Employer :: ~Employer()
{

    //copy all candidate details to "personalDetails" file
    fstream file;
    file.open("C:\\ObjectOrientedProgramming\\jobSearch\\personalDetails.txt",ios::app);
    if(!file.is_open()) {
        cout << "file could not be opened, check error" << endl;
    }else{
        file << "e " << id << " " << password << " " << userName << " " << email << " " << phoneNumber << " " << birthDate << endl;
        file.close();
    }



    delete [] userName;
    delete [] id;
    delete [] email;
    delete [] phoneNumber;
    delete [] birthDate;
    delete [] password;
}

char *Employer::getUserName() const {
    return userName;
}

char *Employer::getId() const {
    return id;
}

char *Employer::getEmail() const {
    return email;
}

char *Employer::getPhoneNumber() const {
    return phoneNumber;
}

char *Employer::getBirthDate() const {
    return birthDate;
}

char *Employer::getPassword() const {
    return password;
}

