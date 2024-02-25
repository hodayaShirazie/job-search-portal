//
// Created by Student on 14/02/2024.
//
//#include <string>
#include <iostream>
#include "Date.h"
#include "CV.h"
#include <fstream>
#include <cstring>
#include "Job.h"
#include <limits>


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ios;


enum personalAreaCandidate{EDIT_PROFILE = '1', ALL_JOBS = '2', FILTER_JOBS = '3', SUBMIT_JOB = '4', LIKE_A_JOB = '5',  JOBS_I_LIKED = '6', SUBMISSION_HISTORY_C = '7',Exit_C = '8'};
enum editProfileCandidate{USER_NAME_C = '1', EMAIL_C = '2', PHONE_NUMBER_C = '3', PASSWORD_C = '4', CV_C = '5', BACK_P_A_C = '6'};
enum filterJobs_c{LOCATION_F = '1', JOB_TYPE_F = '2', ROLE_F = '3'};


#ifndef JOBSEARCH_CANDIDATE_H
#define JOBSEARCH_CANDIDATE_H


class Candidate {
public:

    Candidate();

    Candidate(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate, char* freeTxt);

    ~Candidate();

    Candidate& operator=(const Candidate& candidate);

    Candidate(const Candidate& candidate);

    void personalArea();


    void filterJobsByFeatures();

    char *getUserName() const;

    char *getId() const;

    char *getEmail() const;

    char *getPhoneNumber() const;

    char *getBirthDate() const;

    char *getPassword() const;

    CV *getCv() const;

    void set_user_name();

    void set_email();

    void set_phone_number();

    void set_password();

    void set_cv(CV *cv);

    void print() const;

    void copyAllJobsFromFile();

    void addJobToJobArr(Job* job);

    void printAllJobsArr() const;

    void submit_job();

    void updateLikedtedStatusFromFile();

    void updateSubmittedStatusFromFile();

    void viewSubmissionHistory();

    void likeJob();

    void viewLikedJjobs();

    void copyPersonalDetailsToFile();

    void copyCVToFile();

    void copySubmittedJobsToFile();

    void copyLikedJobsToFile();









private:
    char* userName;
    char* id;
    char* email;
    char* phoneNumber;
    char* birthDate;
    char* password;
    char* freeTxt;
    CV *cv;
    Job** all_jobs_arr;
    int all_jobs_arr_size;

};





#endif //JOBSEARCH_CANDIDATE_H
