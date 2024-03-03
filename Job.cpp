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
//    clearInputBuffer();


    //getting role
    setRole();
//    clearInputBuffer();




    //getting job description
    setJobDescription();
//    clearInputBuffer();




    //getting job requirements
    setJobRequirements();
//    clearInputBuffer();



    //job type
    setJobType();
//    clearInputBuffer();



    //getting job conditions
    setJobCondition();
//    clearInputBuffer();




    //getting job location
    setLocation();
//    clearInputBuffer();


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

    this->day = day;

    this->month = month;

    this->year = year;


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
    //TODO add deleting all dynamic fields



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

    day = job.day;
    month = job.month;
    year = job.year;


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
    return month;
}

int Job::getDay() const {
    return day;
}

int Job::getYear() const {
    return year;
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
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "company name" << endl;
    color.setConsoleColor(7);

//    cin.clear();
    cin.getline(buffer,102);
    company_name = new char[strlen(buffer)+1];
    strcpy(company_name, buffer);

}

void Job::setRole() {

    bool validInput = false; // Flag to track if the input is valid
    Colors color;
    char nav_role;
    while(!validInput) {
        color.setConsoleColor( FOREGROUND_BLUE );
        cout << "role" << endl;
        color.setConsoleColor(7);
        cout << "choose from the following:" << endl;
        cout << "1- teaching \n";
        cout << "2- engineering \n";
        cout << "3- law \n";
        cout << "4- medicine \n";
        cout << "5- research \n";
        cout << "6- sales \n";
        cout << "7- restaurants \n";
        cout << "8- cleaning \n";
        cout << "9- economy \n";
        cin >> nav_role;

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
                Colors color;
                color.setConsoleColor( FOREGROUND_RED );
                cout << "Invalid input. Please choose a valid option." << endl;
                color.setConsoleColor(7);
                // Optionally clear the input buffer in case of invalid input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // No need to set validInput to false as it's already false
                break;
            }


        }
    }

}

void Job::setJobDescription() {

    char buffer[300];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Colors color;
    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "job description"<<endl;
    color.setConsoleColor(7);
    cout << "to skip, enter \"none\"" << endl;
//    cin.ignore();
    cin.getline(buffer,300);
    job_description = new char[strlen(buffer)+1];
    strcpy(job_description, buffer);



}

void Job::setJobRequirements() {
    char buffer[101];
    Colors color;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');

//    cin.ignore();

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "job requirements"<<endl;
//    color.setConsoleColor(7);


    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "you might want to include the following suggestions: degree, languages, "
            "experience,\n valid licence holder, personal skills...\n -to skip, enter \"none\"-" << endl;
    color.setConsoleColor(7);

    cin.getline(buffer,101);
    job_requirements = new char[strlen(buffer)+1];
    strcpy(job_requirements, buffer);

//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


}

void Job::setJobType() {

    bool validInput = false;
    Colors color;
    while(!validInput) {

        char nav_type;

        color.setConsoleColor( FOREGROUND_BLUE );
        cout << "job type" << endl;
        color.setConsoleColor(7);
        cout << "choose from the following:" << endl;
        cout << "1- full time \n";
        cout << "2- part time \n";
        cout << "3- student \n";
        cout << "4- special needs \n";
        cin >> nav_type;
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
                color.setConsoleColor( FOREGROUND_RED );
                cout << "Invalid input. Please choose a valid option." << endl;
                color.setConsoleColor(7);
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
    char buffer[300];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

//    cin.ignore();

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "job conditions"<<endl;

    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "you might want to include the following suggestions: wage, transportation, "
            " car job, \"TenBis \" discount. -to skip, enter \"none\"" << endl;
    color.setConsoleColor(7);

    cin.getline(buffer,300);
//    cin.ignore();
    job_condition = new char[strlen(buffer)+1];
    strcpy(job_condition, buffer);



}

void Job::setLocation() {


    char nav_location;

    Colors color;
    bool validInput = false;

    while(!validInput) {
        color.setConsoleColor( FOREGROUND_BLUE );
        cout << "job location" << endl;
        color.setConsoleColor(7);

        cout << "choose from the following:" << endl;
        cout << "1- north \n";
        cout << "2- south \n";
        cout << "3- center \n";
        cout << "4- haifa \n";
        cout << "5- Tel aviv \n";
        cout << "6- Judea and Samaria \n";
        cin >> nav_location;
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
                color.setConsoleColor( FOREGROUND_RED );
                cout << "Invalid input. Please choose a valid option." << endl;
                color.setConsoleColor(7);

                // Optionally clear the input buffer in case of invalid input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // No need to set validInput to false as it's already false
                break;
            }

        }
    }

}

//void Job::clearInputBuffer() {
//    // If cin fails or reaches EOF, clear its state to allow further operations.
//    if (std::cin.fail() || std::cin.eof()) {
//        std::cin.clear();
//    }
//
//    // Peek the next character in the buffer
//    if (std::cin.peek() != std::char_traits<char>::eof()) {
//        // Ignore the rest of the line up to the maximum streamsize value
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    }
//}

void Job::setJobApplicants(Candidate **jobApplicants) {
    this->jobApplicants = jobApplicants;
}

void Job::setJobApplicantsSize(int jobApplicantsSize) {
    this->jobApplicantsSize = jobApplicantsSize;
}


//print functions
void Job :: print() const
{
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //TODO fix colors!!!!
    Colors color;
    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "----------------------------------------- job id: "<< id << "------------------------------------------------------------ " << endl;
    color.setConsoleColor(7);

    std::cout.flush();

    if(liked) {
        SetConsoleOutputCP(CP_UTF8);
        color.setConsoleColor(FOREGROUND_RED);

        // Set console code page to UTF-8 so console known how to interpret string data
//        SetConsoleOutputCP(CP_UTF8);

        // Enable buffering to prevent VS from injecting its own console code
        setvbuf(stdout, nullptr, _IOFBF, 1000);

        // Print heart symbol
        cout << "♥  ";

        color.setConsoleColor(7);
        std::cout.flush();
    } else {
        SetConsoleOutputCP(CP_UTF8);
        color.setConsoleColor(FOREGROUND_RED);
        cout << "\xE2\x99\xA1  ";// UTF-8 encoding for U+2661 ('♡') is E2 99 A1
        color.setConsoleColor(7);

        std::cout.flush();
    }
    if(submitted) {
        color.setConsoleColor(FOREGROUND_GREEN);
        cout << "submitted  ";
        color.setConsoleColor(7);

        std::cout.flush();
    }
    cout << "posted in: " << day << "." << month << "." << year << endl;





    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "\ncompany name: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << company_name << endl << endl;

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "role: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << role << endl << endl;


    if(strcmp(job_description, "none ") != 0) {
        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "job description: " << endl;
        color.setConsoleColor(7);
        std::cout.flush();
        cout << job_description << endl << endl;
    }

    if(strcmp(job_requirements, "none ") != 0) {

        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "job requirements: " << endl;
        color.setConsoleColor(7);
        std::cout.flush();
        cout << job_requirements << endl << endl;
    }

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "job type: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << job_type << endl << endl;

    if(strcmp(job_condition, "none ") != 0 ) {
        color.setConsoleColor(FOREGROUND_BLUE);
        cout << "job condition:" << endl;
        color.setConsoleColor(7);
        std::cout.flush();
        cout << job_condition << endl << endl;
    }

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "location: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << location << endl << endl;


    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "----------------------------------------------------------------------------------------------------------------- " << endl;
    color.setConsoleColor(7);
    std::cout.flush();



}

void Job:: printJobApplicants() {
    Colors color;
    for (int i = 0; i < jobApplicantsSize; ++i) {

        color.setConsoleColor(FOREGROUND_INTENSITY);
        cout << "----------------------------------------------------------------------------------\n";
        color.setConsoleColor(7);

        if(strcmp(jobApplicants[i]->getFreeTxt(),"none ") != 0) {
            color.setConsoleColor(FOREGROUND_BLUE);
            cout << "----------------------------------about me-------------------------------------\n";
            color.setConsoleColor(7);

            cout << jobApplicants[i]->getFreeTxt() << endl;

            color.setConsoleColor(FOREGROUND_BLUE);
            cout << "-------------------------------------------------------------------------------\n";
            color.setConsoleColor(7);
        }

        jobApplicants[i]->getCv()->print();//printing CV's of candidates

        color.setConsoleColor(FOREGROUND_INTENSITY);
        cout << "----------------------------------------------------------------------------------\n";
        color.setConsoleColor(7);

    }
}


//function that update job details
void Job :: updateJob()
{
    char nav_update_job;

    do {

        cout << "1- company name \n";
        cout << "2- role\n";
        cout << "3- job description \n";
        cout << "4- job requirements \n";
        cout << "5- job type\n";
        cout << "6- job condition \n";
        cout << "7- location \n";
        cout << "8- update \n";


        cin >> nav_update_job;
//        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        switch (nav_update_job) {
            case COMPANY_NAME: {
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
    month = timeinfo->tm_mon + 1;
    day = timeinfo->tm_mday;
    year = timeinfo->tm_year + 1900;

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
    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "----------------------------------------- job id: "<< id << "------------------------------------------------------------ " << endl;
    color.setConsoleColor(7);

    cout << "posted in: " << day << "." << month << "." << year << endl;

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "\ncompany name: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << company_name << endl << endl;

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "role: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << role << endl << endl;

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "job description: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << job_description << endl << endl;

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "job requirements: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << job_requirements << endl << endl;

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "job type: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << job_type << endl << endl;

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "job condition:" << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << job_condition << endl << endl;

    color.setConsoleColor( FOREGROUND_BLUE );
    cout << "location: " << endl;
    color.setConsoleColor(7);
    std::cout.flush();
    cout << location << endl << endl;


    color.setConsoleColor( FOREGROUND_INTENSITY );
    cout << "----------------------------------------------------------------------------------------------------------------- " << endl;
    color.setConsoleColor(7);
    std::cout.flush();



}
