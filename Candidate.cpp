//
// Created by Student on 14/02/2024.
//

#include "Candidate.h"



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


}


//constructor
Candidate :: Candidate(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate, char* freeTxt):cv(NULL),all_jobs_arr(NULL), all_jobs_arr_size(0)
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

    updateSubmittedStatusFromFile();

    updateLikedtedStatusFromFile();


}


//constructor
 Candidate :: Candidate() : userName(NULL), id(NULL), email(NULL), phoneNumber(NULL), birthDate(NULL), password(NULL),freeTxt(NULL),all_jobs_arr_size(0), all_jobs_arr(NULL) {
    copyAllJobsFromFile();


    char buffer[80];
    cin.ignore();

    //getting user-name
    cout << "username" << endl;
    cin.getline(buffer, 80);
    while (strlen(buffer) > 20) {
        cout << "user name is up to 20 letters, try again" << endl;
        cin.getline(buffer, 80);
    }

    userName = new char[strlen(buffer) + 1];
    strcpy(userName, buffer);

    //getting user id
    cout << "id" << endl;
    cin.getline(buffer, 80);
    while (strlen(buffer) != 9) {
        cout << "invalid id, try again" << endl;
        cin.getline(buffer, 80);
    }
    id = new char[strlen(buffer) + 1];
    strcpy(id, buffer);


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
        for (int i = 0; buffer[i] != '\0' && validChar && invalidProfix; ++i) {
            if (!(buffer[i] >= 'a' && buffer[i] <= 'z' || buffer[i] >= 'A' && buffer[i] <= 'Z'))
                if (!(buffer[i] >= '0' && buffer[i] <= '9'))
                    if (!(buffer[i] == '-' || buffer[i] == '.'))
                        if (!(buffer[i] == '@')) {
                            validChar = false; //email is not valid
                        } else
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
    while (strlen(buffer) != 10 || buffer[0] != '0') {
        cout << "invalid phone number, enter again" << endl;
        cin.getline(buffer, 80);
    }
    phoneNumber = new char[strlen(buffer) + 1];
    strcpy(phoneNumber, buffer);

    //getting birth date
    cout << "birthDate" << endl;
    cin.getline(buffer, 80);

    //TODO check validation

    birthDate = new char[strlen(buffer) + 1];
    strcpy(birthDate, buffer);

    //getting password
    cout << "password" << endl;
    cin.getline(buffer, 80);

    //TODO check validation

    password = new char[strlen(buffer) + 1];
    strcpy(password, buffer);

    char tempFt[501];
    cout << "add free text to tell about yourself, if you dont want- enter none" << endl;
    cin.getline(tempFt, 501);
    freeTxt = new char[strlen(tempFt) + 1];
    strcpy(freeTxt, tempFt);

    //add cv
    cv = new CV(userName, email);


    cout << "create account" << endl;
    cout << "-----------------------printing all copied jobs------------------------" << endl;

    printAllJobsArr();
//    updateSubmittedStatusFromFile();


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
    char nav_personal_area = '\0'; //TODO change to do-while

    while(nav_personal_area != Exit_C) {
        cout << "1- edit profile \n";
        cout << "2- all jobs \n";
        cout << "3- filter jobs \n";
        cout << "4- submit job \n";
        cout << "5- like a job \n";
        cout << "6- jobs i liked \n";
        cout << "7- submission history \n";
        cout << "8- exit \n";
        cin >> nav_personal_area;


        switch (nav_personal_area) {
            case EDIT_PROFILE: {
                char nav_edit_profile;



                do {
                    cout << "1- user name \n";
                    cout << "2- email \n";
                    cout << "3- phone number \n";
                    cout << "4- password \n";
                    cout << "5- cv \n";
                    cout << "6- back to personal area \n";

                    cin >> nav_edit_profile;

                    switch (nav_edit_profile) {
                        case USER_NAME_C: {
                            set_user_name();
                            cv->setName(userName); //change name in cv
                            break;
                        }
                        case EMAIL_C: {
                            set_email();
                            cv->setEmail(email); //change email in cv
                            break;

                        }
                        case PHONE_NUMBER_C: {
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
                        case BACK_P_A_C: {
                            break;

                        }

                    }
                }while (nav_edit_profile != BACK_P_A_C);

                print();


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
                likeJob();
                break;
            }
            case JOBS_I_LIKED: {
                viewLikedJjobs();
                break;
            }
            case SUBMISSION_HISTORY_C: {
                viewSubmissionHistory();
                break;
            }
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
//    cin.ignore();

    delete [] phoneNumber;
    cin.ignore();
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


void Candidate:: set_password()
{
    char buffer[80];
    delete [] password;
    cin.ignore();
    cout << "password" << endl;
    cin.getline(buffer, 80);
    password = new char[strlen(buffer) + 1];
    strcpy(password, buffer);

}


void Candidate:: set_cv(CV *cv)
{
    //TODO change cv fields
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

void Candidate :: copyAllJobsFromFile() {


    fstream file_jobs;

    char company_name[200] = "\0";
    char role[200] = "\0";
    char job_description[200] = "\0";
    char job_requirements[200] = "\0";
    char job_type[200] = "\0";
    char job_condition[200] = "\0";
    char location[200] = "\0";
    char date[200] = "\0";
    char id_j[5] = "\0";

    file_jobs.open("C:\\ObjectOrientedProgramming\\jobSearch\\jobs.txt", ios::in);
    if (!file_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else {

        while (!file_jobs.eof()) {
            char read_file_jobs[200];
            file_jobs >> read_file_jobs;

            //coping company name
            file_jobs >> read_file_jobs >> read_file_jobs;
            while (!strcmp(read_file_jobs, "role") == 0) {
                strcat(company_name, read_file_jobs);
                strcat(company_name, " ");
                file_jobs >> read_file_jobs;
            }
            file_jobs >> read_file_jobs;

            while (!strcmp(read_file_jobs, "jobDescription") == 0) {
                strcat(role, read_file_jobs);
                strcat(role, " ");
                file_jobs >> read_file_jobs;
            }
            file_jobs >> read_file_jobs;

            while (!strcmp(read_file_jobs, "jobRequirements") == 0) {
                strcat(job_description, read_file_jobs);
                strcat(job_description, " ");
                file_jobs >> read_file_jobs;

            }
            file_jobs >> read_file_jobs;

            while (!strcmp(read_file_jobs, "jobType") == 0) {
                strcat(job_requirements, read_file_jobs);
                strcat(job_requirements, " ");
                file_jobs >> read_file_jobs;
            }
            file_jobs >> read_file_jobs;

            while (!strcmp(read_file_jobs, "jobCondition") == 0) {
                strcat(job_type, read_file_jobs);
                strcat(job_type, " ");
                file_jobs >> read_file_jobs;
            }
            file_jobs >> read_file_jobs;

            while (!strcmp(read_file_jobs, "location") == 0) {
                strcat(job_condition, read_file_jobs);
                strcat(job_condition, " ");
                file_jobs >> read_file_jobs;
            }
            file_jobs >> read_file_jobs;

            while (!strcmp(read_file_jobs, "date") == 0) {
                strcat(location, read_file_jobs);
                strcat(location, " ");
                file_jobs >> read_file_jobs;
            }
            file_jobs >> read_file_jobs;

            while (!strcmp(read_file_jobs, "id") == 0) {
                strcat(date, read_file_jobs);
                strcat(date, " ");
                file_jobs >> read_file_jobs;
            }
            file_jobs >> read_file_jobs;


            while (!strcmp(read_file_jobs, "endl") == 0) {
                strcat(id_j, read_file_jobs);
                strcat(id_j, " ");
                file_jobs >> read_file_jobs;
            }

            //create new Job with details from file
            Job *job = new Job(company_name, role, job_description, job_requirements, job_type,
                               job_condition,
                               location, date, id_j);
//                        cout << "printing job from filee-------\n";
//            job->print();

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

        file_jobs.close();
    }


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
        cout << "\nJob offer number " << i+1 << " for you" << endl;
        all_jobs_arr[i]->print();

    }
}

void Candidate :: submit_job()
{
    bool is_job_found_in_file = false;
    char tmpID[500] = "";//TODO  you can open file and define in length that is bigger in 1 fro, file
    cout << "enter id of the job you want to submit\n";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(tmpID,500);
    strcat(tmpID, " ");
    for (int i = 0; i < all_jobs_arr_size; ++i)
    {
        if(all_jobs_arr[i]->getId().compare(tmpID) == 0)
        {
            is_job_found_in_file = true;
            cout <<"found jobb-----\n";
            all_jobs_arr[i]->setSubmitted();
        }

//        if(strcmp(all_jobs_arr[i]->getId(),tmpID) == 0)
    }
    if (!is_job_found_in_file)
        cout <<"----------coul NOT find jobb--------\n";
////////////////////////////////////


}


void Candidate :: updateSubmittedStatusFromFile()
{
    fstream file_submitted_jobs;

    char readFile[500];//TODO  you can open file and define in length that is bigger in 1 fro, file

    file_submitted_jobs.open("C:\\ObjectOrientedProgramming\\jobSearch\\submittedJobs",ios::in);
    if(!file_submitted_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        while (!file_submitted_jobs.eof()) {
            file_submitted_jobs >> readFile;
            if (strcmp(readFile, id) == 0) {
                while (strcmp(readFile, "endl") != 0) {
                    file_submitted_jobs >> readFile;
                    for (int i = 0; i < all_jobs_arr_size; ++i) {
                        if (readFile[strlen(readFile) - 1] >= '0' && readFile[strlen(readFile) - 1] <= '9')
                            strcat(readFile, " ");

                        if (all_jobs_arr[i]->getId().compare(readFile) == 0) {
                            all_jobs_arr[i]->setSubmitted();
                            cout << "chaned field sub _-------------" << endl;

                        }
                    }
                }
            }
        }


        file_submitted_jobs.close();
    }



}


void Candidate :: updateLikedtedStatusFromFile()
{

    fstream file_liked_jobs;

    char readFile[500];//TODO  you can open file and define in length that is bigger in 1 fro, file

    file_liked_jobs.open("C:\\ObjectOrientedProgramming\\jobSearch\\likedJobs",ios::in);
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
                            cout << "chaned field LIKED _-------------" << endl;

                        }
                    }
                }
            }
        }


        file_liked_jobs.close();
    }




}


void Candidate :: viewSubmissionHistory()
{
    cout << "inside view sub history"<<endl;

    for(int i = 0; i < all_jobs_arr_size; ++i)
        if (all_jobs_arr[i]->isSubmitted())//if job was submitted - print its details
            all_jobs_arr[i]->print();

}

void Candidate :: likeJob() {
    char tmpID[500] = "";//TODO  you can open file and define in length that is bigger in 1 fro, file
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "enter id of job you want to mark as liked" << endl;
    cin.getline(tmpID, 500);
    strcat(tmpID, " ");
    for (int i = 0; i < all_jobs_arr_size; ++i) {
        if (all_jobs_arr[i]->getId().compare(tmpID) == 0) {//cmp between strings
            cout << "found jobb---LIKED--\n";
            all_jobs_arr[i]->setLiked();
        }


    }
}

void Candidate :: viewLikedJjobs()
{
    cout << "inside view liked job"<<endl;

    for(int i = 0; i < all_jobs_arr_size; ++i)
        if (all_jobs_arr[i]->isLiked())//if job was submitted - print its details
            all_jobs_arr[i]->print();

}

void Candidate :: copyPersonalDetailsToFile()
{
    fstream file_personal_details;
    file_personal_details.open("C:\\ObjectOrientedProgramming\\jobSearch\\personalDetails.txt",ios::app);
    if(!file_personal_details.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        //copy all candidate details to "personalDetails" file
        file_personal_details << endl << "c " << id << " " << password << " " << userName << " " << email << " "
                              << phoneNumber << " " << birthDate << " " << freeTxt;
        file_personal_details.close();
    }

}

void Candidate :: copyCVToFile()
{

    fstream file_cv;

    //copy CV to
    file_cv.open("C:\\ObjectOrientedProgramming\\jobSearch\\CV.txt",ios::app);
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

    file_submitted_jobs.open("C:\\ObjectOrientedProgramming\\jobSearch\\submittedJobs",ios::app);
    if(!file_submitted_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {

        bool isSubmitExists = false;
        for (int i = 0; i < all_jobs_arr_size; ++i)
            if (all_jobs_arr[i]->isSubmitted())
                isSubmitExists = true;

        if (isSubmitExists) {
            file_submitted_jobs << id << " ";
            for (int i = 0; i < all_jobs_arr_size; ++i) {
                if (all_jobs_arr[i]->isSubmitted()) { //if job was submitted, add its id to file
                    cout << "GET ID=" << all_jobs_arr[i]->getId() << endl;
                    file_submitted_jobs << all_jobs_arr[i]->getId() << " ";
                    cout << "coping sub job-----------\n";
                }

            }
            file_submitted_jobs << "endl" << endl;
        }
        file_submitted_jobs.close();

    }


}

void Candidate :: copyLikedJobsToFile() {

//TODO open and close file
    fstream file_liked_jobs;

    file_liked_jobs.open("C:\\ObjectOrientedProgramming\\jobSearch\\likedJobs",ios::app);
    if(!file_liked_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {

        bool isLikedExists = false;
        for (int i = 0; i < all_jobs_arr_size; ++i)
            if (all_jobs_arr[i]->isLiked())
                isLikedExists = true;

        if (isLikedExists) {
            file_liked_jobs << id << " ";
            for (int i = 0; i < all_jobs_arr_size; ++i) {
                if (all_jobs_arr[i]->isLiked()) { //if job was submitted, add its id to file
//                    cout << "GET ID=" << all_jobs_arr[i]->getId() << endl;
                    file_liked_jobs << all_jobs_arr[i]->getId() << " ";
                    cout << "coping liked job-----------\n";
                }

            }
            file_liked_jobs << "endl" << endl;
        }
        file_liked_jobs.close();

    }
    ////////////////////check if work
}


void Candidate :: filterJobsByFeatures() {

    bool north = false, south = false, center = false, haifa = false, telAviv = false, judeaAndSamaria = false;

    bool full_time = false, part_time = false, student = false, special_needs = false;

    bool teaching = false, engineering = false, law = false, medicine = false,
            research = false, sales = false ,restaurants = false, cleaning = false, economy = false;


    char nav_filter_job = '\0';


    cout << "1- location \n";
    cout << "2- job type \n";
    cout << "3- role \n";
//        cout << "4- back to  \n";

    cin >> nav_filter_job;


    switch (nav_filter_job) {

        case LOCATION_F: {


            char nav_location;
            do {

                cout << "job location" << endl << "choose from the following:" << endl;
                cout << "1- north \n";
                cout << "2- south \n";
                cout << "3- center \n";
                cout << "4- haifa \n";
                cout << "5- Tel aviv \n";
                cout << "6- Judea and Samaria \n";
                cout << "7- to filter chosen location \n";

                cin >> nav_location;

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
                }


            }while (nav_location != '7');

//            break;
        }
        case JOB_TYPE_F: {


            char nav_job_type;
            do {

                cout << "job type" << endl << "choose from the following:" << endl;
                cout << "1- full time \n";
                cout << "2- part time \n";
                cout << "3- student \n";
                cout << "4- special needs \n";
                cout << "5- to filter chosen job type \n";

                cin >> nav_job_type;
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
                }
            }
            while (nav_job_type != '5');
//            break;

        }

        case ROLE_F: {


            char nav_role;

            do {

                cout << "role" << endl << "choose from the following:" << endl;
                cout << "1- teaching \n";
                cout << "2- engineering \n";
                cout << "3- law \n";
                cout << "4- medicine \n";
                cout << "5- research \n";
                cout << "6- sales \n";
                cout << "7- restaurants \n";
                cout << "8- cleaning \n";
                cout << "9- economy \n";
                cout << "0- to filter chosen job type \n";

                cin >> nav_role;

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


                }
            } while (nav_role != '0');



//            break;
        }
    }


    //print jobs who meet user selections


    for (int i = 0; i < all_jobs_arr_size; ++i) {
        bool match = true;


        if (north && strcmp(all_jobs_arr[i]->getLocation(), "north ") != 0) match = false;
        else if (south && strcmp(all_jobs_arr[i]->getLocation(), "south ") != 0) match = false;
        else if (center && strcmp(all_jobs_arr[i]->getLocation(), "center ") != 0) match = false;
        else if (haifa && strcmp(all_jobs_arr[i]->getLocation(), "haifa ") != 0) match = false;
        else if (telAviv && strcmp(all_jobs_arr[i]->getLocation(), "telAviv ") != 0) match = false;
        else if (judeaAndSamaria && strcmp(all_jobs_arr[i]->getLocation(),"judeaAndSamaria ") != 0) match = false;


        if (full_time && strcmp(all_jobs_arr[i]->getJobType(), "fullTime ")) match = false;
        else if (part_time && strcmp(all_jobs_arr[i]->getJobType(), "partTime ")) match = false;
        else if (student && strcmp(all_jobs_arr[i]->getJobType(), "student ")) match = false;
        else if (special_needs && strcmp(all_jobs_arr[i]->getJobType(), "specialNeeds ")) match = false;


        if (teaching && strcmp(all_jobs_arr[i]->getJobType(), "teaching ")) match = false;
        else if (engineering && strcmp(all_jobs_arr[i]->getJobType(), "engineering ")) match = false;
        else if (law && strcmp(all_jobs_arr[i]->getJobType(), "law ")) match = false;
        else if (medicine && strcmp(all_jobs_arr[i]->getJobType(), "medicine ")) match = false;
        else if (research && strcmp(all_jobs_arr[i]->getJobType(), "research ")) match = false;
        else if (sales && strcmp(all_jobs_arr[i]->getJobType(), "sales ")) match = false;
        else if (restaurants && strcmp(all_jobs_arr[i]->getJobType(), "restaurants ")) match = false;
        else if (cleaning && strcmp(all_jobs_arr[i]->getJobType(), "cleaning ")) match = false;
        else if (economy && strcmp(all_jobs_arr[i]->getJobType(), "economy ")) match = false;


        //print job after filtration
        if (match)
            all_jobs_arr[i]->print();


    }









}

