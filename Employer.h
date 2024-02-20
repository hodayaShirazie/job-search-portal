//
// Created by Student on 14/02/2024.
//

#ifndef JOBSEARCH_EMPLOYER_H
#define JOBSEARCH_EMPLOYER_H


class Employer {
public:
    Employer();

    Employer(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate);

    char *getUserName() const;

    char *getId() const;

    char *getEmail() const;

    char *getPhoneNumber() const;

    char *getBirthDate() const;

    char *getPassword() const;

    void print() const;


        ~Employer();
private:
    char *userName;
    char* id;
    char* email;
    char* phoneNumber;
    char* birthDate;
    char* password;

};


#endif //JOBSEARCH_EMPLOYER_H
