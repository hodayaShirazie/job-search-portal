// Created by Student on 14/02/2024.
//

#ifndef JOBSEARCH_CANDIDATE_H
#define JOBSEARCH_CANDIDATE_H

#include <iostream>
#include "CV.h"
#include <fstream>
#include <cstring>
#include <limits>
#include "Colors.h"
#include <algorithm>


class Job; //forward declaration


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ios;


enum personalAreaCandidate{EDIT_PROFILE = '1', ALL_JOBS = '2', FILTER_JOBS = '3', SUBMIT_JOB = '4', LIKE_A_JOB = '5',  SUBMISSION_HISTORY_C = '6',Exit_C = '7'};
enum editProfileCandidate{USER_NAME_C = '1', EMAIL_C = '2', PHONE_NUMBER_C = '3', PASSWORD_C = '4', CV_C = '5', UPDATE_P_C = '6'};
enum filterJobs_c{LOCATION_F = '1', JOB_TYPE_F = '2', ROLE_F = '3'};
enum likeJobs_c{LIKE_A_JOB_l = '1', UN_LIKE_A_JOB_l = '2', JOBS_I_LIKED_I = '3'};




class Candidate {
public:

    Candidate(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate, char* freeTxt);

    Candidate();

    ~Candidate();

    Candidate(const Candidate& candidate);

    Candidate& operator=(const Candidate& candidate);


    void personalArea();


    //setters
    void set_user_name();

    void set_id();

    void set_email();

    void set_phone_number();

    void set_password();

    void set_birth_date();

    void set_free_text();

    void set_cv(CV *cv);



    //getters
    char *getId() const;

    Job **getAllJobsArr() const;

    char *getFreeTxt() const;

    int getAllJobsArrSize() const;

    char *getPassword() const;

    CV *getCv() const;


    //print functions
    void print() const;

    void printAllJobsArr() const;


    //general functions
    bool checkValidDate(int day, int month, int year);

    bool checkFirstNameAndLastName(char* str);

    void copyAllJobsFromFile();

    void addJobToJobArr(Job* job);

    void submit_job();

    void filterJobsByFeatures();

    void updateLikedStatusFromFile();

    void viewSubmissionHistory();

    bool compareJobsByDate(Job* a, Job* b);

     void likeJob();

    void unLikeJob();

    void viewLikedJobs();

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
    bool wasCVcopied;
    bool wasPDcopied;
//public:
//    void setPointerJobApplicants(Candidate ***pointerJobApplicants);
//
//    void setPointerJobApplicantsSize(int pointerJobApplicantsSize);

private:
    bool wasLikedCopied;
    bool wasSubmittedCopied;

//    Candidate*** pointerJobApplicants;//pointer to array of candidate to every job
//    int pointerJobApplicantsSize;//size of array of candidate of every job

    Job** all_jobs_arr;
    int all_jobs_arr_size;

};





#endif //JOBSEARCH_CANDIDATE_H
