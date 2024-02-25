//
// Created by Student on 15/02/2024.
//
#include "Administrator.h"
//#include "Candidate.h"
#include "Employer.h"
#include <iostream>
#include "Job.h"

using std::cout;
using std::cin;
using std::endl;

//TODO update a job not working when i update right after register/////fixx

enum userType{CANDIDATE = '1', EMPLOYER = '2'};
enum navEnter {LOGIN = 'A'   ,REGISTER = 'B'};

//constructor to initialize fields
Administrator :: Administrator() : candidate_arr(NULL), employers_arr(NULL), candidate_arr_size(0),employers_arr_size(0)
{

//    Job::getMaxIdFromFiles();

    copyPersonalDetailsFromFile(); //build candidate and employer arrays without cv and published job fields(respectively)
    copyCVfromFile(); //build cv field to candidate array
    copyJobsFromFile(); //build published job field to employer array

//    print();


}


void Administrator :: print() const
{
    cout <<"------------------Administrator printing-----------------------------\n";

    cout <<"------------------candidate-----------------------------\n";

    for (int i = 0; i < candidate_arr_size; ++i)
    {
        candidate_arr[i]->print();
    }


    cout <<"------------------employer-----------------------------\n";

    for (int i = 0; i < employers_arr_size; ++i) {
        employers_arr[i]->print();
        cout <<endl;
    }
}

Administrator :: ~Administrator()
{


    //empty files in order to append
    emptyFiles();


//    print();

    for (int i = 0; i < candidate_arr_size; ++i)
    {
        delete candidate_arr[i];
    }



    for (int i = 0; i < employers_arr_size; ++i)
    {
        delete employers_arr[i];
    }
//    cout << "done coping to files\n";



}


//TODO after operation come back to personal area. add case to end program
void Administrator :: enterSystem()
{
    char enteringChoice;
    cout << "A-log in" << endl << "B-register" << endl;
    cin >> enteringChoice;
    switch (enteringChoice) {
        case LOGIN: {
            cin.ignore();
            bool userExists = false;
            char temp_id[10];
            char temp_password[20];
            cout << "id" << endl;
            cin.getline(temp_id, 20);
            cout << "password" << endl;
            cin.getline(temp_password, 20);
            char user_type = '\0';
            while(user_type == '\0' && !userExists) {
                //check if id and password belong to the same user
                for (int i = 0; i < candidate_arr_size && !userExists; ++i)//if user is candidate--
                {
                    if (strcmp(candidate_arr[i]->getId(), temp_id) == 0 && strcmp(candidate_arr[i]->getPassword(), temp_password) == 0) {
                        user_type = 'c';
                        userExists = true;

                        //send user to personal area
                        candidate_arr[i]->personalArea();
                    }

                }

                for (int i = 0; i < employers_arr_size && !userExists; ++i)//if user is employer--
                {
                    if (strcmp(employers_arr[i]->getId(), temp_id) == 0 && strcmp(employers_arr[i]->getPassword(), temp_password) == 0) {
                        user_type = 'e';
                        userExists = true;

                        //send user to personal area
                        employers_arr[i]->personalArea();

                    }
                }
                if (!userExists) {//if user is not in system--
                    cout << "1 or more details are incorrect, please try again" << endl;
                    cout << "id" << endl;
                    cin.getline(temp_id, 20);
                    cout << "password" << endl;
                    cin.getline(temp_password, 20);

                }
            }


            break;
        }

        case REGISTER: {
            char typeChoice;
            cout << "1-CANDIDATE" << endl << "2-EMPLOYER" << endl;
            cin >> typeChoice;
            switch (typeChoice){
                case CANDIDATE:
                {
                    Candidate *candidate = new Candidate();
                    //add to candidate arr
                    Candidate** temp_candidates = new Candidate*[candidate_arr_size + 1];
                    for(int i = 0; i< candidate_arr_size; i++){temp_candidates[i] = candidate_arr[i];}
                    temp_candidates[candidate_arr_size] = candidate;
                    ++candidate_arr_size;
                    delete [] candidate_arr;
                    candidate_arr = temp_candidates;

                    candidate_arr[candidate_arr_size-1]->personalArea();

                    break;

                }
                case EMPLOYER:
                {
                    Employer* employer = new Employer();

                    //add to candidate arr
                    Employer** temp_employers = new Employer*[employers_arr_size + 1];
                    for(int i = 0; i< employers_arr_size; i++){temp_employers[i] = employers_arr[i];}
                    temp_employers[employers_arr_size] = employer;
                    ++employers_arr_size;
                    delete [] employers_arr;
                    employers_arr = temp_employers;

                    employers_arr[employers_arr_size-1]->personalArea();

                    break;

                }
                default:
                    cout <<"invalid input- try again";

            }


            break;
        }
        default:
            cout <<"invalid input- try again";

    }

}

void Administrator :: copyJobsFromFile() {


    //
//    cout<<"printing before jobs \n";
//    for(int r=0; r<employers_arr_size; ++r)
//        employers_arr[r]->print();
    //

    fstream file_jobs;

        for(int i=0; i<employers_arr_size; ++i) {

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
                    if (strcmp(read_file_jobs, employers_arr[i]->getId()) == 0) {
                        //coping company name
                        file_jobs >> read_file_jobs >> read_file_jobs;
                        while (!strcmp(read_file_jobs, "role") == 0) {
                            strcat(company_name, read_file_jobs);
                            strcat(company_name, " ");
                            file_jobs >> read_file_jobs;
                        }
                        file_jobs >> read_file_jobs;
                        //
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
//                        job->print();

                        //add job to publish jobs array
                        employers_arr[i]->addJobToPublishJobs(job);



                    }

                    company_name[0] = '\0';
                    role [0] = '\0';
                    job_description[0] = '\0';
                    job_requirements[0] = '\0';
                    job_type[0] = '\0';
                    job_condition[0] = '\0';
                    location[0] = '\0';
                    date[0] = '\0';
                    id_j[0] = '\0';
//                    file_jobs >> read_file_jobs;
                }

                file_jobs.close();
            }
        }





}


void Administrator :: emptyFiles()
{
    //open and close files to delete history
    fstream file;
    file.open("C:\\ObjectOrientedProgramming\\jobSearch\\personalDetails.txt",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

    file.open("C:\\ObjectOrientedProgramming\\jobSearch\\CV.txt",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

    file.open("C:\\ObjectOrientedProgramming\\jobSearch\\jobs.txt",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

    file.open("C:\\ObjectOrientedProgramming\\jobSearch\\submittedJobs",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

    file.open("C:\\ObjectOrientedProgramming\\jobSearch\\likedJobs",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();
}






void Administrator ::copyPersonalDetailsFromFile() {
    //copy personal details of employer + candidate to file "personal employer
    fstream file_personal_details, file_cv,file_jobs;
    file_personal_details.open("C:\\ObjectOrientedProgramming\\jobSearch\\personalDetails.txt",ios::in);
    if(!file_personal_details.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {
        while (!file_personal_details.eof()) {
            char readFile[501];
            file_personal_details >> readFile;

            char userName[30];
            char id[30];
            char email[30];
            char phoneNumber[30];
            char birthDate[30];
            char password[30];

            if (strcmp(readFile, "c") == 0)//copy as candide
            {
                char freeTxt[30];

                file_personal_details >> id >> password >> userName >> email >> phoneNumber >> birthDate >> freeTxt;

                //copy details from file and create candidate object
                Candidate *candidate = new Candidate(id, password, userName, email, phoneNumber, birthDate, freeTxt);
                Candidate **candidate_tmp = new Candidate *[candidate_arr_size + 1];


                for (int i = 0; i < candidate_arr_size; ++i) {
                    candidate_tmp[i] = candidate_arr[i];
                }

                candidate_tmp[candidate_arr_size] = candidate;
                delete[] candidate_arr;
                candidate_arr = candidate_tmp;
                ++candidate_arr_size;


            }
            else if(strcmp(readFile, "e") == 0)//copy as employer
            {
                file_personal_details >> id >> password >> userName >> email >> phoneNumber >> birthDate;








                //copy details from file and creat candidate object
                Employer *employer = new Employer(id, password, userName, email, phoneNumber, birthDate);
                Employer **employer_tmp = new Employer *[employers_arr_size + 1];













                for (int i = 0; i < employers_arr_size; ++i) {
                    employer_tmp[i] = employers_arr[i];
                }

                employer_tmp[employers_arr_size] = employer;
                delete [] employers_arr;
                employers_arr = employer_tmp;
                ++employers_arr_size;





            }
        }
        file_personal_details.close();

    }



}

void Administrator ::copyCVfromFile() {

    char file_content[30];
    fstream file_cv,file_jobs;

    for (int i = 0; i < candidate_arr_size; ++i) {
        file_cv.open("C:\\ObjectOrientedProgramming\\jobSearch\\CV.txt", ios::in);
        if (!file_cv.is_open())
            cout << "file could not be opened, check error" << endl;
        else {
            while (!file_cv.eof()) {
                file_cv >> file_content;

                if (strcmp(file_content, candidate_arr[i]->getId()) == 0)//if cv belongs to current candidate-
                {
                    char summary[80] = "\0";
                    char experience[80] = "\0";
                    char education[80] = "\0";
                    char licenses[80] = "\0";
                    char skills[80] = "\0";
                    char awards[80] = "\0";
                    char name[80] = "\0";
                    char email[80] = "\0";
                    file_cv >> file_content >> file_content;//the word #summary#

                    //copy summary from file
                    while (!strcmp(file_content, "#experience#") == 0) {
                        strcat(summary, file_content);
                        strcat(summary, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //summary is done-send to constructor

                    //copy experience from file
                    while (!strcmp(file_content, "#education#") == 0) {
                        strcat(experience, file_content);
                        strcat(experience, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //experience is done-send to constructor

                    //copy education from file
                    while (!strcmp(file_content, "#licenses#") == 0) {
                        strcat(education, file_content);
                        strcat(education, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //education is done-send to constructor

                    //copy licenses from file
                    while (!strcmp(file_content, "#skills#") == 0) {
                        strcat(licenses, file_content);
                        strcat(licenses, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;

                    //licenses is done-send to constructor

                    //copy skills from file
                    while (!strcmp(file_content, "#awards#") == 0) {
                        strcat(skills, file_content);
                        strcat(skills, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //skills is done-send to constructor

                    //copy awards from file
                    while (!strcmp(file_content, "#name#") == 0) {
                        strcat(awards, file_content);
                        strcat(awards, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //awards is done-send to constructor

                    //copy name from file
                    while (!strcmp(file_content, "#email#") == 0) {
                        strcat(name, file_content);
                        strcat(name, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //name is done-send to constructor

                    //copy email from file
                    while (!strcmp(file_content, "#endl#") == 0 && !file_cv.eof()) {
                        strcat(email, file_content);
                        strcat(email, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //email is done-send to constructor

                    //create cv object
                    CV *cv = new CV(summary, experience, education, licenses, skills, awards, name, email);


                    //set cv in cv field
                    candidate_arr[i]->set_cv(cv);





                }


            }
            file_cv.close();

        }



    }





}


