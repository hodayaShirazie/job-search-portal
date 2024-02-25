//
// Created by Student on 21/02/2024.
//
#include <limits> // Include for std::numeric_limits
#include "Job.h"
//#include <cstdlib>

//int Job :: general_id = 0;
//int Job :: max_id = general_id + 1;



//void setConsoleColor(WORD c)
//{
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
//}



Job :: Job():submitted(false)
{
    getMaxIdFromFiles();
    ++max_id;
    char buffer[80];

    //getting company name
    cout << "company name" << endl;
    cin.ignore();
    cin.getline(buffer,102);
    company_name = new char[strlen(buffer)+1];
    strcpy(company_name, buffer);


    //getting role
    get_role_input();



    //job description
    cout << "job description. to skip, enter \"none\"" << endl;
    cin.ignore();
    cin.getline(buffer,101);
    job_description = new char[strlen(buffer)+1];
    strcpy(job_description, buffer);

//    cin.ignore();
    //job requirements
    cout << "job requirements. you might want to include the following suggestions: degree, languages, "
            "experience,\n valid licence holder, personal skills...\n -to skip, enter \"none\"-" << endl;
    cin.getline(buffer,101);
    job_requirements = new char[strlen(buffer)+1];
    strcpy(job_requirements, buffer);

    //job type
    get_job_type_input();


    //job conditions
    cout << "job conditions. you might want to include the following suggestions: wage, transportation, "
            " car job, \"TenBis \" discount. -to skip, enter \"none\"" << endl;
    cin.ignore();
    cin.getline(buffer,51);
    job_condition = new char[strlen(buffer)+1];
    strcpy(job_condition, buffer);



    //job location
    get_job_location_input();

    //job date
    today();

    //job id
    //convert max id to string and save in id of job
    id = to_string(max_id);

    insertMaxIdToFiles(); //save id of last job ID in file



    print();




}

Job :: Job(char *company_name, char* role, char* job_description, char* job_requirements,
    char* job_type, char* job_condition, char* location, char* date, string id ):submitted(false)
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

    this->date = new char[strlen(date) + 1];
    strcpy(this->date,date);

    this->id = id;

//    updateSubmittedStatusFromFile(); //update submitted field


}

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
    delete [] date;

//    insertMaxIdToFiles(); //save id of last job ID in file


}


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
    delete [] date;


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

    date = new char[strlen(job.date)+1];
    strcpy(date, job.date);

    id = job.id;

}

void Job :: get_job_location_input()
{
    char nav_location;
    cout << "job location" << endl << "choose from the following:" << endl;
    cout << "1- north \n";
    cout << "2- south \n";
    cout << "3- center \n";
    cout << "4- haifa \n";
    cout << "5- Tel aviv \n";
    cout << "6- Judea and Samaria \n";
    cin >> nav_location;
    switch (nav_location) {
        case NORTH:
        {
            location = new char[strlen("north")+1];
            strcpy(location,"north");
            break;
        }
        case SOUTH:
        {
            location = new char[strlen("south")+1];
            strcpy(location,"south");
            break;
        }
        case CENTER:
        {
            location = new char[strlen("center")+1];
            strcpy(location,"center");
            break;
        }
        case HAIFA:
        {
            location = new char[strlen("haifa")+1];
            strcpy(location,"haifa");
            break;
        }
        case TEL_AVIV:
        {
            location = new char[strlen("telAviv")+1];
            strcpy(location,"telAviv");
            break;
        }
        case JUDEA_AND_SAMARIA:
        {
            location = new char[strlen("judeaAndSamaria")+1];
            strcpy(location,"judeaAndSamaria");
            break;
        }


    }
}

void Job ::get_job_type_input()
{
    char nav_type;
    cout << "job type" << endl << "choose from the following:" << endl;
    cout << "1- full time \n";
    cout << "2- part time \n";
    cout << "3- student \n";
    cout << "4- special needs \n";
    cin >> nav_type;
    switch (nav_type) {
        case FULL_TIME:
        {
            job_type = new char[strlen("fullTime")+1];
            strcpy(job_type,"fullTime");
            break;
        }
        case PART_TIME:
        {
            job_type = new char[strlen("partTime")+1];
            strcpy(job_type,"partTime");
            break;
        }
        case STUDENT:
        {
            job_type = new char[strlen("student")+1];
            strcpy(job_type,"student");
            break;
        }
        case SPECIAL_NEEDS:
        {
            job_type = new char[strlen("specialNeeds")+1];
            strcpy(job_type,"specialNeeds");
            break;
        }


    }
}


void Job:: get_role_input()
{
    char nav_role;
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
    cin >> nav_role;

    switch (nav_role) {
        case TEACHING:
        {
            role = new char[strlen("teaching")+1];
            strcpy(role,"teaching");
            break;
        }
        case ENGINEERING:
        {
            role = new char[strlen("engineering")+1];
            strcpy(role,"engineering");
            break;
        }
        case LAW:
        {
            role = new char[strlen("law")+1];
            strcpy(role,"law");
            break;
        }
        case MEDICINE:
        {
            role = new char[strlen("medicine")+1];
            strcpy(role,"medicine");
            break;
        }
        case RESEARCH:
        {
            role = new char[strlen("research")+1];
            strcpy(role,"research");
            break;
        }
        case SALES:
        {
            role = new char[strlen("sales")+1];
            strcpy(role,"sales");
            break;
        }
        case RESTAURANTS:
        {
            role = new char[strlen("restaurants")+1];
            strcpy(role,"restaurants");
            break;
        }
        case CLEANING:
        {
            role = new char[strlen("cleaning")+1];
            strcpy(role,"cleaning");
            break;
        }
        case ECONOMY:
        {
            role = new char[strlen("economy")+1];
            strcpy(role,"economy");
            break;
        }


    }




}

void Job :: print() const
{
//    setConsoleColor( FOREGROUND_BLUE );
    cout << "\ncompany name: " << endl;
//    setConsoleColor(7);
    cout << company_name << endl << endl;

//    setConsoleColor( FOREGROUND_BLUE );
    cout << "role: " << endl;
//    setConsoleColor(7);
    cout << role << endl << endl;

//    setConsoleColor( FOREGROUND_BLUE );
    cout << "job description: " << endl;
//    setConsoleColor(7);
    cout << job_description << endl << endl;

//    setConsoleColor( FOREGROUND_BLUE );
    cout << "job requirements: " << endl;
//    setConsoleColor(7);
    cout << job_requirements << endl << endl;

//    setConsoleColor( FOREGROUND_BLUE );
    cout << "job type: " << endl;
//    setConsoleColor(7);
    cout << job_type << endl << endl;

//    setConsoleColor( FOREGROUND_BLUE );
    cout << "job condition:" << endl;
//    setConsoleColor(7);
    cout << job_condition << endl << endl;

//    setConsoleColor( FOREGROUND_BLUE );
    cout << "location: " << endl;
//    setConsoleColor(7);
    cout << location << endl << endl;

    //    setConsoleColor( FOREGROUND_BLUE );
    cout << "posted in: " << endl;
//    setConsoleColor(7);
    cout << date << endl << endl;

    cout << "id: " << id << endl;
//
//    cout << "max id: " << max_id << endl;

    cout << "is submitted: " << submitted << endl << endl;



}

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
        cout << "8- back to all submitted jobs \n";


        cin >> nav_update_job;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


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
        }
    } while (nav_update_job != BACK_ALL_SUB_J); //keep showing options for adaptation until user back in all submitted jobs



}

//function that creates a string which is the date the function was called
void Job :: today() {

    time_t rawtime;
    tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int d = timeinfo->tm_mday;
    int m = timeinfo->tm_mon + 1;
    int y = timeinfo->tm_year + 1900;

    char buffer[10] = "";
    strcat(buffer, to_string(d).c_str());
    strcat(buffer, "/");
    strcat(buffer, to_string(m).c_str());
    strcat(buffer, "/");
    strcat(buffer, to_string(y).c_str());
    cout << buffer;
    date = new char[strlen(buffer)+1];
    strcpy(date, buffer);
}

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

char *Job::getDate() const {
    return date;
}

//int Job::getGeneralId() {
//    return general_id;
//}

//int Job::getMaxId() {
//    return max_id;
//}


void Job:: getMaxIdFromFiles() {


    fstream file_general;
    file_general.open("C:\\ObjectOrientedProgramming\\jobSearch\\general.txt", ios::in);
    if (!file_general.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        file_general >> max_id;
    }

}

void Job:: insertMaxIdToFiles() {

    fstream file_general;
    file_general.open("C:\\ObjectOrientedProgramming\\jobSearch\\general.txt", ios::out);
    if (!file_general.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        file_general << max_id;
    }

}




void Job:: setSubmitted()
{
    submitted = true; //chane field submitted
}



void Job::setCompanyName() {

    char buffer[80];

    cout << "company name" << endl;
    cin.getline(buffer,80);
    company_name = new char[strlen(buffer)+1];
    strcpy(company_name, buffer);
    cout<<"comp name in field: " << company_name<<endl;
}

void Job::setRole() {//TODO delete multiple function(do the same thing)

    get_role_input();

}

void Job::setJobDescription() {
    char buffer[80];

    cout << "job description. to skip, enter \"none\"" << endl;
    cin.getline(buffer,101);
    job_description = new char[strlen(buffer)+1];
    strcpy(job_description, buffer);
    cout<<"job description in field: " << job_description<<endl;



}

void Job::setJobRequirements() {
    char buffer[80];

    cout << "job requirements. you might want to include the following suggestions: degree, languages, "
            "experience,\n valid licence holder, personal skills...\n -to skip, enter \"none\"-" << endl;
    cin.getline(buffer,101);
    job_requirements = new char[strlen(buffer)+1];
    strcpy(job_requirements, buffer);
    cout<<"job_requirements in field: " << job_requirements<<endl;


}

void Job::setJobType() {

    get_job_type_input();

}

void Job::setJobCondition() {
    char buffer[80];


    cout << "job conditions. you might want to include the following suggestions: wage, transportation, "
            " car job, \"TenBis \" discount. -to skip, enter \"none\"" << endl;
    cin.getline(buffer,51);
    job_condition = new char[strlen(buffer)+1];
    strcpy(job_condition, buffer);

    cout<<"job_condition in field: " << job_condition<<endl;


}

void Job::setLocation() {

    get_job_location_input();

}

bool Job::isSubmitted() const {
    return submitted;
}

////if id exists in
//void Job:: updateSubmittedStatusFromFile()
//{
//
//}

