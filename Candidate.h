//
// Created by Student on 14/02/2024.
//
//#include <string>
#include <iostream>
#include "Date.h"
#include "CV.h"
#include <fstream>
#include <cstring>


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ios;



#ifndef JOBSEARCH_CANDIDATE_H
#define JOBSEARCH_CANDIDATE_H


class Candidate {
public:

    Candidate();

    Candidate(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate, char* freeTxt);

    ~Candidate();

    Candidate& operator=(const Candidate& candidate);

    Candidate(const Candidate& candidate);

    void personalArea();

    void set_user_name();

    char *getUserName() const;

    char *getId() const;

    char *getEmail() const;

    char *getPhoneNumber() const;

    char *getBirthDate() const;

    char *getPassword() const;

    CV *getCv() const;

    void set_email();

    void set_phone_number();

    void set_password();

    void set_cv(CV *cv);

    void print() const;







private:
    char* userName;
    char* id;
    char* email;
    char* phoneNumber;
    char* birthDate;
    char* password;
    char* freeTxt;
    CV *cv;

};





#endif //JOBSEARCH_CANDIDATE_H
