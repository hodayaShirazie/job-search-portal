//
// Created by Student on 14/02/2024.
//

#include "Candidate.h"
#include "Job.h"


//constructor with parameters
Candidate :: Candidate(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate, char* freeTxt):cv(NULL),all_jobs_arr(NULL), all_jobs_arr_size(0),wasCVcopied(false),wasPDcopied(false),wasLikedCopied(false),wasSubmittedCopied(false)
{
    copyAllJobsFromFile();

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

    updateLikedStatusFromFile();


}


//constructor with no parameters
 Candidate :: Candidate() : userName(NULL), id(NULL), email(NULL), phoneNumber(NULL), birthDate(NULL), password(NULL),freeTxt(NULL),all_jobs_arr_size(0), all_jobs_arr(NULL),wasCVcopied(false),wasPDcopied(false),wasLikedCopied(false),wasSubmittedCopied(false) {

    //copy jobs from file
    copyAllJobsFromFile();

    //getting user-name
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    set_user_name();

    //getting user id
    set_id();

    //getting user email
    set_email();

    //getting phone number
    set_phone_number();

    //getting birthdate
    set_birth_date();

    //getting password
    set_password();


    //getting free text
    set_free_text();



    //add cv
    cv = new CV(userName, email);

}


//distructor
Candidate :: ~Candidate()
{

    copyPersonalDetailsToFile();

    copyCVToFile();

    copySubmittedJobsToFile();

    copyLikedJobsToFile();



    //dis-allocating memory
    delete [] userName;
    delete [] id;
    delete [] email;
    delete [] phoneNumber;
    delete [] birthDate;
    delete [] password;
    delete [] freeTxt;
    delete cv;

    userName = NULL;
    id = NULL;
    email = NULL;
    phoneNumber = NULL;
    birthDate = NULL;
    password = NULL;
    freeTxt = NULL;
    cv = NULL;



    for (int i = 0; i < all_jobs_arr_size; ++i) {
        delete all_jobs_arr[i];
        all_jobs_arr[i] = NULL;
    }
    delete [] all_jobs_arr;
    all_jobs_arr = NULL;
    all_jobs_arr_size = 0;

}


//copy constructor
Candidate :: Candidate(const Candidate& candidate): userName(NULL), id(NULL), email(NULL), phoneNumber(NULL), birthDate(NULL), password(NULL), freeTxt(NULL),all_jobs_arr(NULL),all_jobs_arr_size(0)
{
    *this = candidate;
}


//operator=
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


//person area
void Candidate :: personalArea()
{

    char nav_personal_area = '\0';


    while(nav_personal_area != Exit_C) {

        Colors color;

        color.enableVirtualTerminalProcessing();

        color.setColorANSI(33);
        cout << "1";
        color.setColorANSI(39);
        cout << "- edit profile \n";

        color.setColorANSI(33);
        cout << "2";
        color.setColorANSI(39);
        cout << "- all jobs \n";

        color.setColorANSI(33);
        cout << "3";
        color.setColorANSI(39);
        cout << "- filter jobs \n";

        color.setColorANSI(33);
        cout << "4";
        color.setColorANSI(39);
        cout << "- submit job \n";

        color.setColorANSI(33);
        cout << "5";
        color.setColorANSI(39);
        cout << "- like job \n";

        color.setColorANSI(33);
        cout << "6";
        color.setColorANSI(39);
        cout << "- submission history \n";

        color.setColorANSI(33);
        cout << "7";
        color.setColorANSI(39);
        cout << "- log out \n";

        cin >> nav_personal_area;

        if (nav_personal_area != '1' && nav_personal_area != '2' && nav_personal_area != '3' && nav_personal_area != '4' && nav_personal_area != '5' && nav_personal_area != '6' && nav_personal_area != '7') {
            cin.clear(); // Clears the error flag on cin.
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (nav_personal_area) {
            case EDIT_PROFILE: {
                char nav_edit_profile;

                do {

                    Colors color;


                    color.setColorANSI(33);
                    cout << "1";
                    color.setColorANSI(0);
                    cout << "- user name \n";

                    color.setColorANSI(33);
                    cout << "2";
                    color.setColorANSI(0);
                    cout << "- email \n";

                    color.setColorANSI(33);
                    cout << "3";
                    color.setColorANSI(0);
                    cout << "- phone number \n";

                    color.setColorANSI(33);
                    cout << "4";
                    color.setColorANSI(0);
                    cout << "- password \n";

                    color.setColorANSI(33);
                    cout << "5";
                    color.setColorANSI(0);
                    cout << "- cv \n";

                    color.setColorANSI(33);
                    cout << "6";
                    color.setColorANSI(0);
                    cout << "- update \n";

                    cin >> nav_edit_profile;

                    if (nav_edit_profile != '1' && nav_edit_profile != '2' && nav_edit_profile != '3' && nav_edit_profile != '4' && nav_edit_profile != '5' && nav_edit_profile != '6') {
                        cin.clear(); // Clears the error flag on cin.
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }

                    switch (nav_edit_profile) {
                        case USER_NAME_C: {
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            set_user_name();
                            cv->setName(userName); //change name in cv
                            break;
                        }
                        case EMAIL_C: {
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            set_email();
                            cv->setEmail(email); //change email in cv
                            break;

                        }
                        case PHONE_NUMBER_C: {
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            set_phone_number();
                            break;

                        }
                        case PASSWORD_C: {
                            set_password();
                            break;

                        }
                        case CV_C: {
                            cv->change_cv();
                            break;

                        }
                        case UPDATE_P_C: {
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;

                        }
                        default:{
                            Colors color;
                            //if input is not one of the above - do nothing and print menu again
                            color.setColorANSI(31);
                            cout<< "invalid input, try again\n";
                            color.setColorANSI(0);

                        };

                    }
                }while (nav_edit_profile != UPDATE_P_C);


                break;
            }


            case ALL_JOBS: {
                printAllJobsArr();
                break;
            }
            case FILTER_JOBS: {
                filterJobsByFeatures();
                break;
            }
            case SUBMIT_JOB: {
                submit_job();
                break;
            }

            case LIKE_A_JOB: {

                char nav_like_job;
                Colors color;


                color.setColorANSI(33);
                cout << "1";
                color.setColorANSI(0);
                cout << "- like a job \n";

                color.setColorANSI(33);
                cout << "2";
                color.setColorANSI(0);
                cout << "- un-like a job \n";


                color.setColorANSI(33);
                cout << "3";
                color.setColorANSI(0);
                cout << "- jobs i liked \n";


                cin >> nav_like_job;

                switch (nav_like_job) {
                    case LIKE_A_JOB_l: {
                        likeJob();
                        break;
                    }
                    case UN_LIKE_A_JOB_l: {
                        unLikeJob();
                        break;
                    }
                    case JOBS_I_LIKED_I: {
                        viewLikedJobs();
                        break;
                    }
                    default:{
                        //if input is not one of the above - do nothing and print menu again
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    };
                }


                break;
            }

            case SUBMISSION_HISTORY_C: {
                viewSubmissionHistory();
                break;
            }
            case Exit_C: {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //end program
                break;
            }

            default:{
                Colors color;
                //if input is not one of the above - do nothing and print menu again
                color.setColorANSI(31);
                cout<< "invalid input, try again\n";
                color.setColorANSI(0);

            };
        }

    }
}


//setters
void Candidate :: set_user_name()
{
    delete [] userName;


//    string newVal;
    char buffer[80];
//    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool validInput = true;


    //getting user-name
    cout << "username" << endl;
    cin.getline(buffer,80);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        validInput = false;
    }


    while (!validInput || strlen(buffer) > 20 || !checkFirstNameAndLastName(buffer)) { //check validation of user name
        Colors color;

        color.setColorANSI(31);
        cout << "invalid input, enter a valid user name"<<endl;
        color.setColorANSI(0);

        cout << "" << endl;
        cin.getline(buffer, 80);

        if (std::cin.fail()) {
            Colors color;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            color.setColorANSI(31);
            cout << "invalid input"<<endl;
            color.setColorANSI(0);

            validInput = false;
        }
        else
            validInput = true;


    }
    userName = new char[strlen(buffer) + 1];
    strcpy(userName, buffer);
}

void  Candidate ::set_id() {

    bool valid = false;
    char buffer[80];
    bool validInput = true;

    cout << "id" << endl;
    cin.getline(buffer, 80);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        validInput = false;
    }


    while (!validInput || !valid) {
        if(validInput) {
            bool onlyDigits = true;
            for (int i = 0; buffer[i] != '\0'; ++i)
                if (buffer[i] < '0' || buffer[i] > '9')
                    onlyDigits = false;


            if (strlen(buffer) == 9 && onlyDigits)
                valid = true;
        }
         if(!validInput || !valid){
             Colors color;

             color.setColorANSI(31);
             cout << "invalid id, try again" << endl;
             color.setColorANSI(0);

            cin.getline(buffer, 80);

            if (std::cin.fail()) {
                Colors color;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                validInput = false;
            }
            else
                validInput = true;

        }

    }

    id = new char[strlen(buffer) + 1];
    strcpy(id, buffer);


}

void Candidate::set_email()
{
    char buffer[80];
    bool validInput = true;
    delete [] email;

    cout << "email" << endl;
    cin.getline(buffer, 80);
    if (std::cin.fail()) {
        Colors color;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        validInput = false;
    }





    bool existsSign = false;
    bool validChar = true;
    bool invalidProfix = false;
    while (!validInput || !validChar || !invalidProfix || !existsSign) {
        if(validInput) {

            int lenEmail = strlen(buffer);

            //if email does not end with .org/.com/.il
            if ((buffer[lenEmail - 1] == 'm' && buffer[lenEmail - 2] == 'o' && buffer[lenEmail - 3] == 'c' &&
                 buffer[lenEmail - 4] == '.')
                || (buffer[lenEmail - 1] == 'g' && buffer[lenEmail - 2] == 'r' && buffer[lenEmail - 3] == 'o' &&
                    buffer[lenEmail - 4] == '.') ||
                (buffer[lenEmail - 1] == 'l' && buffer[lenEmail - 2] == 'i' && buffer[lenEmail - 3] == '.'))
                invalidProfix = true;


            //if email contains invalid characters
            for (int i = 0; buffer[i] != '\0' && validChar && invalidProfix; ++i) {
                if (!(buffer[i] >= 'a' && buffer[i] <= 'z' || buffer[i] >= 'A' && buffer[i] <= 'Z'))
                    if (!(buffer[i] >= '0' && buffer[i] <= '9'))
                        if (!(buffer[i] == '-' || buffer[i] == '.'))
                            if (!(buffer[i] == '@')) {
                                validChar = false; //email is not valid
                            } else
                                existsSign = true;

            }
        }
        if (!validInput || !validChar || !invalidProfix || !existsSign) {
            Colors color;

            color.setColorANSI(31);
            cout << "invalid email, enter again" << endl;
            color.setColorANSI(0);

            cin.getline(buffer, 80);

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                validInput = false;
            }
            else
                validInput = true;

        }

    }

    email = new char[strlen(buffer) + 1];
    strcpy(email, buffer);

}

void Candidate :: set_phone_number() {
    char buffer[80];
    bool validInput = true;


    delete[] phoneNumber;

    bool valid = false;

    cout << "phone number" << endl;
    cin.getline(buffer, 80);
    if (std::cin.fail()) {
        Colors color;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        validInput = false;
    }


    while (!validInput || !valid) {
        if (validInput) {
            bool onlyDigits = true;

            for (int i = 0; buffer[i] != '\0'; ++i)
                if (buffer[i] < '0' || buffer[i] > '9')
                    onlyDigits = false;

            if (strlen(buffer) == 10 && buffer[0] == '0' && onlyDigits)
                valid = true;
        } if(!validInput || !valid){
            Colors color;

            color.setColorANSI(31);
            cout << "invalid phone number, enter again" << endl;
            color.setColorANSI(0);

            cin.getline(buffer, 80);

            if (std::cin.fail()) {
                Colors color;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                color.setColorANSI(31);
                cout << "invalid input" << endl;
                color.setColorANSI(0);

                validInput = false;
            } else
                validInput = true;
        }



    }


    phoneNumber = new char[strlen(buffer) + 1];
    strcpy(phoneNumber, buffer);
}


void Candidate:: set_password()
{
    char buffer[80];
    bool validInput = true;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    delete [] password;

    bool lowerCase = false;
    bool upperCase = false;
    bool valid = false;

    cout << "password" << endl;
    cin.getline(buffer, 80);

    if (std::cin.fail()) {
        Colors color;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        validInput = false;
    }



    while(!validInput || !valid)
    {
        if(validInput) {
            for (int i = 0; buffer[i] != '\0' && !valid; ++i) {
                if (buffer[i] >= 'a' && buffer[i] <= 'z')
                    lowerCase = true;
                else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
                    upperCase = true;

                if (lowerCase && upperCase && strlen(buffer) >= 8)
                    valid = true;
            }
        }
        if(!validInput || !valid)
        {
            Colors color;

            color.setColorANSI(31);
            cout << "password is not valid, try again" << endl;
            color.setColorANSI(0);


            cin.getline(buffer, 80);

            if (std::cin.fail()) {
                Colors color;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                validInput = false;
            } else
                validInput = true;
        }


    }


    password = new char[strlen(buffer) + 1];
    strcpy(password, buffer);

}

void Candidate:: set_birth_date()
{
    delete [] birthDate;
    int d,m,y;
    cout<<"birth-date: enter month, day and year"<<endl;
    bool validInput = true;


    //validate input
    while(!(cin >> m) || !(cin >> d) || !(cin >> y)) //if input is not integer
    {
        Colors color;

        color.setColorANSI(31);
        cout << "Invalid input.try again \n";
        color.setColorANSI(0);


        cin.clear();// Clear the buffer
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignore the rest of the input line to avoid infinite loop
    }

    //validate date
    while(!checkValidDate(d,m,y)) {
        cout<<"invalid date, enter birth-month, birth-day and birth-year"<<endl;
        while(!(cin >> m) || !(cin >> d) || !(cin >> y)) //if input is not integer
        {
            Colors color;
            color.setColorANSI(31);
            cout << "Invalid input.try again \n";
            color.setColorANSI(0);


            cin.clear();// Clear the buffer
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// Ignore the rest of the input line to avoid infinite loop
        }
    }
    char buffer[10] = "";
    strcat(buffer, to_string(m).c_str());
    strcat(buffer, ".");
    strcat(buffer, to_string(d).c_str());
    strcat(buffer, ".");
    strcat(buffer, to_string(y).c_str());


    birthDate = new char[strlen(buffer) + 1];
    strcpy(birthDate, buffer);

}

void Candidate:: set_free_text()
{
    char tempFt[501];
    bool validInput = true;
    Colors color;
    cout << "add free text to tell about yourself\n";


    color.setColorANSI(90);
    cout << "--to skip, enter \"none\"--" << endl;
    color.setColorANSI(0);


    do {
        cin.getline(tempFt, 501);

        if (std::cin.fail()) {
            Colors color;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            color.setColorANSI(31);
            cout << "invalid input, try again" << endl;
            color.setColorANSI(0);

            validInput = false;
        }
        else
            validInput = true;

    } while (!validInput);


    freeTxt = new char[strlen(tempFt) + 1];
    strcpy(freeTxt, tempFt);

}

void Candidate:: set_cv(CV *cv)
{
    this->cv = cv;
}



bool Candidate:: checkValidDate(int day, int month, int year) {

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





//getters
char *Candidate::getId() const {
    return id;
}

char *Candidate::getPassword() const {
    return password;
}

Job **Candidate::getAllJobsArr() const {
    return all_jobs_arr;
}

int Candidate::getAllJobsArrSize() const {
    return all_jobs_arr_size;
}


//function that prints candidate details
void Candidate:: print() const
{
    Colors color;


    color.setColorANSI(90);
    cout << "user name: " << endl;
    color.setColorANSI(0);
    cout << userName <<endl;

    color.setColorANSI(90);
    cout << "id: " << endl;
    color.setColorANSI(0);
    cout << id <<endl;

    color.setColorANSI(90);
    cout << "email: " << endl;
    color.setColorANSI(0);
    cout << email <<endl;

    color.setColorANSI(90);
    cout << "phoneNumber: " << endl;
    color.setColorANSI(0);
    cout << phoneNumber <<endl;

    color.setColorANSI(90);
    cout << "birthDate: " << endl;
    color.setColorANSI(0);
    cout << birthDate <<endl;

    color.setColorANSI(90);
    cout << "password: " << endl;
    color.setColorANSI(0);
    cout << password <<endl;

    color.setColorANSI(90);
    cout << "freeTxt: " << endl;
    color.setColorANSI(0);
    cout << freeTxt <<endl;

    //printing CV's
    color.setColorANSI(90);
    cout << "printing CV's \n";
    color.setColorANSI(0);

    cv->print();



}


void Candidate :: copyAllJobsFromFile() {


    fstream file_jobs;

    char company_name[1000] = "\0";
    char role[1000] = "\0";
    char job_description[1000] = "\0";
    char job_requirements[1000] = "\0";
    char job_type[1000] = "\0";
    char job_condition[1000] = "\0";
    char location[1000] = "\0";
    char date[1000] = "\0";
    char id_j[5] = "\0";
    int d=0,m=0,y=0;

    file_jobs.open("C:\\ObjectOrientedProgramming\\job-search-portal\\jobs.txt", ios::in);
    if (!file_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else {

        while (!file_jobs.eof()) {


                char read_file_jobs[200];
                file_jobs >> read_file_jobs;

                //coping company name
                file_jobs >> read_file_jobs >> read_file_jobs;
                while (!strcmp(read_file_jobs, "#role#") == 0) {
                    strcat(company_name, read_file_jobs);
                    strcat(company_name, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while (!strcmp(read_file_jobs, "#jobDescription#") == 0) {
                    strcat(role, read_file_jobs);
                    strcat(role, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while (!strcmp(read_file_jobs, "#jobRequirements#") == 0) {
                    strcat(job_description, read_file_jobs);
                    strcat(job_description, " ");
                    file_jobs >> read_file_jobs;

                }
                file_jobs >> read_file_jobs;

                while (!strcmp(read_file_jobs, "#jobType#") == 0) {
                    strcat(job_requirements, read_file_jobs);
                    strcat(job_requirements, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while (!strcmp(read_file_jobs, "#jobCondition#") == 0) {
                    strcat(job_type, read_file_jobs);
                    strcat(job_type, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while (!strcmp(read_file_jobs, "#location#") == 0) {
                    strcat(job_condition, read_file_jobs);
                    strcat(job_condition, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;


                while (!strcmp(read_file_jobs, "#date#") == 0) {
                    strcat(location, read_file_jobs);
                    strcat(location, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> m >> d >> y;
                file_jobs >> read_file_jobs >> read_file_jobs;


                while (!strcmp(read_file_jobs, "#endl#") == 0) {
                    strcat(id_j, read_file_jobs);
                    strcat(id_j, " ");
                    file_jobs >> read_file_jobs;
                }

                //create new Job with details from file
                Job *job = new Job(company_name, role, job_description, job_requirements, job_type,
                                   job_condition,
                                   location, id_j, d, m, y);


                //add job to all_jobs array
                addJobToJobArr(job);


                company_name[0] = '\0';
                role[0] = '\0';
                job_description[0] = '\0';
                job_requirements[0] = '\0';
                job_type[0] = '\0';
                job_condition[0] = '\0';
                location[0] = '\0';
                date[0] = '\0';
                id_j[0] = '\0';
            }
        }

        file_jobs.close();

}


void Candidate :: addJobToJobArr(Job* job) {

    Job **temp_jobs_arr = new Job *[all_jobs_arr_size + 1];
    for (int i = 0; i < all_jobs_arr_size; ++i)
        temp_jobs_arr[i] = all_jobs_arr[i];

    temp_jobs_arr[all_jobs_arr_size] = job;
    delete [] all_jobs_arr;
    all_jobs_arr = temp_jobs_arr;
    ++all_jobs_arr_size;
}


void Candidate :: printAllJobsArr() const
{
    for (int i = 0; i < all_jobs_arr_size; ++i) {
        all_jobs_arr[i]->print();

    }
}

//function that returns true if str is at least 2 words and false otherwise
bool Candidate :: checkFirstNameAndLastName(char* str)
{
    int count = 0;
    bool exists = false;
    int index;
    for (int i = 0; str[i]!= '\0'; ++i) {
        if (str[i] == ' ') {
            exists = true;
            count ++;
        }
    }
    if(exists && count==1)
        return true;
    return false;
}


void Candidate :: submit_job()
{
    Colors color;
    bool validInput = true;
    bool is_job_found_in_file = false;
    char tmpID[500] = "";
    cout << "enter id of the job you want to submit\n";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(tmpID,500);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Colors color;

        color.setColorANSI(31);
        cout << "invalid input"<<endl;
        color.setColorANSI(0);


        validInput = false;
    }

    if(validInput) {
        strcat(tmpID, " ");
        for (int i = 0; i < all_jobs_arr_size; ++i) {
            if (all_jobs_arr[i]->getId().compare(tmpID) == 0) {
                is_job_found_in_file = true;


                color.setColorANSI(94);
                cout << "job was -SUBMITTED- successfully\n";
                color.setColorANSI(0);

                all_jobs_arr[i]->setSubmitted();
            }

        }
        if (!is_job_found_in_file)
        {
            color.setColorANSI(31);
            cout << "----------could not find job---------\n";
            color.setColorANSI(0);


        }


    }

}


void Candidate :: filterJobsByFeatures() {


    bool isInputValid = true;

    bool north = false, south = false, center = false, haifa = false, telAviv = false, judeaAndSamaria = false;

    bool full_time = false, part_time = false, student = false, special_needs = false;

    bool teaching = false, engineering = false, law = false, medicine = false,
            research = false, sales = false, restaurants = false, cleaning = false, economy = false;


    char nav_filter_job;
    Colors color;

    color.setColorANSI(33);
    cout << "1";
    color.setColorANSI(0);
    cout << "- location \n";

    color.setColorANSI(33);
    cout << "2";
    color.setColorANSI(0);
    cout << "- job type \n";

    color.setColorANSI(33);
    cout << "3";
    color.setColorANSI(0);
    cout << "- role \n";


    cin >> nav_filter_job;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        color.setColorANSI(31);
        cout << "invalid input, try again" << endl;
        color.setColorANSI(0);

        cin >> nav_filter_job;
        isInputValid = false;
    }

    if (nav_filter_job != '1' && nav_filter_job != '2' && nav_filter_job != '3') {

        cin.clear(); // Clears the error flag on cin
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        isInputValid = false;

    }


    if (isInputValid) {
        switch (nav_filter_job) {

            case LOCATION_F: {


                char nav_location;
                do {

                    Colors color;
                    color.setColorANSI(33);
                    cout << "3";
                    color.setColorANSI(0);
                    cout << "- role \n";


                    color.setColorANSI(34);
                    cout << "job location\n";
                    color.setColorANSI(0);
                    cout << "choose from the following:" << endl;


                    color.setColorANSI(33);
                    cout << "1";
                    color.setColorANSI(0);
                    cout << "- north \n";

                    color.setColorANSI(33);
                    cout << "2";
                    color.setColorANSI(0);
                    cout << "- south \n";

                    color.setColorANSI(33);
                    cout << "3";
                    color.setColorANSI(0);
                    cout << "- center \n";

                    color.setColorANSI(33);
                    cout << "4";
                    color.setColorANSI(0);
                    cout << "- haifa \n";

                    color.setColorANSI(33);
                    cout << "5";
                    color.setColorANSI(0);
                    cout << "- Tel aviv \n";


                    color.setColorANSI(33);
                    cout << "6";
                    color.setColorANSI(0);
                    cout << "- Judea and Samaria \n";

                    color.setColorANSI(33);
                    cout << "7";
                    color.setColorANSI(0);
                    cout << "- to filter chosen location \n";


                    cin >> nav_location;

                    while (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        color.setColorANSI(31);
                        cout << "invalid input, try again" << endl;
                        color.setColorANSI(0);

                        cin >> nav_filter_job;
                        isInputValid = false;
                    }

                    if (nav_filter_job != '1' && nav_filter_job != '2' && nav_filter_job != '3') {

                        cin.clear(); // Clears the error flag on cin
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    }

                    switch (nav_location) {
                        case NORTH: {
                            north = true;
                            break;
                        }
                        case SOUTH: {
                            south = true;
                            break;
                        }
                        case CENTER: {
                            center = true;
                            break;
                        }
                        case HAIFA: {
                            haifa = true;
                            break;
                        }
                        case TEL_AVIV: {
                            telAviv = true;
                            break;
                        }
                        case JUDEA_AND_SAMARIA: {
                            judeaAndSamaria = true;
                            break;
                        }
                        default: {
                            //if input is not one of the above - do nothing and print menu again
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        };
                    }


                } while (nav_location != '7');

            }
            case JOB_TYPE_F: {


                char nav_job_type;
                do {
                    Colors color;

                    color.setColorANSI(34);
                    cout << "job type\n";
                    color.setColorANSI(0);


                    color.setColorANSI(33);
                    cout << "1";
                    color.setColorANSI(0);
                    cout << "- full time \n";

                    color.setColorANSI(33);
                    cout << "2";
                    color.setColorANSI(0);
                    cout << "- part time \n";

                    color.setColorANSI(33);
                    cout << "3";
                    color.setColorANSI(0);
                    cout << "- student \n";

                    color.setColorANSI(33);
                    cout << "4";
                    color.setColorANSI(0);
                    cout << "- special needs \n";

                    color.setColorANSI(33);
                    cout << "5";
                    color.setColorANSI(0);
                    cout << "- to filter chosen job type \n";


                    cin >> nav_job_type;
                    while (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        color.setColorANSI(31);
                        cout << "invalid input, try again" << endl;
                        color.setColorANSI(0);

                        cin >> nav_filter_job;
                    }


                    switch (nav_job_type) {
                        case FULL_TIME: {
                            full_time = true;
                            break;
                        }
                        case PART_TIME: {
                            part_time = true;
                            break;
                        }
                        case STUDENT: {
                            student = true;
                            break;
                        }
                        case SPECIAL_NEEDS: {
                            special_needs = true;
                            break;
                        }
                        default: {
                            //if input is not one of the above - do nothing and print menu again
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        };
                    }
                } while (nav_job_type != '5');

            }

            case ROLE_F: {


                char nav_role;

                do {
                    Colors color;


                    color.setColorANSI(34);
                    cout << "role\n";
                    color.setColorANSI(0);

                    cout << "choose from the following:" << endl;


                    color.setColorANSI(33);
                    cout << "1";
                    color.setColorANSI(0);
                    cout << "- teaching \n";

                    color.setColorANSI(33);
                    cout << "2";
                    color.setColorANSI(0);
                    cout << "- engineering \n";

                    color.setColorANSI(33);
                    cout << "3";
                    color.setColorANSI(0);
                    cout << "- law \n";

                    color.setColorANSI(33);
                    cout << "4";
                    color.setColorANSI(0);
                    cout << "- medicine \n";

                    color.setColorANSI(33);
                    cout << "5";
                    color.setColorANSI(0);
                    cout << "- research \n";

                    color.setColorANSI(33);
                    cout << "6";
                    color.setColorANSI(0);
                    cout << "- sales \n";

                    color.setColorANSI(33);
                    cout << "7";
                    color.setColorANSI(0);
                    cout << "- restaurants \n";

                    color.setColorANSI(33);
                    cout << "8";
                    color.setColorANSI(0);
                    cout << "- cleaning \n";

                    color.setColorANSI(33);
                    cout << "9";
                    color.setColorANSI(0);
                    cout << "- economy \n";

                    color.setColorANSI(33);
                    cout << "0";
                    color.setColorANSI(0);
                    cout << "- to filter chosen job type \n";


                    cin >> nav_role;
                    while (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        color.setColorANSI(31);
                        cout << "invalid input, try again" << endl;
                        color.setColorANSI(0);

                        cin >> nav_filter_job;
                    }

                    switch (nav_role) {
                        case TEACHING: {
                            teaching = true;
                            break;
                        }
                        case ENGINEERING: {
                            engineering = true;
                            break;
                        }
                        case LAW: {
                            law = true;
                            break;
                        }
                        case MEDICINE: {
                            medicine = true;
                            break;
                        }
                        case RESEARCH: {
                            research = true;
                            break;
                        }
                        case SALES: {
                            sales = true;
                            break;
                        }
                        case RESTAURANTS: {
                            restaurants = true;
                            break;
                        }
                        case CLEANING: {
                            cleaning = true;
                            break;
                        }
                        case ECONOMY: {
                            economy = true;
                            break;
                        }
                        default: {
                            //if input is not one of the above - do nothing and print menu again
                            cin.clear(); // Clears the error flag on cin
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                        };


                    }
                } while (nav_role != '0');

            }
            default: {

            };
        }


        if (!isInputValid)
            return;

        bool existsJobToPrint = false;
        for (int i = 0; i < all_jobs_arr_size; ++i) {

            bool match_location = false;
            bool match_type = false;
            bool match_role = false;


            if ((north && strcmp(all_jobs_arr[i]->getLocation(), "north ") == 0)
                || (south && strcmp(all_jobs_arr[i]->getLocation(), "south ") == 0)
                || (center && strcmp(all_jobs_arr[i]->getLocation(), "center ") == 0)
                || (haifa && strcmp(all_jobs_arr[i]->getLocation(), "haifa ") == 0)
                || (telAviv && strcmp(all_jobs_arr[i]->getLocation(), "telAviv ") == 0)
                || (judeaAndSamaria && strcmp(all_jobs_arr[i]->getLocation(), "judeaAndSamaria ") == 0))
                match_location = true;


            if ((full_time && strcmp(all_jobs_arr[i]->getJobType(), "fullTime ") == 0)
                || (part_time && strcmp(all_jobs_arr[i]->getJobType(), "partTime ") == 0)
                || (student && strcmp(all_jobs_arr[i]->getJobType(), "student ") == 0)
                || (special_needs && strcmp(all_jobs_arr[i]->getJobType(), "specialNeeds ") == 0))
                match_type = true;


            if ((teaching && strcmp(all_jobs_arr[i]->getRole(), "teaching ") == 0)
                || (engineering && strcmp(all_jobs_arr[i]->getRole(), "engineering ") == 0)
                || (law && strcmp(all_jobs_arr[i]->getRole(), "law ") == 0)
                || (medicine && strcmp(all_jobs_arr[i]->getRole(), "medicine ") == 0)
                || (research && strcmp(all_jobs_arr[i]->getRole(), "research ") != 0)
                || (sales && strcmp(all_jobs_arr[i]->getRole(), "sales ") == 0)
                || (restaurants && strcmp(all_jobs_arr[i]->getRole(), "restaurants ") == 0)
                || (cleaning && strcmp(all_jobs_arr[i]->getRole(), "cleaning ") == 0)
                || (economy && strcmp(all_jobs_arr[i]->getRole(), "economy ") == 0))
                match_role = true;

        //print job after filtration
            if (match_location && match_type && match_role) {
                all_jobs_arr[i]->print();
                existsJobToPrint = true;
            }


        }
        if (!existsJobToPrint) {
            color.setColorANSI(34);
            cout << "not found the job your'e looking for, try expand search" << endl;
            color.setColorANSI(0);
        }
    }


}


void Candidate :: updateLikedStatusFromFile()
{

    fstream file_liked_jobs;

    char readFile[500];

    file_liked_jobs.open("C:\\ObjectOrientedProgramming\\job-search-portal\\likedJobs.txt",ios::in);
    if(!file_liked_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        while (!file_liked_jobs.eof()) {
            file_liked_jobs >> readFile;
            if (strcmp(readFile, id) == 0) {
                while (strcmp(readFile, "endl") != 0) {
                    file_liked_jobs >> readFile;
                    for (int i = 0; i < all_jobs_arr_size; ++i) {
                        if (readFile[strlen(readFile) - 1] >= '0' && readFile[strlen(readFile) - 1] <= '9')
                            strcat(readFile, " ");

                        if (all_jobs_arr[i]->getId().compare(readFile) == 0) {
                            all_jobs_arr[i]->setLiked();

                        }
                    }
                }
            }
        }


        file_liked_jobs.close();
    }




}


//print Submission history sorted by date
void Candidate :: viewSubmissionHistory() {

    if (all_jobs_arr_size < 1)
        return;

    Job *tmpSortedJobs[all_jobs_arr_size];

    bool selected[all_jobs_arr_size];//to track which jobs have been sorted
    for (int i = 0; i < all_jobs_arr_size; ++i) {
        selected[i] = false;
    }

    for (int i = 0; i < all_jobs_arr_size; ++i) {
        Job *latestDateJob = nullptr;
        int latestJobIndex = -1;

        for (int j = 0; j < all_jobs_arr_size; ++j) {
            if (!selected[j] && all_jobs_arr[j] != NULL && (latestDateJob == nullptr || compareJobsByDate(all_jobs_arr[j],latestDateJob))) {
                latestDateJob = all_jobs_arr[j];
                latestJobIndex = j;
            }
        }

        if (latestDateJob != nullptr) {
            if(all_jobs_arr[latestJobIndex]->isSubmitted())
                latestDateJob->Job::print(); //print latest submitted job
            selected[latestJobIndex] = true; // Mark this job as sorted
        }
    }

}

//return true if date of first job is earlier than second and false otherwise
bool Candidate :: compareJobsByDate(Job* a, Job* b) {
    // first compare by publishedYear
    if (a->getYear() != b->getYear())
        return a->getYear() > b->getYear();
    // then by publishedMonth
    if (a->getMonth() != b->getMonth())
        return a->getMonth() > b->getMonth();
    // finally by publishedDay
    return a->getDay() > b->getDay();
}




void Candidate :: likeJob() {
    Colors color;
    char tmpID[500] = "";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool validInput = true;

    cout << "enter id of job you want to mark as liked \n";

    cin.getline(tmpID, 500);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Colors color;

        color.setColorANSI(31);
        cout << "invalid input, try again" << endl;
        color.setColorANSI(0);


        validInput = false;
    }
    if (validInput) {

        strcat(tmpID, " ");
        for (int i = 0; i < all_jobs_arr_size; ++i) {
            if (all_jobs_arr[i]->getId().compare(tmpID) == 0) {//cmp between strings

                color.setColorANSI(34);
                cout << "job was -LIKED- successfully\n";
                color.setColorANSI(0);

                all_jobs_arr[i]->setLiked();
            }
        }
    }
}

void Candidate :: unLikeJob()
{
    Colors color;
    bool validInput = true;


    char tmpID[500] = "";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "enter id of job you want to mark as un liked\n";

    cin.getline(tmpID, 500);

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Colors color;

        color.setColorANSI(31);
        cout << "invalid input" << endl;
        color.setColorANSI(0);

        validInput = false;
    }
    if (validInput) {


        strcat(tmpID, " ");
        for (int i = 0; i < all_jobs_arr_size; ++i) {
            if (all_jobs_arr[i]->getId().compare(tmpID) == 0) {//job is found
                all_jobs_arr[i]->setUnLiked();
                color.setColorANSI(34);
                cout << "job " << tmpID << " is marked as UN-LIKED\n";
                color.setColorANSI(0);


            }
        }
    }



}


void Candidate :: viewLikedJobs()
{
    bool existsLikedJob = false;
    for(int i = 0; i < all_jobs_arr_size; ++i)
        if (all_jobs_arr[i]->isLiked()) {//if job was submitted - print its details
            existsLikedJob = true;
            all_jobs_arr[i]->print();
        }
    if(!existsLikedJob) {
        Colors color;

        color.setColorANSI(31);
        cout << "--havn't like a job yet--\n";
        color.setColorANSI(0);

    }
}


void Candidate :: copyPersonalDetailsToFile()
{
    fstream file_personal_details;
    file_personal_details.open("C:\\ObjectOrientedProgramming\\job-search-portal\\personalDetails.txt",ios::app);
    if(!file_personal_details.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        if (id != NULL && password != NULL && userName != NULL && email != NULL && phoneNumber != NULL &&
            birthDate != NULL && freeTxt != NULL && !wasPDcopied) {
            //copy all candidate details to "personalDetails" file
            file_personal_details << endl << "c " << id << " " << password << " " << userName << " " << email << " "
                                  << phoneNumber << " " << birthDate << " " << freeTxt << " #endl#";
            file_personal_details.close();
            wasPDcopied = true; //personal details were copied
        }
    }

}


void Candidate :: copyCVToFile()
{

    fstream file_cv;

    //copy CV to
    file_cv.open("C:\\ObjectOrientedProgramming\\job-search-portal\\CV.txt",ios::app);
    if(!file_cv.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
            file_cv << id << " #summary# " << cv->getSummary() << " #experience# " << cv->getExperience()
                    << " #education# " << cv->getEducation() << " #licenses# " <<
                    cv->getLicenses() << " #skills# " << cv->getSkills() << " #awards# " << cv->getAwards()
                    << " #name# " <<
                    cv->getName() << " #email# " << cv->getEmail() << " #endl# " << endl;

            file_cv.close();

    }

}


void Candidate :: copySubmittedJobsToFile()
{
    fstream file_submitted_jobs;

    file_submitted_jobs.open("C:\\ObjectOrientedProgramming\\job-search-portal\\submittedJobs.txt",ios::app);
    if(!file_submitted_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {

        if(all_jobs_arr != NULL) {
            bool isSubmitExists = false;
            for (int i = 0; i < all_jobs_arr_size; ++i)
                if (all_jobs_arr[i] != NULL) {
                    if (all_jobs_arr[i]->isSubmitted())
                        isSubmitExists = true;
                }

            if (isSubmitExists) {
                file_submitted_jobs << id << " ";
                for (int i = 0; i < all_jobs_arr_size; ++i) {
                    if (all_jobs_arr[i] != NULL)
                        if (all_jobs_arr[i]->isSubmitted()) { //if job was submitted, add its id to file
                            file_submitted_jobs << all_jobs_arr[i]->getId() << " ";
                    }

                }
                file_submitted_jobs << "endl" << endl;
            }
        }
        file_submitted_jobs.close();

    }


}


void Candidate :: copyLikedJobsToFile() {

    fstream file_liked_jobs;

    file_liked_jobs.open("C:\\ObjectOrientedProgramming\\job-search-portal\\likedJobs.txt",ios::app);
    if(!file_liked_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {

        if(all_jobs_arr != NULL) {

            bool isLikedExists = false;
            for (int i = 0; i < all_jobs_arr_size; ++i)
                if (all_jobs_arr[i] != NULL) {
                    if (all_jobs_arr[i]->isLiked())
                        isLikedExists = true;
                }

            if (isLikedExists) {
                file_liked_jobs << id << " ";
                for (int i = 0; i < all_jobs_arr_size; ++i) {
                    if (all_jobs_arr[i] != NULL)
                        if (all_jobs_arr[i]->isLiked()) { //if job was submitted, add its id to file
                        file_liked_jobs << all_jobs_arr[i]->getId() << " ";
                    }

                }
                file_liked_jobs << "endl" << endl;
            }
        }
        file_liked_jobs.close();

    }

}

CV *Candidate::getCv() const {
    return cv;
}

char *Candidate::getFreeTxt() const {
    return freeTxt;
}

