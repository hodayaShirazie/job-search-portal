#include <iostream>
#include "CV.h"
//#include "Candidate.h"
#include "Administrator.h"
#include <stdlib.h>
#include <cstring>
#include "Employer.h"
#include "Job.h"


//git link: https://github.com/hodayaShirazie/job-search-portal.git

void draftColor()
{
//#include <iostream>
//#include <windows.h>

//// c = 7 for default color
//void setConsoleColor(WORD c)
//{
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
//}
//
//int main()
//{
//    setConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED );
//    std::cout << "Hello\n";
//    setConsoleColor( BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED );
//    std::cout << "Goodbye\n";
//    setConsoleColor(7);
//}
}

void checkCV(){
//    CV cv("rina","hodaya.sh2003@gmail.com");
//    cv.createCV();
//    cv.print();

}




void validemailC(){
        char buffer [80];
        char* email;
        bool existsSign = false;
        bool invalidEmail = false;
        bool invalidProfix = false;
//    while (!invalidEmail || !invalidProfix || !existsSign) {
        while(!invalidEmail) {
            cout << "email" << endl;
            cin.getline(buffer, 20);
            email = new char[strlen(buffer) + 1];
            strcpy(email, buffer);
            int lenEmail = strlen(email);

//        //if email does not end with .org/.com/.il
//        if ((email[lenEmail - 1] == 'm' && email[lenEmail - 2] == 'o' && email[lenEmail - 3] == 'c' &&
//             email[lenEmail - 4] == '.')
//            || (email[lenEmail - 1] == 'g' && email[lenEmail - 2] == 'r' && email[lenEmail - 3] == 'o' &&
//                email[lenEmail - 4] == '.') ||
//                (email[lenEmail - 1] == 'l' && email[lenEmail - 2] == 'i' && email[lenEmail - 3] == '.'))
//            invalidProfix = true;


            //if email contains invalid characters
            for (int i = 0; email[i] != '\0' && invalidEmail; ++i) {
                if (!(email[i] > 'a' && email[i] < 'z' || email[i] > 'A' && email[i] < 'Z'))
                    if (!(email[i] > '0' && email[i] < '9'))
                        if (!(email[i] == '-' && email[i] < '.'))
                            if (!(email[i] == '@')) {
                                invalidEmail = false; //email is not valid
                                cout << "enter a valid ";
                            }
                            else
                                invalidEmail = true;



//            if (email[i] == '@')
//                existsSign = true;
            }

        }

}



#include <fstream>
using std::ios;
using std::fstream;
using std::to_string;

void today(int d,int m,int y) {

    time_t rawtime;
    tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    d = timeinfo->tm_mday;
    m = timeinfo->tm_mon + 1;
    y = timeinfo->tm_year + 1900;

    char buffer[10] = "";
    strcat(buffer, to_string(d).c_str());
    strcat(buffer, "/");
    strcat(buffer, to_string(m).c_str());
    strcat(buffer, "/");
    strcat(buffer, to_string(y).c_str());
    cout << buffer;
}
#include <typeinfo>

void addJobToJobArr(Job* job)
{

}

void copyAllJobsFromFile() {


    fstream file_jobs;

//    for(int i=0; i<employers_arr_size; ++i) {

    char company_name[200] = "\0";
    char role[200] = "\0";
    char job_description[200] = "\0";
    char job_requirements[200] = "\0";
    char job_type[200] = "\0";
    char job_condition[200] = "\0";
    char location[200] = "\0";
    char date[200] = "\0";
    char id_j[5] = "\0";

    //TODO copy list of jobs
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
                        job->print();

            //add job to publish jobs array
//            employers_arr[i]->addJobToPublishJobs(job);


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


int main() {




//Job j;
//Job j1;


//    copyAllJobsFromFile();


    Administrator a;
    a.enterSystem();
//    a.print();


/*






 */


    return 0;
}




