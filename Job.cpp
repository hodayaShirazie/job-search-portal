//
// Created by Student on 21/02/2024.
//
#include "Job.h"
#include "Candidate.h"



//constructor with no parameters
Job :: Job():submitted(false),liked(false),jobApplicants(NULL),jobApplicantsSize(0)
{

    readMaxIdFromFiles();
    ++max_id;
    char buffer[80];

    //getting company name
    setCompanyName();


    //getting role
    setRole();


    //getting job description
    setJobDescription();




    //getting job requirements
    setJobRequirements();



    //job type
    setJobType();



    //getting job conditions
    setJobCondition();




    //getting job location
    setLocation();


    //getting job date
    today();

    //job id
    id = to_string(max_id); //convert max id to string and save in id of job

    insertMaxIdToFiles(); //save id of last job ID in file

}


//constructor with parameters
Job :: Job(char *company_name, char* role, char* job_description, char* job_requirements,
    char* job_type, char* job_condition, char* location, string id, int day, int month,int year):submitted(false),liked(false),jobApplicants(NULL),jobApplicantsSize(0)
{

    this->company_name = new char[strlen(company_name) + 1];
    strcpy(this->company_name,company_name);

    this->role = new char[strlen(role) + 1];
    strcpy(this->role,role);

    this->job_description = new char[strlen(job_description) + 1];
    strcpy(this->job_description,job_description);

    this->job_requirements = new char[strlen(job_requirements) + 1];
    strcpy(this->job_requirements,job_requirements);

    this->job_type = new char[strlen(job_type) + 1];
    strcpy(this->job_type,job_type);

    this->job_condition = new char[strlen(job_condition) + 1];
    strcpy(this->job_condition,job_condition);

    this->location = new char[strlen(location) + 1];
    strcpy(this->location,location);

    this->id = id;

    this->publishedDay = day;

    this->publishedMonth = month;

    this->publishedYear = year;


}

//distructor
Job :: ~Job()
{
    //dis-allocating memory
    delete [] company_name;
    delete [] role;
    delete [] job_description;
    delete [] job_requirements;
    delete [] job_type;
    delete [] job_condition;
    delete [] location;

    company_name = NULL;
    role = NULL;
    job_description = NULL;
    job_requirements = NULL;
    job_type = NULL;
    job_condition = NULL;
    location = NULL;

    delete [] jobApplicants;


}


//copy constructor
Job :: Job(const Job& job)
{
    company_name = NULL;
    role = NULL;
    job_description = NULL;
    job_requirements = NULL;
    job_type = NULL;
    job_condition = NULL;
    location = NULL;

    *this = job; //call operator=
}


//operator=
Job& Job :: operator=(const Job& job)
{
    //dis-allocating memory
    delete [] company_name;
    delete [] role;
    delete [] job_description;
    delete [] job_requirements;
    delete [] job_type;
    delete [] job_condition;
    delete [] location;


    company_name = new char[strlen(job.company_name)+1];
    strcpy(company_name, job.company_name);

    role = new char[strlen(job.role)+1];
    strcpy(role, job.role);

    job_description = new char[strlen(job.job_description)+1];
    strcpy(job_description, job.job_description);

    job_type = new char[strlen(job.job_type)+1];
    strcpy(job_type, job.job_type);

    job_condition = new char[strlen(job.job_condition)+1];
    strcpy(job_condition, job.job_condition);

    location = new char[strlen(job.location)+1];
    strcpy(location, job.location);

    publishedDay = job.publishedDay;
    publishedMonth = job.publishedMonth;
    publishedYear = job.publishedYear;


    id = job.id;

    return *this;

}


//getters
string Job::getId() const {
    return id;
}

char *Job::getCompanyName() const {
    return company_name;
}

char *Job::getRole() const {
    return role;
}

char *Job::getJobDescription() const {
    return job_description;
}

char *Job::getJobRequirements() const {
    return job_requirements;
}

char *Job::getJobType() const {
    return job_type;
}

char *Job::getJobCondition() const {
    return job_condition;
}

char *Job::getLocation() const {
    return location;
}


bool Job::isSubmitted() const {
    return submitted;
}

bool Job::isLiked() const {
    return liked;
}

Candidate **Job::getJobApplicants() const {
    return jobApplicants;
}

int Job::getJobApplicantsSize() const {
    return jobApplicantsSize;
}

int Job::getMonth() const {
    return publishedMonth;
}

int Job::getDay() const {
    return publishedDay;
}

int Job::getYear() const {
    return publishedYear;
}



//setters
void Job:: setSubmitted()
{
    submitted = true; //change field submitted
}

void Job:: setLiked()
{
    liked = true;  //change field liked
}

void Job:: setUnLiked()
{
    liked = false;
}

void Job::setCompanyName() {

    char buffer[102];
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    //getting company name

    Colors color;

    color.setColorANSI(34);
    cout << "company name" << endl;
    color.setColorANSI(0);

    cin.getline(buffer,102);
    while ( std::cin.fail() || strlen(buffer) > 30) {
        std::cin.clear(); // Clears the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        color.setColorANSI(31);
        cout << "invalid input, try again" << endl;
        color.setColorANSI(0);


        cin.getline(buffer,102);
    }
    company_name = new char[strlen(buffer)+1];
    strcpy(company_name, buffer);

}

void Job::setRole() {

    bool validInput = false; // Flag to track if the input is valid
    Colors color;
    char nav_role;
    while(!validInput) {

        color.setColorANSI(34);
        cout << "role" << endl;
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


        cin >> nav_role;

        while (std::cin.fail() ||(nav_role != '1' && nav_role != '2' && nav_role != '3' && nav_role != '4' && nav_role != '5' && nav_role != '6' && nav_role != '7' && nav_role != '8' && nav_role != '9')) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            color.setColorANSI(31);
            cout << "invalid input, selection must be in range 1-9" << endl;
            color.setColorANSI(0);

            cin >> nav_role;
        }

        switch (nav_role) {
            case TEACHING: {
                role = new char[strlen("teaching") + 1];
                strcpy(role, "teaching");
                validInput = true;
                break;
            }
            case ENGINEERING: {
                role = new char[strlen("engineering") + 1];
                strcpy(role, "engineering");
                validInput = true;
                break;
            }
            case LAW: {
                role = new char[strlen("law") + 1];
                strcpy(role, "law");
                validInput = true;
                break;
            }
            case MEDICINE: {
                role = new char[strlen("medicine") + 1];
                strcpy(role, "medicine");
                validInput = true;
                break;
            }
            case RESEARCH: {
                role = new char[strlen("research") + 1];
                strcpy(role, "research");
                validInput = true;
                break;
            }
            case SALES: {
                role = new char[strlen("sales") + 1];
                strcpy(role, "sales");
                validInput = true;
                break;
            }
            case RESTAURANTS: {
                role = new char[strlen("restaurants") + 1];
                strcpy(role, "restaurants");
                validInput = true;
                break;
            }
            case CLEANING: {
                role = new char[strlen("cleaning") + 1];
                strcpy(role, "cleaning");
                validInput = true;
                break;
            }
            case ECONOMY: {
                role = new char[strlen("economy") + 1];
                strcpy(role, "economy");
                validInput = true;
                break;
            }
            default: {

                break;
            }


        }
    }

}

void Job::setJobDescription() {

    char buffer[300];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Colors color;

    color.setColorANSI(34);
    cout << "job description"<<endl;
    color.setColorANSI(0);


    color.setColorANSI(90);
    cout << "--to skip, enter \"none\"--" << endl;
    color.setColorANSI(39);

    cin.getline(buffer,300);
    while ( std::cin.fail() || strlen(buffer) > 280) {
        std::cin.clear(); // Clears the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        color.setColorANSI(31);
        cout << "invalid input, try again" << endl;
        color.setColorANSI(0);

        cin.getline(buffer,300);
    }


    job_description = new char[strlen(buffer)+1];
    strcpy(job_description, buffer);



}

void Job::setJobRequirements() {
    char buffer[200];
    Colors color;

    color.setColorANSI(34);
    cout << "job requirements"<<endl;
    color.setColorANSI(0);


    color.setColorANSI(90);
    cout << "you might want to include the following suggestions: degree, languages, "
            "experience,\n valid licence holder, personal skills...\n--to skip, enter \"none\"--" << endl;
    color.setColorANSI(39);

    cin.getline(buffer,200);
    while ( std::cin.fail() || strlen(buffer) > 100) {
        std::cin.clear(); // Clears the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        color.setColorANSI(31);
        cout << "invalid input, try again" << endl;
        color.setColorANSI(0);

        cin.getline(buffer,200);
    }


    job_requirements = new char[strlen(buffer)+1];
    strcpy(job_requirements, buffer);


}

void Job::setJobType() {

    bool validInput = false;
    Colors color;
    while(!validInput) {

        char nav_type;

        color.setColorANSI(34);
        cout << "job type" << endl;
        color.setColorANSI(0);

        cout << "choose from the following:" << endl;

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

        cin >> nav_type;

        while (std::cin.fail() || (nav_type != '1' && nav_type != '2' && nav_type != '3' && nav_type != '4')) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            color.setColorANSI(31);
            cout << "invalid input, selection must be in range 1-4" << endl;
            color.setColorANSI(0);

            cin >> nav_type;
        }


        switch (nav_type) {
            case FULL_TIME: {
                job_type = new char[strlen("fullTime") + 1];
                strcpy(job_type, "fullTime");
                validInput = true;
                break;
            }
            case PART_TIME: {
                job_type = new char[strlen("partTime") + 1];
                strcpy(job_type, "partTime");
                validInput = true;
                break;
            }
            case STUDENT: {
                job_type = new char[strlen("student") + 1];
                strcpy(job_type, "student");
                validInput = true;
                break;
            }
            case SPECIAL_NEEDS: {
                job_type = new char[strlen("specialNeeds") + 1];
                strcpy(job_type, "specialNeeds");
                validInput = true;
                break;
            }
            default: {

                Colors color;

                color.setColorANSI(31);
                cout << "Invalid input. Please choose a valid option." << endl;
                color.setColorANSI(0);

                // Optionally clear the input buffer in case of invalid input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // No need to set validInput to false as it's already false
                break;
            }


        }
    }

}

void Job::setJobCondition() {
    Colors color;
    char buffer[100];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    color.setColorANSI(34);
    cout << "job conditions"<<endl;
    color.setColorANSI(90);
    cout << "you might want to include the following suggestions: wage, transportation, "
            " car job, \"TenBis \" discount.\n--to skip, enter \"none\"--" << endl;
    color.setColorANSI(39);



    cin.getline(buffer,100);
    while ( std::cin.fail() || strlen(buffer) > 50) {
        std::cin.clear(); // Clears the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        color.setColorANSI(31);
        cout << "invalid input, try again" << endl;
        color.setColorANSI(0);

        cin.getline(buffer,100);
    }

//    cin.ignore();
    job_condition = new char[strlen(buffer)+1];
    strcpy(job_condition, buffer);



}

void Job::setLocation() {


    char nav_location;

    Colors color;
    bool validInput = false;

    while(!validInput) {

        color.setColorANSI(34);
        cout << "job location" << endl;
        color.setColorANSI(39);

        cout << "choose from the following:" << endl;

        color.setColorANSI(33);
        cout << "1";
        color.setColorANSI(39);
        cout << "- north \n";

        color.setColorANSI(33);
        cout << "2";
        color.setColorANSI(39);
        cout << "- south \n";

        color.setColorANSI(33);
        cout << "3";
        color.setColorANSI(39);
        cout << "- center \n";

        color.setColorANSI(33);
        cout << "4";
        color.setColorANSI(39);
        cout << "- haifa \n";

        color.setColorANSI(33);
        cout << "5";
        color.setColorANSI(39);
        cout << "- Tel aviv \n";


        color.setColorANSI(33);
        cout << "6";
        color.setColorANSI(39);
        cout << "- Judea and Samaria \n";


        cin >> nav_location;
        while (std::cin.fail() || (nav_location != '1' && nav_location != '2' && nav_location != '3' && nav_location != '4' && nav_location != '5' && nav_location != '6')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            color.setColorANSI(31);
            cout << "invalid input, selection must be in range 1-6" << endl;
            color.setColorANSI(0);

            cin >> nav_location;
        }

        switch (nav_location) {
            case NORTH: {
                location = new char[strlen("north") + 1];
                strcpy(location, "north");
                validInput = true;
                break;
            }
            case SOUTH: {
                location = new char[strlen("south") + 1];
                strcpy(location, "south");
                validInput = true;
                break;
            }
            case CENTER: {
                location = new char[strlen("center") + 1];
                strcpy(location, "center");
                validInput = true;
                break;
            }
            case HAIFA: {
                location = new char[strlen("haifa") + 1];
                strcpy(location, "haifa");
                validInput = true;
                break;
            }
            case TEL_AVIV: {
                location = new char[strlen("telAviv") + 1];
                strcpy(location, "telAviv");
                validInput = true;
                break;
            }
            case JUDEA_AND_SAMARIA: {
                location = new char[strlen("judeaAndSamaria") + 1];
                strcpy(location, "judeaAndSamaria");
                validInput = true;
                break;
            }
            default: {
                Colors color;

                color.setColorANSI(31);
                cout << "Invalid input. Please choose a valid option." << endl;
                color.setColorANSI(39);

                // Optionally clear the input buffer in case of invalid input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // No need to set validInput to false as it's already false
                break;
            }

        }
    }

}



void Job::setJobApplicants(Candidate **jobApplicants) {
    this->jobApplicants = jobApplicants;
}

void Job::setJobApplicantsSize(int jobApplicantsSize) {
    this->jobApplicantsSize = jobApplicantsSize;
}


//print functions
void Job :: print() const
{

    Colors color;
    color.setColorANSI(90);;
    cout << "----------------------------------------- job id: "<< id << "------------------------------------------------------------ " << endl;
    color.setColorANSI(39);

    std::cout.flush();
    color.enableVirtualTerminalProcessing();

    if(liked) {

        SetConsoleOutputCP(CP_UTF8);

        // Enable buffering to prevent VS from injecting its own console code
        setvbuf(stdout, nullptr, _IOFBF, 1000);

        color.setColorANSI(31); // Set text color to red.
        cout << "♥  ";// Print heart symbol

        color.setColorANSI(0);


        std::cout.flush();
    } else {
        SetConsoleOutputCP(CP_UTF8);
        color.setColorANSI(31); // Set text color to red.
        cout << "\xE2\x99\xA1  ";// UTF-8 encoding for U+2661 ('♡') is E2 99 A1
        color.setColorANSI(0);



        std::cout.flush();
    }
    if(submitted) {
        color.setColorANSI(32); // Set text color to red.
        cout << "submitted  ";
        color.setColorANSI(0);

        std::cout.flush();
    }
    cout << "posted in: " << publishedDay << "." << publishedMonth << "." << publishedYear << endl;





    color.setColorANSI(34);
    cout << "\ncompany name: " << endl;
    color.setColorANSI(39);
    std::cout.flush();
    cout << company_name << endl << endl;

    color.setColorANSI(34);
    cout << "role: " << endl;
    color.setColorANSI(39);
    std::cout.flush();
    cout << role << endl << endl;


    if(strcmp(job_description, "none ") != 0) {
        color.setColorANSI(34);;
        cout << "job description: " << endl;
        color.setColorANSI(39);
        std::cout.flush();
        cout << job_description << endl << endl;
    }

    if(strcmp(job_requirements, "none ") != 0) {

        color.setColorANSI(34);;
        cout << "job requirements: " << endl;
        color.setColorANSI(39);
        std::cout.flush();
        cout << job_requirements << endl << endl;
    }

    color.setColorANSI(34);
    cout << "job type: " << endl;
    color.setColorANSI(39);
    std::cout.flush();
    cout << job_type << endl << endl;

    if(strcmp(job_condition, "none ") != 0 ) {
        color.setColorANSI(34);;
        cout << "job condition:" << endl;
        color.setColorANSI(39);
        std::cout.flush();
        cout << job_condition << endl << endl;
    }

    color.setColorANSI(34);
    cout << "location: " << endl;
    color.setColorANSI(39);;
    std::cout.flush();
    cout << location << endl << endl;


    color.setColorANSI(90);
    cout << "----------------------------------------------------------------------------------------------------------------- " << endl;
    color.setColorANSI(39);
    std::cout.flush();



}

void Job:: printJobApplicants() {
    Colors color;
    for (int i = 0; i < jobApplicantsSize; ++i) {

        color.setColorANSI(90);
        cout << "----------------------------------------------------------------------------------\n";
        color.setColorANSI(39);

        if(strcmp(jobApplicants[i]->getFreeTxt(),"none ") != 0) {
            color.setColorANSI(34);
            cout << "----------------------------------about me---------------------------------------------------------\n";
            color.setColorANSI(39);

            cout << jobApplicants[i]->getFreeTxt() << endl;

            color.setColorANSI(34);
            cout << "---------------------------------------------------------------------------------------------------\n";
            color.setColorANSI(39);
        }

        jobApplicants[i]->getCv()->print();//printing CV's of candidates

        color.setColorANSI(90);
        cout << "----------------------------------------------------------------------------------\n";
        color.setColorANSI(39);

    }
}


//function that update job details
void Job :: updateJob()
{
    char nav_update_job;

    do {
        Colors color;
        color.setColorANSI(33);
        cout << "1";
        color.setColorANSI(39);
        cout << "- company name \n";

        color.setColorANSI(33);
        cout << "2";
        color.setColorANSI(39);
        cout << "- role\n";

        color.setColorANSI(33);
        cout << "3";
        color.setColorANSI(39);
        cout << "- job description \n";

        color.setColorANSI(33);
        cout << "4";
        color.setColorANSI(39);
        cout << "- job requirements \n";

        color.setColorANSI(33);
        cout << "5";
        color.setColorANSI(39);
        cout << "- job type\n";

        color.setColorANSI(33);
        cout << "6";
        color.setColorANSI(39);
        cout << "- job condition \n";

        color.setColorANSI(33);
        cout << "7";
        color.setColorANSI(39);
        cout << "- location \n";

        color.setColorANSI(33);
        cout << "8";
        color.setColorANSI(39);
        cout << "- update \n";



        cin >> nav_update_job;
//        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        switch (nav_update_job) {
            case COMPANY_NAME: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                delete [] company_name;
                setCompanyName();
                break;
            }
            case ROLE: {
                delete [] role;
                setRole();
                break;
            }
            case JOB_DESCRIPTION: {
                delete [] job_description;
                setJobDescription();
                break;
            }
            case JOB_REQUIREMENTS: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                delete [] job_requirements;
                setJobRequirements();
                break;
            }
            case JOB_TYPE: {
                delete [] job_type;
                setJobType();
                break;
            }
            case JOB_CONDITION: {
                delete [] job_condition;
                setJobCondition();
                break;
            }
            case LOCATION: {
                delete [] location;
                setLocation();
                break;
            }
            case BACK_ALL_SUB_J: {
                //navigate user to all submitted jobs
                break;
            }
            default: {
                //navigate user to all submitted jobs
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
    } while (nav_update_job != BACK_ALL_SUB_J); //keep showing options for adaptation until user back in all submitted jobs



}


//function that creates a string which is the date the function was called
void Job :: today() {

    time_t rawtime;
    tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    publishedMonth = timeinfo->tm_mon + 1;
    publishedDay = timeinfo->tm_mday;
    publishedYear = timeinfo->tm_year + 1900;

}


//function that read id from general file and update field
void Job:: readMaxIdFromFiles() {


    fstream file_general;
    file_general.open("C:\\ObjectOrientedProgramming\\job-search-portal\\uniqueId.txt", ios::in);
    if (!file_general.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        file_general >> max_id;
    }

}


//function that update general to contain max id
void Job:: insertMaxIdToFiles() {

    fstream file_general;
    file_general.open("C:\\ObjectOrientedProgramming\\job-search-portal\\uniqueId.txt", ios::out);
    if (!file_general.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        file_general << max_id;
    }

}

void Job:: printJobForEmployer()
{

    Colors color;
    color.setColorANSI(90);
    cout << "----------------------------------------- job id: "<< id << "------------------------------------------------------------ " << endl;
    color.setColorANSI(39);

    cout << "posted in: " << publishedDay << "." << publishedMonth << "." << publishedYear << endl;

    color.setColorANSI(34);
    cout << "\ncompany name: " << endl;
    color.setColorANSI(39);
    std::cout.flush();
    cout << company_name << endl << endl;

    color.setColorANSI(34);
    cout << "role: " << endl;
    color.setColorANSI(39);
    std::cout.flush();
    cout << role << endl << endl;

    if(strcmp(job_description, "none ") != 0 && strcmp(job_description, "none") != 0) {
        color.setColorANSI(34);
        cout << "job description: " << endl;
        color.setColorANSI(39);
        std::cout.flush();
        cout << job_description << endl << endl;
    }
    if(strcmp(job_requirements, "none ") != 0 && strcmp(job_requirements, "none") != 0) {
        color.setColorANSI(34);
        cout << "job requirements: " << endl;
        color.setColorANSI(39);
        std::cout.flush();
        cout << job_requirements << endl << endl;
    }

    color.setColorANSI(34);
    cout << "job type: " << endl;
    color.setColorANSI(39);
    std::cout.flush();
    cout << job_type << endl << endl;

    if(strcmp(job_condition, "none ") != 0 && strcmp(job_condition, "none") != 0) {
        color.setColorANSI(34);
        cout << "job condition:" << endl;
        color.setColorANSI(39);
        std::cout.flush();
        cout << job_condition << endl << endl;
    }

    color.setColorANSI(34);
    cout << "location: " << endl;
    color.setColorANSI(39);
    std::cout.flush();
    cout << location << endl << endl;


    color.setColorANSI(90);
    cout << "----------------------------------------------------------------------------------------------------------------- " << endl;
    color.setColorANSI(39);
    std::cout.flush();

}
