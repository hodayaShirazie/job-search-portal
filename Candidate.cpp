//
// Created by Student on 14/02/2024.
//

#include "Candidate.h"

enum personalAreaCandidate{EDIT_PROFILE = '1', ALL_JOBS = '2', FILTER_JOBS = '3', JOBS_I_LIKED = '4', SUBMISSION_HISTORY_C = '5'};
enum editProfileCandidate{USER_NAME_C = '1', EMAIL_C = '2', PHONE_NUMBER_C = '3', PASSWORD_C = '4', CV_C = '5'};


Candidate :: ~Candidate()
{

    fstream file_personal_details, file_cv;
    file_personal_details.open("C:\\ObjectOrientedProgramming\\jobSearch\\personalDetails.txt",ios::app);
    if(!file_personal_details.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {
        //copy all candidate details to "personalDetails" file
        file_personal_details << endl << "c " << id << " " << password << " " << userName << " " << email << " " << phoneNumber << " " << birthDate << " " << freeTxt;
        file_personal_details.close();

        //copy CV to
        file_cv.open("C:\\ObjectOrientedProgramming\\jobSearch\\CV.txt",ios::app);
        if(!file_cv.is_open())
            cout << "file could not be opened, check error" << endl;
        else
        {
            file_cv << id << " summary " << cv->getSummary() << " experience " << cv->getExperience() << " education " << cv->getEducation() << " licenses " <<
            cv->getLicenses() << " skills " << cv->getSkills() << " awards " << cv->getAwards() << " name " <<
                                        cv->getName() << " email " << cv->getEmail()  << " endl " << endl;

            file_cv.close();
        }

    }


    //dis-allocating memory
    delete [] userName;
    delete [] id;
    delete [] email;
    delete [] phoneNumber;
    delete [] birthDate;
    delete [] password;
    delete [] freeTxt;
    delete cv;


}


//constructor
Candidate :: Candidate(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate, char* freeTxt):cv(NULL)
{

    this->id = new char[strlen(id) + 1];
    strcpy(this->id,id);

    this->password = new char[strlen(password) + 1];
    strcpy(this->password,password);

    this->userName = new char[strlen(userName) + 1];
    strcpy(this->userName,userName);

    this->email = new char[strlen(email) + 1];
    strcpy(this->email,email);

    this->phoneNumber = new char[strlen(phoneNumber) + 1];
    strcpy(this->phoneNumber,phoneNumber);

    this->birthDate = new char[strlen(birthDate) + 1];
    strcpy(this->birthDate,birthDate);

    this->freeTxt = new char[strlen(freeTxt) + 1];
    strcpy(this->freeTxt,freeTxt);

}


//constructor
 Candidate :: Candidate() : userName(NULL), id(NULL), email(NULL), phoneNumber(NULL), birthDate(NULL), password(NULL),freeTxt(NULL)
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

     char tempFt[501];
     cout << "add free text to tell about yourself, if you dont want- enter none" << endl;
     cin.getline(tempFt,501);
     freeTxt = new char[strlen(tempFt) + 1];
     strcpy(freeTxt, tempFt);

     //add cv
     cv = new CV(userName,email);


     cout << "create account" << endl;



}

Candidate :: Candidate(const Candidate& candidate): userName(NULL), id(NULL), email(NULL), phoneNumber(NULL), birthDate(NULL), password(NULL), freeTxt(NULL)
{
    *this = candidate;
}


Candidate& Candidate :: operator=(const Candidate& candidate)
{
    //dis-allocating memory
    delete [] userName;
    delete [] id;
    delete [] email;
    delete [] phoneNumber;
    delete [] birthDate;
    delete [] password;
    delete [] freeTxt;
    delete cv;

    //copy values to fields
    userName = new char[strlen(candidate.userName) + 1];
    strcpy(userName, candidate.userName);

    id = new char[strlen(candidate.id) + 1];
    strcpy(id, candidate.id);

    email = new char[strlen(candidate.email) + 1];
    strcpy(email, candidate.email);

    phoneNumber = new char[strlen(candidate.phoneNumber) + 1];
    strcpy(phoneNumber, candidate.phoneNumber);

    birthDate = new char[strlen(candidate.birthDate) + 1];
    strcpy(birthDate, candidate.birthDate);

    password = new char[strlen(candidate.password) + 1];
    strcpy(password, candidate.password);

    userName = new char[strlen(candidate.freeTxt) + 1];
    strcpy(freeTxt, candidate.freeTxt);

    cv = new CV(*candidate.cv);

    return *this;

}



void Candidate :: personalArea()
{
    char nav_personal_area;
    cout << "1- edit profile \n";
    cout << "2- all jobs \n";
    cout << "3- filter jobs \n";
    cout << "4- jobs i liked \n";
    cout << "5- submission history \n";
    cin >> nav_personal_area;
    
    switch(nav_personal_area){
        case EDIT_PROFILE: {
            char nav_edit_profile;
            cout << "1- user name \n";
            cout << "2- email \n";
            cout << "3- phone number \n";
            cout << "4- password \n";
            cout << "5- cv \n";
            cin >> nav_personal_area;

            switch (nav_edit_profile) {
                case USER_NAME_C:
                {
                    set_user_name();
                }
                case EMAIL_C:
                {
                    set_email();
                }
                case PHONE_NUMBER_C:
                {
                    set_phone_number();
                }
                case PASSWORD_C:
                {
                    set_password();
                }
                case CV_C:
                {


                }
                
            }
            
            

            break;
        }
        case ALL_JOBS: {

            break;
        }
        case FILTER_JOBS: {

            break;
        }
        case JOBS_I_LIKED: {

            break;
        }
        case SUBMISSION_HISTORY_C: {

            break;
        }
    }
}


void Candidate :: set_user_name()
{
    delete [] userName;

    char buffer[80];
    cin.ignore();
    
    //getting user-name
    cout << "username" << endl;
    cin.getline(buffer,80);
    //if input is valid
    while(strlen(buffer) > 20) {
        cout << "user name is up to 20 letters, try again" << endl;
        cin.getline(buffer,80);
    }
    userName = new char[strlen(buffer) + 1];
    strcpy(userName,buffer);
}


void Candidate::set_email()
{
    char buffer[80];
    cin.ignore();
    delete [] email;

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

}


void Candidate :: set_phone_number()
{
    char buffer[80];
    cin.ignore();

    delete [] phoneNumber;
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
}


void Candidate::set_password()
{
    char buffer[80];
    cin.ignore();

    delete [] password;
    password = new char[strlen(buffer) + 1];
    strcpy(password, buffer);

}

void Candidate:: set_cv(CV *cv)
{
    this->cv = cv;
}


char *Candidate::getUserName() const {
    return userName;
}

char *Candidate::getId() const {
    return id;
}

char *Candidate::getEmail() const {
    return email;
}

char *Candidate::getPhoneNumber() const {
    return phoneNumber;
}

char *Candidate::getBirthDate() const {
    return birthDate;
}

char *Candidate::getPassword() const {
    return password;
}

CV *Candidate::getCv() const {
    return cv;
}


void Candidate:: print() const
{
    cout << "user name: " << userName <<endl;

    cout << "id: " << id <<endl;

    cout << "email: " << email <<endl;

    cout << "phoneNumber: " << phoneNumber <<endl;

    cout << "birthDate: " << birthDate <<endl;

    cout << "password: " << password <<endl;

    cout << "freeTxt: " << freeTxt <<endl;

    //printing CV's
    cout << "printing CV's \n";
    cv->print();



}

