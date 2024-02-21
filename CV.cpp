//
// Created by Student on 14/02/2024.
//
#define SIZE_STRING 600
#include "CV.h"
#include <iostream>
#include <cstring>
#include <windows.h>


//using std::string;
using std::cout;
using std::cin;
using std::endl;

void setConsoleColor(WORD c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

CV::CV(){}

CV :: CV(char* summary, char* experience, char* education, char* licenses, char* skills, char* awards, char* name, char* email)
{
    this->summary = new char[strlen(summary) + 1];
    strcpy(this->summary,summary);

    this->experience = new char[strlen(experience) + 1];
    strcpy(this->experience,experience);

    this->education = new char[strlen(education) + 1];
    strcpy(this->education,education);

    this->licenses = new char[strlen(licenses) + 1];
    strcpy(this->licenses,licenses);

    this->skills = new char[strlen(skills) + 1];
    strcpy(this->skills,skills);

    this->awards = new char[strlen(awards) + 1];
    strcpy(this->awards,awards);

    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);

    this->email = new char[strlen(email) + 1];
    strcpy(this->email,email);

}

//constructor
CV::CV(char* name, char* email) {

    //initialize name and email
    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);

    this->email = new char[strlen(email) + 1];
    strcpy(this->email,email);

    //initialize strings to "none"
    summary=NULL;
    experience=NULL;
    education=NULL;
    licenses=NULL;
    skills=NULL;
    awards=NULL;

    createCV();
}

//distractor
CV::~CV()
{
    //dis-allocating memory
   delete [] summary;
   delete [] experience;
   delete [] education;
   delete [] licenses;
   delete [] skills;
   delete [] awards;
   delete [] name;
   delete [] email;
   summary = NULL;
   experience = NULL;
   education = NULL;
   licenses = NULL;
   skills = NULL;
   awards = NULL;
   name = NULL;
   email = NULL;
//   cout <<"dis CV" <<endl;

}

CV::CV(const CV& cv)
{
    summary = NULL;
    experience = NULL;
    education = NULL;
    licenses = NULL;
    skills = NULL;
    awards = NULL;
    name = NULL;
    email = NULL;
    *this = cv; //call operator=
}

//opertaor=
CV& CV:: operator=(const CV& cv) {
    //dis-allocating memory
    delete[] summary;
    delete[] experience;
    delete[] education;
    delete[] licenses;
    delete[] skills;
    delete[] awards;
    delete[] name;
    delete[] email;

    //coping
    summary = new char[strlen(cv.summary) + 1];
    strcpy(summary, cv.summary);

    experience = new char[strlen(cv.experience) + 1];
    strcpy(experience, cv.experience);

    education = new char[strlen(cv.education) + 1];
    strcpy(education, cv.education);

    licenses = new char[strlen(cv.licenses) + 1];
    strcpy(licenses, cv.licenses);

    skills = new char[strlen(cv.skills) + 1];
    strcpy(skills, cv.skills);

    awards = new char[strlen(cv.awards) + 1];
    strcpy(awards, cv.awards);

    name = new char[strlen(cv.name) + 1];
    strcpy(name, cv.name);

    email = new char[strlen(cv.email) + 1];
    strcpy(email, cv.email);
}



void CV:: createCV()
{
    delete[] summary;
    delete[] experience;
    delete[] education;
    delete[] licenses;
    delete[] skills;
    delete[] awards;

    char tmp [SIZE_STRING];
    cout << "enter the following requests, if you dont want to- enter none"<<endl;

    cout << "summary" << endl;
    cin.getline(tmp,SIZE_STRING);
    summary = new char[strlen(tmp) + 1];
    strcpy(summary, tmp);



    cout << "experience" << endl;
    cin.getline(tmp,SIZE_STRING);
    experience = new char[strlen(tmp) + 1];
    strcpy(experience, tmp);



    cout << "education" << endl;
    cin.getline(tmp,SIZE_STRING);
    education = new char[strlen(tmp) + 1];
    strcpy(education, tmp);



    cout << "licenses" << endl;
    cin.getline(tmp,SIZE_STRING);
    licenses = new char[strlen(tmp) + 1];
    strcpy(licenses, tmp);


    cout << "skills" << endl;
    cin.getline(tmp,SIZE_STRING);
    skills = new char[strlen(tmp) + 1];
    strcpy(skills, tmp);


    cout << "awards" << endl;
    cin.getline(tmp,SIZE_STRING);
    awards = new char[strlen(tmp) + 1];
    strcpy(awards, tmp);

}

//print cv
void CV:: print ()const
{
    //print only if field is not "none"

    setConsoleColor( FOREGROUND_BLUE );
    cout << "name " << endl;
    setConsoleColor(7);
    cout << name << endl;

    setConsoleColor( FOREGROUND_BLUE);
    cout << "email " << endl;
    setConsoleColor(7);
    cout << email << endl << endl << endl;

    if(strcmp(summary, "none") != 0) {
        setConsoleColor(FOREGROUND_BLUE);
        cout << "summary " << endl;
        setConsoleColor(7);
        cout << summary << endl << endl;
    }

    if(strcmp(experience, "none") != 0) {
        setConsoleColor(FOREGROUND_BLUE);
        cout << "experience " << endl;
        setConsoleColor(7);
        cout << experience << endl << endl;
    }
    if(strcmp(education, "none") != 0) {
        setConsoleColor(FOREGROUND_BLUE);
        cout << "education " << endl;
        setConsoleColor(7);
        cout << education << endl << endl;
    }

    if(strcmp(licenses, "none") != 0) {
        setConsoleColor(FOREGROUND_BLUE);
        cout << "licenses " << endl;
        setConsoleColor(7);
        cout << licenses << endl << endl;
    }

    if(strcmp(skills, "none") != 0) {
        setConsoleColor(FOREGROUND_BLUE);
        cout << "skills " << endl;
        setConsoleColor(7);
        cout << skills << endl << endl;
    }

    if(strcmp(awards, "none") != 0) {
        setConsoleColor(FOREGROUND_BLUE);
        cout << "awards " << endl;
        setConsoleColor(7);
        cout << awards << endl << endl;
    }



}

char *CV::getSummary() const {
    return summary;
}

char *CV::getExperience() const {
    return experience;
}

char *CV::getEducation() const {
    return education;
}

char *CV::getLicenses() const {
    return licenses;
}

char *CV::getSkills() const {
    return skills;
}

char *CV::getAwards() const {
    return awards;
}

char *CV::getName() const {
    return name;
}

char *CV::getEmail() const {
    return email;
}
