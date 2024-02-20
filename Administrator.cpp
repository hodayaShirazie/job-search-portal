//
// Created by Student on 15/02/2024.
//
#include "Administrator.h"
#include "Candidate.h"
#include "Employer.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;



enum personalAreaEmployer{SUBMISSION_HISTORY_E = '1', CANDIDTE_SUBMISSION = '2', PUBLISH_JOB = '3'};
enum userType{CANDIDATE = '1', EMPLOYER = '2'};
enum navEnter {LOGIN = 'A'   ,REGISTER = 'B'};

//constructor to initialize fields
Administrator :: Administrator() : candidate_arr(NULL), employers_arr(NULL), candidate_arr_size(0),employers_arr_size(0)
{
    //TODO copy from file to here
    fstream file_personal_details, file_cv;
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

                //copy details from file and creat candidate object
                Candidate *candidate = new Candidate(id, password, userName, email, phoneNumber, birthDate, freeTxt);
                Candidate **candidate_tmp = new Candidate *[candidate_arr_size + 1];


                for (int i = 0; i < candidate_arr_size; ++i) {
                    candidate_tmp[i] = candidate_arr[i];
                }

                candidate_tmp[candidate_arr_size] = candidate;
                delete[] candidate_arr;
                candidate_arr = candidate_tmp;
                ++candidate_arr_size;


            } else//copy as employer
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

                //TODO copy list of jobs

            }
        }
        file_personal_details.close();



        //TODO personal details is copied perfectly

    }

    //after coping personal details, copy CV's
    file_cv.open("C:\\ObjectOrientedProgramming\\jobSearch\\CV.txt", ios::in);
    if(!file_cv.is_open())
        cout << "file could not be opened, check error" << endl;
    else
    {
        char file_content[30];
        while(!file_cv.eof()) {
            file_cv >> file_content;
            for (int i = 0; i < candidate_arr_size; ++i) {
                if(strcmp(file_content, candidate_arr[i]->getId()) == 0)//if cv belongs to current candidate-
                {
                    char summary [80] = "\0";
                    char experience [80] = "\0";
                    char education [80] = "\0";
                    char licenses [80] = "\0";
                    char skills [80] = "\0";
                    char awards [80] = "\0";
                    char name [80] = "\0";
                    char email [80] = "\0";
                    file_cv >> file_content >> file_content;//the word summary

                    //copy summary from file
                    while(!strcmp(file_content, "experience") == 0)
                    {
                        strcat(summary, file_content);
                        strcat(summary, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //summary is done-send to constructor

                    //copy experience from file
                    while(!strcmp(file_content, "education") == 0)
                    {
                        strcat(experience, file_content);
                        strcat(experience, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //experience is done-send to constructor

                    //copy education from file
                    while(!strcmp(file_content, "licenses") == 0)
                    {
                        strcat(education, file_content);
                        strcat(education, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //education is done-send to constructor

                    //copy licenses from file
                    while(!strcmp(file_content, "skills") == 0)
                    {
                        strcat(licenses, file_content);
                        strcat(licenses, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;

                    //licenses is done-send to constructor

                    //copy skills from file
                    while(!strcmp(file_content, "awards") == 0)
                    {
                        strcat(skills, file_content);
                        strcat(skills, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //skills is done-send to constructor

                    //copy awards from file
                    while(!strcmp(file_content, "name") == 0)
                    {
                        strcat(awards, file_content);
                        strcat(awards, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //awards is done-send to constructor

                    //copy name from file
                    while(!strcmp(file_content, "email") == 0)
                    {
                        strcat(name, file_content);
                        strcat(name, " ");
                        file_cv >> file_content;
                    }
                    file_cv >> file_content;
                    //name is done-send to constructor

                    //copy email from file
                    while(!strcmp(file_content, "endl") == 0 && !file_cv.eof())
                    {
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


//                    cout <<"-----------------------------------------------\n";
//                    candidate_arr[i]->print();

                    file_cv >> file_content;












                }


            }
        }




        file_cv.close();
    }

//    for (int i = 0; i < employers_arr_size; ++i) {
//        cout << "\n printing emp--\n";
//        employers_arr[i]->print();
//        cout << "end printing emp-------\n\n";
//    }

//    for (int i = 0; i < candidate_arr_size; ++i) {
//        cout << "\n printing candidates--\n";
//        candidate_arr[i]->print();
//        cout << "end printing can-------\n\n";
//    }














}

Administrator :: ~Administrator()
{

}



void Administrator :: enterSystem()
{
    char enteringChoice;
    cout << "A-log in" << endl << "B-register" << endl;
    cin >> enteringChoice;
    switch (enteringChoice) {
        case LOGIN: {
            cin.ignore();
            char temp_id[10];
            char temp_password[20];
            cout << "id" << endl;
            cin.getline(temp_id, 20);
            cout << "password" << endl;
            cin.getline(temp_password, 20);

            //verify login details exists in txt file
            fstream file;
            file.open("C:\\ObjectOrientedProgramming\\jobSearch\\personalDetails.txt\\",ios::in);
            if(!file.is_open()) {
                cout << "file could not be opened, check error" << endl;
            }else{
                bool verified_user = false;
                char system_id[10];
                char system_password[20];
                while (!file.eof() || !verified_user)
                {
                    //TODO maybe check that password is right after id in file
                    file >> system_id >> system_password;
                    if(strcmp(system_id,temp_id) == 0 && strcmp(system_password,temp_password) == 0 )
                        verified_user = true;
                }
                if(verified_user){
                    cout << "can log in- verified user" << endl;


                }

                else
                    cout << "account was not created, try register" << endl;


                file.close();
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
                    Candidate candidate;
                    //add to candidate arr
                    Candidate** temp_candidates = new Candidate*[candidate_arr_size + 1];
                    for(int i = 0; i< candidate_arr_size; i++){temp_candidates[i] = candidate_arr[i];}
                    temp_candidates[candidate_arr_size] = &candidate;
                    ++candidate_arr_size;
                    delete [] candidate_arr;
                    candidate_arr = temp_candidates;
                    break;

                }
                case EMPLOYER:
                {
                    Employer employer;

                    //add to candidate arr
                    Employer** temp_employers = new Employer*[employers_arr_size + 1];
                    for(int i = 0; i< employers_arr_size; i++){temp_employers[i] = employers_arr[i];}
                    temp_employers[employers_arr_size] = &employer;
                    ++employers_arr_size;
                    delete [] employers_arr;
                    employers_arr = temp_employers;

                    break;

                }

            }





            break;
        }
        default:
            cout <<"do";
            //TODO HDERE
    }

}


