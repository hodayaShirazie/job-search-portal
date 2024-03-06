//
// Created by Student on 14/02/2024.
//
#include "Employer.h"
//#include "Candidate.h"

//constructor with parameters
Employer :: Employer(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate):published_jobs_arr(NULL), published_jobs_arr_size(0)
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


}

//constructor with no parameters
Employer::Employer() : userName(NULL), id(NULL), email(NULL), phoneNumber(NULL), birthDate(NULL), password(NULL), published_jobs_arr(NULL), published_jobs_arr_size(0)
{

    //getting user-name
    set_user_name();

    //getting user id
    set_id();

    //getting user email
    set_email();

    //getting phone number
    set_phone_number();

    //getting password
    set_password();

    //getting birthdate
    set_birth_date();

}


//distructor
Employer :: ~Employer()
{
    //saving data in files
    copyPersonalDetailsToFile();

    copyAllJobsToFiles();


    //dis-allocating memory
    delete [] userName;
    delete [] id;
    delete [] email;
    delete [] phoneNumber;
    delete [] birthDate;
    delete [] password;

    for (int i = 0; i < Employer::published_jobs_arr_size; ++i)
        delete published_jobs_arr[i];



}


void Employer :: personalArea()
{
    char nav_personal_area;
    do {

        Colors color;

        color.setColorANSI(33);
        cout << "1";
        color.setColorANSI(0);
        cout << "- submission history \n";

        color.setColorANSI(33);
        cout << "2";
        color.setColorANSI(0);
        cout << "- candidate submission\n";

        color.setColorANSI(33);
        cout << "3";
        color.setColorANSI(0);
        cout << "- publish a job \n";

        color.setColorANSI(33);
        cout << "4";
        color.setColorANSI(0);
        cout << "- log out \n";

        cin >> nav_personal_area;



        // Clear buffer after getting single char
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Check if the input is not one of the expected options
        if (nav_personal_area < '1' || nav_personal_area > '4')
        {
            Colors color;

            color.setColorANSI(31);
            cout<< "invalid input, try again\n";
            color.setColorANSI(0);


            continue; // Skip the rest of the loop and prompt again
        }



        switch (nav_personal_area) {
            case SUBMISSION_HISTORY_E: {
                char nav_submission_history;

                do {

                    Colors color;

                    color.setColorANSI(33);
                    cout << "\n1";
                    color.setColorANSI(39);
                    cout << "- all submitted jobs \n";

                    color.setColorANSI(33);
                    cout << "2";
                    color.setColorANSI(39);
                    cout << "- update a job \n";

                    color.setColorANSI(33);
                    cout << "3";
                    color.setColorANSI(39);
                    cout << "- delete a job\n";

                    color.setColorANSI(33);
                    cout << "4";
                    color.setColorANSI(39);
                    cout << "- back to personal area \n";

                    cin >> nav_submission_history;

                    // Check if the input is not one of the expected options
                    if (nav_submission_history != '1' && nav_submission_history != '2' && nav_submission_history != '3' && nav_submission_history != '4') {
                        Colors color;

                        color.setColorANSI(31);
                        cout<< "invalid input, try again\n";
                        color.setColorANSI(0);


                        cin.clear(); // Clears the error flag on cin.
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }




                    switch (nav_submission_history) {
                        case ALL_SUBMITTED_JOBS: {

                            //print array of published jobs
                            printPublishedJobs();

                            break;
                        }
                        case EDIT_JOBS: {

                            edit_job();
                            break;
                        }
                        case DELETE_JOBS: {

                            delete_a_job();
                            break;
                        }

                        case BACK_P_A_E: {
                            //navigate user to all submission history
                            break;
                        }
                        default:{
                            break;
                        }
                    }


                } while (nav_submission_history != BACK_P_A_E);

                break;
            }
            case CANDIDTE_SUBMISSION: {
                viewCandidateSubmission();
                break;
            }
            case PUBLISH_JOB: {


                addNewJob();

                break;
            }
            case Exit_E: {
                //exit program
                break;
            }


        }
    } while (nav_personal_area != Exit_E);
}


//getters
char *Employer::getId() const {
    return id;
}

char *Employer::getPassword() const {
    return password;
}

Job **Employer::getPublishedJobsArr() const {
    return published_jobs_arr;
}

int Employer::getPublishedJobsArrSize() const {
    return published_jobs_arr_size;
}


void Employer::set_user_name()
{

    delete [] userName;


//    string newVal;
    char buffer[80];
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool validInput = true;


    //getting user-name
    cout << "username" << endl;
    cin.getline(buffer,80);
    if (std::cin.fail()) {
        Colors color;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        color.setColorANSI(31);
        cout<< "invalid input";
        color.setColorANSI(0);

        validInput = false;
    }


    while (!validInput || strlen(buffer) > 20 || !checkFirstNameAndLastName(buffer)) { //check validation of user name
        cout << "enter a valid user name" << endl;
        cin.getline(buffer, 80);

        if (std::cin.fail()) {
            Colors color;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            color.setColorANSI(31);
            cout<< "invalid input";
            color.setColorANSI(0);

            validInput = false;
        }
        else
            validInput = true;


    }
    userName = new char[strlen(buffer) + 1];
    strcpy(userName, buffer);



}

void Employer ::set_id() {

    bool valid = false;
    char buffer[80];
    bool validInput = true;

    cout << "id" << endl;
    cin.getline(buffer, 80);

    if (std::cin.fail()) {
        Colors color;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        color.setColorANSI(31);
        cout<< "invalid input";
        color.setColorANSI(0);


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

                color.setColorANSI(31);
                cout << "invalid id" << endl;
                color.setColorANSI(0);

                validInput = false;
            }
            else
                validInput = true;

        }

    }
    id = new char[strlen(buffer) + 1];
    strcpy(id, buffer);
}

void  Employer ::set_email() {

    char buffer[80];
    bool validInput = true;

    delete [] email;

    cout << "email" << endl;
    cin.getline(buffer, 80);
    if (std::cin.fail()) {
        Colors color;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        color.setColorANSI(31);
        cout << "invalid id" << endl;
        color.setColorANSI(0);

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
            cout << "invalid email, enter again" << endl;
            cin.getline(buffer, 80);

            if (std::cin.fail()) {
                Colors color;

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                color.setColorANSI(31);
                cout << "invalid id" << endl;
                color.setColorANSI(0);

                validInput = false;
            }
            else
                validInput = true;

        }

    }

    email = new char[strlen(buffer) + 1];
    strcpy(email, buffer);


}

void Employer :: set_phone_number()
{

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

//                color.setConsoleColor(FOREGROUND_RED);
//                cout << "invalid input" << endl;
//                color.setConsoleColor(7);
                validInput = false;
            } else
                validInput = true;
        }



    }


    phoneNumber = new char[strlen(buffer) + 1];
    strcpy(phoneNumber, buffer);

}

void Employer::set_password() {

    char buffer[80];
    bool validInput = true;

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


        color.setColorANSI(31);
        cout << "invalid input" << endl;
        color.setColorANSI(0);

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


    password = new char[strlen(buffer) + 1];
    strcpy(password, buffer);

}
//TODO print message when done deleting job
void Employer::set_birth_date() {

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
        cout<<"invalid date, enter: publishedMonth, publishedDay and publishedYear"<<endl;
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



bool Employer:: checkValidDate(int day, int month, int year) {

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



//function that returns true if str is at least 2 words and false otherwise
bool Employer :: checkFirstNameAndLastName(char* str)
{
    bool exists = false;
    for (int i = 0; str[i]!= '\0'; ++i)
        if(str[i] == ' ')
            exists = true;
    return exists;
}




//print functions
void Employer:: print() const {

    cout << "\nuser name: " << userName << endl;

    cout << "id: " << id << endl;

    cout << "email: " << email << endl;

    cout << "phoneNumber: " << phoneNumber << endl;

    cout << "birthDate: " << birthDate << endl;

    cout << "password: " << password << endl << endl;

    //printing published jobs
    cout << "--------------printing published jobs-----------------------\n";
    printPublishedJobs();

}

void Employer :: printPublishedJobs() const
{

    for (int i = 0; i < published_jobs_arr_size; ++i) {
        published_jobs_arr[i]->printJobForEmployer();

    }
}


//update to and from file functions
void Employer ::copyPersonalDetailsToFile() {


    //copy all employer details to "personalDetails" file
    fstream file_personal_details;
    file_personal_details.open("C:\\ObjectOrientedProgramming\\job-search-portal\\personalDetails.txt",ios::app);
    if(!file_personal_details.is_open()) {
        cout << "file could not be opened, check error" << endl;
    }else{
        file_personal_details  << endl << "e " << id << " " << password << " " << userName << " " << email << " " << phoneNumber << " " << birthDate;
        file_personal_details.close();
    }



}


void Employer :: copyAllJobsToFiles()
{
    //copy all job details to "jobSearch" file
    fstream file_jobs;
    file_jobs.open("C:\\ObjectOrientedProgramming\\job-search-portal\\jobs.txt", ios::app);
    if(!file_jobs.is_open()) {
        cout << "file could not be opened, check error" << endl;
    }else
    {
        for (int i = 0; i < published_jobs_arr_size; ++i) {
            file_jobs << endl << id;
            file_jobs << " #companyName# " << published_jobs_arr[i]->getCompanyName() <<  " #role# " << published_jobs_arr[i]->getRole()
                      <<  " #jobDescription# " << published_jobs_arr[i]->getJobDescription() <<  " #jobRequirements# " <<
                      published_jobs_arr[i]->getJobRequirements() <<
                      " #jobType# " << published_jobs_arr[i]->getJobType() <<  " #jobCondition# " << published_jobs_arr[i]->getJobCondition() <<
                      " #location# " << published_jobs_arr[i]->getLocation() << " #date# " << published_jobs_arr[i]->getMonth()  << " "
                      << published_jobs_arr[i]->getDay()  << " " << published_jobs_arr[i]->getYear() << " #id# " <<
                      published_jobs_arr[i]->getId() << " #endl#";

        }
        file_jobs.close();
    }


}


void Employer :: edit_job()
{
    //getting input of job to update
    char jobId1[500];
    string jobId2;
    Colors color;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "enter id of job you want to update \n";
    cin.getline(jobId1,500);
    jobId2 = jobId1;

    strcat(jobId1," ");//id in field is a string that consist of a number and space in end

    //update job
    for (int i = 0; i < published_jobs_arr_size; ++i) {
        if (jobId1 == published_jobs_arr[i]->getId() || jobId2 == published_jobs_arr[i]->getId()) {//if job is in array - update its details
            published_jobs_arr[i]->updateJob();

            color.setColorANSI(34);
            cout << "job was successfully updated" << endl;
            color.setColorANSI(0);

        }

    }




}

void Employer :: delete_a_job()
{

    char nav_delete;

    //getting input of job to delete
    char jobId[500];
    string jobId2;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "enter id of job you want to delete \n";
    cin.getline(jobId,500);
    jobId2 = jobId;

    while(!isValidNumber(jobId))
    {
        Colors color;
        color.setColorANSI(34);
        cout << "input is not valid or job was not found, try again \n";
        color.setColorANSI(0);

        cin.getline(jobId,500);
    }
    Colors color;

    cout << "are you sure you want to delete this job?\n";

    color.setColorANSI(33);
    cout << "1";
    color.setColorANSI(0);
    cout<<"- yes \n";
    color.setColorANSI(33);
    cout << "2";
    color.setColorANSI(0);
    cout << "- no \n";
    cin >> nav_delete;


    if (nav_delete != '1' && nav_delete != '2') {
        cin.clear(); // Clears the error flag on cin.
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }



    if(nav_delete == '1') {
        //update job
        for (int i= 0; i < published_jobs_arr_size; ++i)
            if (jobId == published_jobs_arr[i]->getId() || jobId2 == published_jobs_arr[i]->getId())//if job is in array - remove from array
            {
                Job **tmpArr = new Job *[published_jobs_arr_size - 1];
                for (int k = 0; k < i; ++k)
                    tmpArr[k] = published_jobs_arr[k];
                for (int m = i + 1; m < published_jobs_arr_size; ++m)
                    tmpArr[m - 1] = published_jobs_arr[m];

                delete[] published_jobs_arr;
                published_jobs_arr = tmpArr;
                published_jobs_arr_size--;

                color.setColorANSI(34);
                cout << "job is successfully deleted\n";
                color.setColorANSI(39);


            }
    }

}

bool Employer :: isValidNumber(char* jobId) {

    bool exists = false;
    bool allDigits = true;


    // Check each character to ensure it's a digit
    for (int i = 0; jobId[i] != '\0'; ++i) { // Loop until the end of the string
        if (!isdigit(jobId[i])) {
            allDigits = false; // Found a non-digit character
        }
    }

    if (allDigits && !exists) {
        string jobIDNoSpace = jobId;
        strcat(jobId," ");


        for (int i = 0; i < published_jobs_arr_size; ++i)
            if(jobIDNoSpace == published_jobs_arr[i]->getId() || published_jobs_arr[i]->getId().compare(jobId) == 0)
                exists = true;
    }

    if (!allDigits || !exists)
        return false;
    return true;


}


void Employer :: addNewJob()
{
    Job* job = new Job();
    Job** tempArr = new Job*[published_jobs_arr_size+1];
    for(int i=0; i<published_jobs_arr_size; ++i)
        tempArr[i] = published_jobs_arr[i];
    tempArr[published_jobs_arr_size] = job;
    delete [] published_jobs_arr;
    published_jobs_arr = tempArr;
    ++published_jobs_arr_size;

    Colors color;
    color.setColorANSI(34);
    cout << "---job was successfully posted, to view job details go to submission history---\n";
    color.setColorANSI(39);

}

void Employer :: addJobToPublishJobs(Job* job) {
    Job **temp_jobs_arr = new Job *[published_jobs_arr_size + 1];
    for (int i = 0; i < published_jobs_arr_size; ++i)
        temp_jobs_arr[i] = published_jobs_arr[i];
    temp_jobs_arr[published_jobs_arr_size] = job;
    delete [] published_jobs_arr;
    published_jobs_arr = temp_jobs_arr;
    ++published_jobs_arr_size;
}

void Employer :: viewCandidateSubmission()
{
    Colors color;

    for (int i = 0; i < published_jobs_arr_size; ++i) {
        if (published_jobs_arr[i]->getJobApplicantsSize() != 0) {

            color.setColorANSI(33);
            cout << "--------------------------candidate submission to job id: " << published_jobs_arr[i]->getId()
                 << "--------------------------\n";
            color.setColorANSI(39);

            published_jobs_arr[i]->printJobApplicants();

        }
    }


}



