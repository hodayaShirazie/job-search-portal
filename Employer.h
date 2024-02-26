//
// Created by Student on 14/02/2024.
//
#ifndef JOBSEARCH_EMPLOYER_H
#define JOBSEARCH_EMPLOYER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "Job.h"
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ios;

//TODO WHEN employer delete a gob, add it as usual to files but add it to another file as deleted


enum personalAreaEmployer{SUBMISSION_HISTORY_E = '1', CANDIDTE_SUBMISSION = '2', PUBLISH_JOB = '3', Exit_E = '4'};
enum submission_history_e{ALL_SUBMITTED_JOBS = '1', EDIT_JOBS = '2', DELETE_JOBS = '3', BACK_P_A_E = '4'};


class Employer {
public:
    Employer();

    Employer(char* id, char* password, char* userName, char* email, char* phoneNumber, char* birthDate);

    void addJobToPublishJobs(Job* job);

    void copyJobsFromFile();

    char *getUserName() const;

    char *getId() const;

    char *getEmail() const;

    char *getPhoneNumber() const;

    char *getBirthDate() const;

    char *getPassword() const;

    void print() const;

    void printPublishedJobs() const;

    void copyPersonalDetailsToFile();

    void copyAllJobsToFiles();

    void edit_job();

    void delete_a_job();

    void personalArea();



    ~Employer();

    void viewCandidateSubmission();

    void addNewJob();

private:
    char *userName;
    char* id;
    char* email;
    char* phoneNumber;
    char* birthDate;
    char* password;

    Job** published_jobs_arr;
    int published_jobs_arr_size;




};


#endif //JOBSEARCH_EMPLOYER_H
