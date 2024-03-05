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

//constructor
Administrator :: Administrator() : candidate_arr(NULL), employers_arr(NULL), candidate_arr_size(0),employers_arr_size(0)
{
    copyPersonalDetailsFromFile(); //build candidate and employer arrays without cv and published job fields(respectively)
    copyCVfromFile(); //build cv field to candidate array
    copyJobsFromFile(); //build published job field of employer array
    copySubFromFile();

}

//distructor
Administrator :: ~Administrator()
{


    //empty files in order to append
    emptyFiles();

    for (int i = 0; i < candidate_arr_size; ++i)
    {
        delete candidate_arr[i];
    }



    for (int i = 0; i < employers_arr_size; ++i)
    {
        delete employers_arr[i];
    }



}

//main function that starts program for user
void Administrator :: enterSystem()
{
    char enteringChoice;
    Colors color;

    color.setConsoleColor(  FOREGROUND_RED );
    cout << "\nA";
    color.setConsoleColor(7);
    cout << "-log in" << endl;
    color.setConsoleColor(  FOREGROUND_RED );
    cout << "B";
    color.setConsoleColor(7);
    cout << "-register\n";


    cin >> enteringChoice;
    if (std::cin.fail()) {
        std::cin.clear(); // Clears the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        color.setConsoleColor(  FOREGROUND_RED );
        cout << "invalid input"<<endl;
        color.setConsoleColor(7);

    }

    if (!cin) {
        cin.clear(); // Clears the error flag on cin.
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    switch (enteringChoice) {
        case LOGIN: {
            cin.ignore();
            bool userExists = false;
            char temp_id[10];
            char temp_password[20];

            cout << "id" << endl;
            cin.getline(temp_id, 20);
            if (std::cin.fail()) {
                std::cin.clear(); // Clears the error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                color.setConsoleColor(  FOREGROUND_RED );
                cout << "invalid input"<<endl;
                color.setConsoleColor(7);
                return;
            }


            cout << "password" << endl;
            cin.getline(temp_password, 20);
            if (std::cin.fail()) {
                std::cin.clear(); // Clears the error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                color.setConsoleColor(  FOREGROUND_RED );
                cout << "invalid input"<<endl;
                color.setConsoleColor(7);
                return;
            }

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
                    color.setConsoleColor(  FOREGROUND_RED );
                    cout << "1 or more details are incorrect, please try again" << endl;
                    color.setConsoleColor(7);

                    cout << "id" << endl;
                    cin.getline(temp_id, 20);
                    if (std::cin.fail()) {
                        std::cin.clear(); // Clears the error flags
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        color.setConsoleColor(FOREGROUND_RED);
                        cout << "invalid input" << endl;
                        color.setConsoleColor(7);
                        return;
                    }

                    cout << "password" << endl;

                    cin.getline(temp_password, 20);
                    if (std::cin.fail()) {
                        std::cin.clear(); // Clears the error flags
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        color.setConsoleColor(FOREGROUND_RED);
                        cout << "invalid input" << endl;
                        color.setConsoleColor(7);
                        return;
                    }

                }
            }


            break;
        }

        case REGISTER: {
            char typeChoice;

            color.setConsoleColor(  FOREGROUND_RED );
            cout << "1";
            color.setConsoleColor(7);
            cout <<"-candidate" << endl;

            cout << "2";
            color.setConsoleColor(7);
            cout <<"-employer" << endl;
            cin >> typeChoice;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                color.setConsoleColor(  FOREGROUND_RED );
                cout << "invalid input"<<endl;
                color.setConsoleColor(7);
                return;
            }
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
                default: {
                    color.setConsoleColor(FOREGROUND_RED);
                    cout << "invalid input" << endl;
                    color.setConsoleColor(7);
                }

            }


            break;
        }
        default: {
            //end program
        }

    }

}

//print function
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

//function to files content
void Administrator :: emptyFiles()
{
    //open and close files to delete history
    fstream file;
    file.open("C:\\ObjectOrientedProgramming\\job-search-portal\\personalDetails.txt",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

    file.open("C:\\ObjectOrientedProgramming\\job-search-portal\\CV.txt",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

    file.open("C:\\ObjectOrientedProgramming\\job-search-portal\\jobs.txt",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

    file.open("C:\\ObjectOrientedProgramming\\job-search-portal\\submittedJobs",ios::out);
    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

    file.open("C:\\ObjectOrientedProgramming\\job-search-portal\\likedJobs",ios::out);

    if(!file.is_open())
        cout << "file could not be opened, check error" << endl;
    else
        file.close();

}


//functions to create data Structure from files
void Administrator :: copyJobsFromFile() {


    fstream file_jobs;

        for(int i=0; i<employers_arr_size; ++i) {

            char company_name[200] = "\0";
            char role[200] = "\0";
            char job_description[200] = "\0";
            char job_requirements[200] = "\0";
            char job_type[200] = "\0";
            char job_condition[200] = "\0";
            char location[200] = "\0";
            char id_j[5] = "\0";
            int d = 0,m = 0,y = 0;

            file_jobs.open("C:\\ObjectOrientedProgramming\\job-search-portal\\jobs.txt", ios::in);
            if (!file_jobs.is_open())
                cout << "file could not be opened, check error" << endl;
            else {

                while (!file_jobs.eof()) {
                    char read_file_jobs[200];
                    int readFileDate;
                    file_jobs >> read_file_jobs;
                    if (strcmp(read_file_jobs, employers_arr[i]->getId()) == 0) {
                        //coping company name
                        file_jobs >> read_file_jobs >> read_file_jobs;
                        while (!strcmp(read_file_jobs, "#role#") == 0) {
                            strcat(company_name, read_file_jobs);
                            strcat(company_name, " ");
                            file_jobs >> read_file_jobs;
                        }
                        file_jobs >> read_file_jobs;
                        //
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
                                           location, id_j,d,m,y);


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
                    id_j[0] = '\0';
                }

                file_jobs.close();
            }
        }

}

void Administrator ::copyPersonalDetailsFromFile() {
    //copy personal details of employer + candidate to file "personal employer
    fstream file_personal_details, file_cv,file_jobs;
    file_personal_details.open("C:\\ObjectOrientedProgramming\\job-search-portal\\personalDetails.txt",ios::in);
    if(!file_personal_details.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {
        while (!file_personal_details.eof()) {
            char readFile[501];
            file_personal_details >> readFile;

            char userName[30];
            char lastName[30];
            char id[30];
            char email[30];
            char phoneNumber[30];
            char birthDate[30];
            char password[30];

            if (strcmp(readFile, "c") == 0)//copy as candide
            {
                char freeTxt[400] = "";

                file_personal_details >> id >> password >> userName >> lastName >> email >> phoneNumber >> birthDate;

                file_personal_details >> readFile;
                while(strcmp(readFile, "#endl#") != 0) {
                    strcat(freeTxt,readFile);
                    strcat(freeTxt," ");
                    file_personal_details >> readFile;

                }
                strcat(userName," ");
                strcat(userName,lastName);

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
                file_personal_details >> id >> password >> userName >> lastName >> email >> phoneNumber >> birthDate;
                strcat(userName," ");
                strcat(userName,lastName);



                //copy details from file and create candidate object
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
        file_cv.open("C:\\ObjectOrientedProgramming\\job-search-portal\\CV.txt", ios::in);
        if (!file_cv.is_open())
            cout << "file could not be opened, check error" << endl;
        else {
            while (!file_cv.eof()) {
                file_cv >> file_content;

                if (strcmp(file_content, candidate_arr[i]->getId()) == 0)//if cv belongs to current candidate-
                {
                    char summary[3100] = "\0";
                    char experience[3100] = "\0";
                    char education[3100] = "\0";
                    char licenses[3100] = "\0";
                    char skills[3100] = "\0";
                    char awards[3100] = "\0";
                    char name[3100] = "\0";
                    char email[3100] = "\0";
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

void Administrator ::copySubFromFile() {

    fstream file_submitted_jobs;

    char readFile[500];//TODO  you can open file and define in length that is bigger in 1 fro, file

    file_submitted_jobs.open("C:\\ObjectOrientedProgramming\\job-search-portal\\submittedJobs",ios::in);
    if(!file_submitted_jobs.is_open())
        cout << "file could not be opened, check error" << endl;
    else {
        while (!file_submitted_jobs.eof()) {
            file_submitted_jobs >> readFile;

            for (int t = 0; t < candidate_arr_size; ++t) {


                if (strcmp(readFile, candidate_arr[t]->getId()) == 0) {


                    while (strcmp(readFile, "endl") != 0) {
                        file_submitted_jobs >> readFile;
                        for (int i = 0; i < candidate_arr[t]->getAllJobsArrSize(); ++i) {
                            if (readFile[strlen(readFile) - 1] >= '0' &&
                                readFile[strlen(readFile) - 1] <= '9') //if readFile contains id of a job
                                strcat(readFile, " ");

                            if (candidate_arr[t]->getAllJobsArr()[i]->getId().compare(readFile) == 0) {
                                candidate_arr[t]->getAllJobsArr()[i]->setSubmitted();




//TODO HEREEEEEEEEEEEEEEEEEEEEEEEEE
                                //update JobApplicants array
                                Candidate **tmpArrC = new Candidate *[
                                candidate_arr[t]->getAllJobsArr()[i]->getJobApplicantsSize() + 1];
                                for (int j = 0; j < candidate_arr[t]->getAllJobsArr()[i]->getJobApplicantsSize(); ++j) {
                                    tmpArrC[j] = candidate_arr[t]->getAllJobsArr()[i]->getJobApplicants()[j];
                                }
                                tmpArrC[candidate_arr[t]->getAllJobsArr()[i]->getJobApplicantsSize()] = candidate_arr[t]; //put in last cell - pointer to current candidate
                                delete[] candidate_arr[t]->getAllJobsArr()[i]->getJobApplicants();
                                candidate_arr[t]->getAllJobsArr()[i]->setJobApplicants(tmpArrC);
                                candidate_arr[t]->getAllJobsArr()[i]->setJobApplicantsSize(
                                        candidate_arr[t]->getAllJobsArr()[i]->getJobApplicantsSize() + 1);




//                                //update JobApplicants array
//                                Candidate **tmpArrC = new Candidate *[
//                                candidate_arr[t]->getAllJobsArr()[i]->getJobApplicantsSize() + 1];
//                                for (int j = 0; j < candidate_arr[t]->getAllJobsArr()[i]->getJobApplicantsSize(); ++j) {
//                                    tmpArrC[j] = candidate_arr[t]->getAllJobsArr()[i]->getJobApplicants()[j];
//                                }
//                                tmpArrC[candidate_arr[t]->getAllJobsArr()[i]->getJobApplicantsSize()] = candidate_arr[t]; //put in last cell - pointer to current candidate
//                                delete[] candidate_arr[t]->getAllJobsArr()[i]->getJobApplicants();
//                                candidate_arr[t]->getAllJobsArr()[i]->setJobApplicants(tmpArrC);
//                                candidate_arr[t]->getAllJobsArr()[i]->setJobApplicantsSize(
//                                        candidate_arr[t]->getAllJobsArr()[i]->getJobApplicantsSize() + 1);





                                // find job in published job arr of employer
                                for (int e = 0; e < employers_arr_size; ++e) {
                                    for (int y = 0; y < employers_arr[e]->getPublishedJobsArrSize(); ++y) {


                                        if (employers_arr[e]->getPublishedJobsArr()[y]->getId().compare(readFile) ==
                                            0)//if job is found in publish job arr of said employer
                                        {
                                            Candidate **tmpArrE = new Candidate *[
                                            employers_arr[e]->getPublishedJobsArr()[y]->getJobApplicantsSize() + 1];
                                            for (int j = 0; j < employers_arr[e]->getPublishedJobsArr()[y]->getJobApplicantsSize(); ++j) {
                                                tmpArrE[j] = employers_arr[e]->getPublishedJobsArr()[y]->getJobApplicants()[j];
                                            }
                                            tmpArrE[employers_arr[e]->getPublishedJobsArr()[y]->getJobApplicantsSize()] = candidate_arr[t]; //put in last cell pointer to current candidate
                                            delete[] employers_arr[e]->getPublishedJobsArr()[y]->getJobApplicants();
                                            employers_arr[e]->getPublishedJobsArr()[y]->setJobApplicants(tmpArrE);
                                            employers_arr[e]->getPublishedJobsArr()[y]->setJobApplicantsSize(
                                                    employers_arr[e]->getPublishedJobsArr()[y]->getJobApplicantsSize()+1);


                                        }

                                    }


                                }


                            }
                        }
                    }
                }
            }
        }


        file_submitted_jobs.close();
    }

}


