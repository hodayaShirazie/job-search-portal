//
// Created by Student on 14/02/2024.
//
#define SIZE_STRING 3100
#include "CV.h"
#include <iostream>
#include <cstring>
#include "Colors.h"

enum editCV{SUMMARY = '1', EXPERIENCE = '2', EDUCATION = '3', LICENSES = '4', SKILLS = '5', AWARDS = '6', BACK_E_P = '7'};


//using std::string;
using std::cout;
using std::cin;
using std::endl;



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


void CV:: createCV() {

    cout << "build your CV, to skip- enter none" << endl;


    setSummary();

    setExperience();

    setEducation();

    setLicenses();

    setSkills();

    setAwards();


}

//print cv
void CV:: print ()const
{

    Colors color;
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "name " << endl;
    color.setConsoleColor(7);
    cout << name << endl;

    color.setConsoleColor( FOREGROUND_BLUE);
    cout << "email " << endl;
    color.setConsoleColor(7);
    cout << email << endl << endl << endl;

    if(strcmp(summary, "none") != 0) {
        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "summary " << endl;
        color.setConsoleColor(7);
        cout << summary << endl << endl;
    }

    if(strcmp(experience, "none") != 0) {
        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "experience " << endl;
        color.setConsoleColor(7);
        cout << experience << endl << endl;
    }
    if(strcmp(education, "none") != 0) {
        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "education " << endl;
        color.setConsoleColor(7);
        cout << education << endl << endl;
    }

    if(strcmp(licenses, "none") != 0) {
        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "licenses " << endl;
        color.setConsoleColor(7);
        cout << licenses << endl << endl;
    }

    if(strcmp(skills, "none") != 0) {
        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "skills " << endl;
        color.setConsoleColor(7);
        cout << skills << endl << endl;
    }

    if(strcmp(awards, "none") != 0) {
        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "awards " << endl;
        color.setConsoleColor(7);
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




void CV:: setName(char* name)
{
    delete [] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

}

void CV:: setEmail(char* email)
{
    delete [] this->email;
    this->email = new char[strlen(email) + 1];
    strcpy(this->email,email);
}


void CV::  change_cv()
{

    char nav_edit_cv;
    do {
        Colors color;
        color.setConsoleColor( FOREGROUND_RED );
        cout << "1";
        color.setConsoleColor(7);
        cout << "- summary \n";

        color.setConsoleColor( FOREGROUND_RED );
        cout << "2";
        color.setConsoleColor(7);
        cout << "- experience \n";

        color.setConsoleColor( FOREGROUND_RED );
        cout << "3";
        color.setConsoleColor(7);
        cout << "- education \n";


        color.setConsoleColor( FOREGROUND_RED );
        cout << "4";
        color.setConsoleColor(7);
        cout << "- licenses \n";


        color.setConsoleColor( FOREGROUND_RED );
        cout << "5";
        color.setConsoleColor(7);
        cout << "- skills \n";


        color.setConsoleColor( FOREGROUND_RED );
        cout << "6";
        color.setConsoleColor(7);
        cout << "- awards \n";

        color.setConsoleColor( FOREGROUND_RED );
        cout << "7";
        color.setConsoleColor(7);
        cout << "- back to edit profile \n";


        cin >> nav_edit_cv;

        if (nav_edit_cv != '1' && nav_edit_cv != '2' && nav_edit_cv != '3' && nav_edit_cv != '4' && nav_edit_cv != '5' && nav_edit_cv != '6' && nav_edit_cv != '7') {
            cin.clear(); // Clears the error flag on cin.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            {
                Colors color;
                color.setConsoleColor( FOREGROUND_RED);
                cout << "invalid input, try again\n";
                color.setConsoleColor(7);
            }
        }

        switch (nav_edit_cv) {
            case SUMMARY: {
                cin.ignore();
                setSummary();
                break;

            }
            case EXPERIENCE: {
                cin.ignore();
                setExperience();
                break;

            }
            case EDUCATION: {
                cin.ignore();
                setEducation();
                break;

            }
            case LICENSES: {
                cin.ignore();
                setLicenses();
                break;

            }
            case SKILLS: {
                cin.ignore();
                setSkills();
                break;

            }
            case AWARDS: {
                cin.ignore();
                setAwards();
                break;

            }
            case BACK_E_P: {
//                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            }
            default:{
//                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //if input is not one of the above - do nothing and print menu again
            };

        }
    }while (nav_edit_cv != BACK_E_P);



}



void CV::setSummary() {//TODO handle when input above 600 chars


    char tmp [SIZE_STRING];
    delete[] summary;
//    cin.ignore();

    bool tooLong = false;

    Colors color;
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "summary" << endl;
    color.setConsoleColor(7);

    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "to skip, enter \"none\"" << endl;
    color.setConsoleColor(7);

    while(!tooLong) {
        cin.getline(tmp, 3100);

        if (std::cin.fail()) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (strlen(tmp) > 3000)
        {
            color.setConsoleColor( FOREGROUND_RED);
            cout << "summary is too long! try again\n";
            color.setConsoleColor(7);
        }
        else
            tooLong = true;
    }


    summary = new char[strlen(tmp) + 1];
    strcpy(summary, tmp);



}

void CV::setExperience() {

    char tmp [SIZE_STRING];
    delete [] experience;
//    cin.ignore();


    bool tooLong = false;


    Colors color;
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "experience" << endl;
    color.setConsoleColor(7);

    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "to skip, enter \"none\"" << endl;
    color.setConsoleColor(7);

    while(!tooLong) {
        cin.getline(tmp, 3100);

        if (std::cin.fail()) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (strlen(tmp) > 3000)
        {
            color.setConsoleColor( FOREGROUND_RED);
            cout << "experience is too long! try again\n";
            color.setConsoleColor(7);
        }
        else
            tooLong = true;
    }

    experience = new char[strlen(tmp) + 1];
    strcpy(experience, tmp);

}

void CV::setEducation() {
    char tmp [SIZE_STRING];
    delete [] education;
//    cin.ignore();


    bool tooLong = false;

    Colors color;
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "education" << endl;
    color.setConsoleColor(7);

    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "to skip, enter \"none\"" << endl;
    color.setConsoleColor(7);

    while(!tooLong) {
        cin.getline(tmp, 3100);

        if (std::cin.fail()) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (strlen(tmp) > 3000)
        {
            color.setConsoleColor( FOREGROUND_RED);
            cout << "education is too long! try again\n";
            color.setConsoleColor(7);
        }
        else
            tooLong = true;
    }

    education = new char[strlen(tmp) + 1];
    strcpy(education, tmp);

}

void CV::setLicenses() {
    char tmp [SIZE_STRING];
    delete [] licenses;
//    cin.ignore();



    bool tooLong = false;

    Colors color;
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "licenses" << endl;
    color.setConsoleColor(7);

    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "to skip, enter \"none\"" << endl;
    color.setConsoleColor(7);

    while(!tooLong) {
        cin.getline(tmp, 3100);

        if (std::cin.fail()) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (strlen(tmp) > 3000)
        {
            color.setConsoleColor( FOREGROUND_RED);
            cout << "licenses is too long! try again\n";
            color.setConsoleColor(7);
        }
        else
            tooLong = true;
    }

    licenses = new char[strlen(tmp) + 1];
    strcpy(licenses, tmp);

}

void CV::setSkills() {
    char tmp [SIZE_STRING];
    delete[] skills;
//    cin.ignore();

    bool tooLong = false;
    Colors color;
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "skills" << endl;
    color.setConsoleColor(7);

    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "to skip, enter \"none\"" << endl;
    color.setConsoleColor(7);

    while(!tooLong) {
        cin.getline(tmp, 3100);

        if (std::cin.fail()) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (strlen(tmp) > 3000)
        {
            color.setConsoleColor( FOREGROUND_RED);
            cout << "skills is too long! try again\n";
            color.setConsoleColor(7);
        }
        else
            tooLong = true;
    }

    skills = new char[strlen(tmp) + 1];
    strcpy(skills, tmp);

}

void CV::setAwards() {
    char tmp [SIZE_STRING];
    delete[] awards;
//    cin.ignore();

    bool tooLong = false;

    Colors color;
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "awards" << endl;
    color.setConsoleColor(7);

    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "to skip, enter \"none\"" << endl;
    color.setConsoleColor(7);

    while(!tooLong) {
        cin.getline(tmp, 3100);

        if (std::cin.fail()) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (strlen(tmp) > 3000) {
            color.setConsoleColor( FOREGROUND_RED);
            cout << "awards is too long! try again\n";
            color.setConsoleColor(7);

        }
        else
            tooLong = true;
    }

    awards = new char[strlen(tmp) + 1];
    strcpy(awards, tmp);
}
