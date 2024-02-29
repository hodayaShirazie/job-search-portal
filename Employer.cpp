//
// Created by Student on 14/02/2024.
//
#include "Employer.h"
//#include "Candidate.h"

//TODO handle "none" printing
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

    //TODO delete here or in candidate array of candidate applicants

}


void Employer :: personalArea()
{
    char nav_personal_area;
    do {
        cout << "1- submission history \n";
        cout << "2- candidate submission\n";
        cout << "3- publish a job \n";
        cout << "4- log out \n";

        cin >> nav_personal_area;



        // Clear buffer after getting single char
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Check if the input is not one of the expected options
        if (nav_personal_area < '1' || nav_personal_area > '4') {
            cout << "Invalid input. Please enter a valid option (1-4)." << endl;
            continue; // Skip the rest of the loop and prompt again
        }



        switch (nav_personal_area) {
            case SUBMISSION_HISTORY_E: {
                char nav_submission_history;

                do {
                    cout << "\n1- all submitted jobs \n";
                    cout << "2- update a job \n";
                    cout << "3- delete a job\n";
                    cout << "4- back to personal area \n";

                    cin >> nav_submission_history;



                    // Clear buffer after getting single char
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    // Check if the input is not one of the expected options
                    if (nav_submission_history < '1' || nav_submission_history > '4') {
                        cout << "Invalid input. Please enter a valid option (1-4)." << endl;
                        continue; // Skip the rest of the loop and prompt again
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
                cout << "------------------ghghgh------------------\n";
                for (int i = 0; i < published_jobs_arr_size; ++i) {
                    published_jobs_arr[i]->print();

                }
                cout << "------------------ghghgh------------------\n";


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

    char buffer[80];
    cin.ignore();

    cout << "username" << endl;
    cin.getline(buffer,80);
    while (strlen(buffer) > 20 || !checkFirstNameAndLastName(buffer)) { //check validation of user name
        cout << "enter a valid user name" << endl;
        cin.getline(buffer, 80);
    }
    userName = new char[strlen(buffer) + 1];
    strcpy(userName,buffer);

}
void Employer ::set_id() {

    bool valid = false;
    char buffer[80];
    cout << "id" << endl;
    cin.getline(buffer, 80);
    while (!valid) {
        bool onlyDigits = true;
        for (int i = 0; buffer[i] != '\0'; ++i)
            if(buffer[i] < '0' || buffer[i] > '9')
                onlyDigits = false;

        if(strlen(buffer) == 9 && onlyDigits)
            valid = true;
        else{
            cout << "invalid id, try again" << endl;
            cin.getline(buffer, 80);
        }

    }
    id = new char[strlen(buffer) + 1];
    strcpy(id, buffer);


}

void  Employer ::set_email() {

    char buffer[80];
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

void Employer :: set_phone_number()
{

    char buffer[80];

    delete [] phoneNumber;
//    cin.ignore();
    bool valid = false;

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


    phoneNumber = new char[strlen(buffer) + 1];
    strcpy(phoneNumber, buffer);

}

void Employer::set_password() {

    char buffer[80];
    delete [] password;
//    cin.ignore();

    bool lowerCase = false;
    bool upperCase = false;
    bool valid = false;

    cout << "password" << endl;
    cin.getline(buffer, 80);
    while(!valid)
    {
        for (int i = 0; buffer[i] != '\0' && !valid; ++i) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z')
                lowerCase = true;
            else if(buffer[i] >= 'A' && buffer[i] <= 'Z')
                upperCase = true;

            if(lowerCase && upperCase && strlen(buffer) >= 8)
                valid = true;
        }
        if(!valid)
        {
            cout << "password is not valid, try again" << endl;
            cin.getline(buffer, 80);
        }
    }


    password = new char[strlen(buffer) + 1];
    strcpy(password, buffer);


}

void Employer::set_birth_date() {

    delete [] birthDate;

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
        cout<<"invalid date, enter: month, day and year"<<endl;
        cin >> m >> d >> y;
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
    cout << "--------------printing published jobs in function-----------------------\n";

    for (int i = 0; i < published_jobs_arr_size; ++i) {
        published_jobs_arr[i]->print();

    }
}


//update to and from file functions
void Employer ::copyPersonalDetailsToFile() {


    //copy all employer details to "personalDetails" file
    fstream file_personal_details;
    file_personal_details.open("C:\\ObjectOrientedProgramming\\jobSearch\\personalDetails.txt",ios::app);
    if(!file_personal_details.is_open()) {
        cout << "file could not be opened, check error" << endl;
    }else{
        file_personal_details  << endl << "e " << id << " " << password << " " << userName << " " << email << " " << phoneNumber << " " << birthDate;
        file_personal_details.close();
    }



}

void Employer ::copyJobsFromFile()
{
    fstream file_jobs;

    file_jobs.open("C:\\ObjectOrientedProgramming\\jobSearch\\jobs.txt",ios::in);
    if(!file_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {
        char company_name[200] = "\0";
        char role[200] = "\0";
        char job_description[200] = "\0";
        char job_requirements[200] = "\0";
        char job_type[200] = "\0";
        char job_condition[200] = "\0";
        char location[200] = "\0";
        char date[200] = "\0";
        char id_j[5] =  "\0";

        while(!file_jobs.eof()) {
            char read_file_jobs[200];
            file_jobs >> read_file_jobs;
            if (strcmp(read_file_jobs, id) == 0)
            {
                //coping company name
                file_jobs >> read_file_jobs >> read_file_jobs;
                while(!strcmp(read_file_jobs, "#role#") == 0)
                {
                    strcat(company_name,read_file_jobs);
                    strcat(company_name, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;
                //
                while(!strcmp(read_file_jobs, "#jobDescription#") == 0)
                {
                    strcat(role,read_file_jobs);
                    strcat(role, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while(!strcmp(read_file_jobs, "#jobRequirements#") == 0)
                {
                    strcat(job_description,read_file_jobs);
                    strcat(job_description, " ");
                    file_jobs >> read_file_jobs;

                }
                file_jobs >> read_file_jobs;

                while(!strcmp(read_file_jobs, "#jobType#") == 0)
                {
                    strcat(job_requirements,read_file_jobs);
                    strcat(job_requirements, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while(!strcmp(read_file_jobs, "#jobCondition#") == 0)
                {
                    strcat(job_type,read_file_jobs);
                    strcat(job_type, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while(!strcmp(read_file_jobs, "#location#") == 0)
                {
                    strcat(job_condition,read_file_jobs);
                    strcat(job_condition, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while(!strcmp(read_file_jobs, "#date#") == 0)
                {
                    strcat(location,read_file_jobs);
                    strcat(location, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

                while(!strcmp(read_file_jobs, "#id#") == 0)
                {
                    strcat(date,read_file_jobs);
                    strcat(date, " ");
                    file_jobs >> read_file_jobs;
                }

                while(!strcmp(read_file_jobs, "#endl#") == 0)
                {
                    strcat(id_j,read_file_jobs);
                    strcat(id_j, " ");
                    file_jobs >> read_file_jobs;
                }
                file_jobs >> read_file_jobs;

//                            create new Job with details from file
                Job* job = new Job(company_name, role, job_description, job_requirements, job_type, job_condition, location, date, id);
//                cout<<"printing job from filee-------\n";
//                job->print();



            }
        }

        file_jobs.close();
    }




}

void Employer :: copyAllJobsToFiles()
{
    //copy all job details to "jobSearch" file
    fstream file_jobs;
    file_jobs.open("C:\\ObjectOrientedProgramming\\jobSearch\\jobs.txt", ios::app);
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
                      " #location# " << published_jobs_arr[i]->getLocation() << " #date# " << published_jobs_arr[i]->getDate() <<
                      " #id# " << published_jobs_arr[i]->getId() << " #endl#";

        }
        file_jobs.close();
    }


}


void Employer :: edit_job()
{
    //getting input of job to update
    char jobId[500];
    cout << "enter id of job you want to update \n";
    cin.getline(jobId,500);
    strcat(jobId," ");//id in field is a string that consist of a number and space in end

    //update job
    for (int i = 0; i < published_jobs_arr_size; ++i) {
        if (jobId == published_jobs_arr[i]->getId()) {//if job is in array - update its details
            published_jobs_arr[i]->updateJob();
            cout << "job was successfully updated" << endl;
        }

    }




}

void Employer :: delete_a_job()
{

    char nav_delete;

    //getting input of job to delete
    char jobId[500];
    cout << "enter id of job you want to delete \n";
    cin.getline(jobId,500);


    while(!isValidNumber(jobId))
    {
        cout << "input is not valid or job was not found, try again \n";
        cin.getline(jobId,500);
    }


    cout << "are you sure you want to delete this job? \n1- yes \n2- no \n";
    cin >> nav_delete;

    if(nav_delete == '1') {
        //update job
        for (int i= 0; i < published_jobs_arr_size; ++i)
            if (jobId == published_jobs_arr[i]->getId())//if job is in array - remove from array
            {
                Job **tmpArr = new Job *[published_jobs_arr_size - 1];
                for (int k = 0; k < i; ++k)
                    tmpArr[k] = published_jobs_arr[k];
                for (int m = i + 1; m < published_jobs_arr_size; ++m)
                    tmpArr[m - 1] = published_jobs_arr[m];

                delete[] published_jobs_arr;
                published_jobs_arr = tmpArr;
                published_jobs_arr_size--;


                cout << "job is successfully deleted\n";


            }
    }

}

bool Employer :: isValidNumber(char* jobId) {

    bool exists = false;
    bool allDigits = true;

//    cout << "inside is-invalid\n";
//
//    cout << "------------------g----------gh------------------\n";
//    for (int i = 0; i < published_jobs_arr_size; ++i) {
//        cout<< "id=" <<published_jobs_arr[i]->getId()<<endl;
//
//    }
//    cout << "------------------gh---------gh------------------\n";

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

////////TODO fix delete after publishing

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
    cout << "job was successfully posted, to view job details go to submission history\n";
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
    for (int i = 0; i < published_jobs_arr_size; ++i)
    {
        cout << "candidate submission to job id: " << published_jobs_arr[i]->getId();
        if(published_jobs_arr[i]->getJobApplicantsSize() == 0) cout << "--none--\n"; else cout << "\n";

        published_jobs_arr[i]->printJobApplicants();
//        for (int j = 0; j < published_jobs_arr[i]->getJobApplicantsSize(); ++j) {
//            published_jobs_arr[i]->printJobApplicants();
//        }

    }


}
















//char *Employer::getUserName() const {
//    return userName;
//}
//
//
//char *Employer::getEmail() const {
//    return email;
//}
//
//char *Employer::getPhoneNumber() const {
//    return phoneNumber;
//}
//
//char *Employer::getBirthDate() const {
//    return birthDate;
//}
