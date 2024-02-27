//
// Created by Student on 21/02/2024.
//

#ifndef CANDIDATE_H_JOB_H
#define CANDIDATE_H_JOB_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "Colors.h"

class Candidate; //forward declaration


//TODO maintain array of applicants here for candidate submissions in employer


using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::string;
using std::ios;
using std::fstream;



//using std::stoi;


enum role_of_job{TEACHING = '1', ENGINEERING = '2', LAW = '3', MEDICINE = '4', RESEARCH = '5', SALES = '6', RESTAURANTS = '7', CLEANING = '8', ECONOMY = '9'};
enum type_of_job{FULL_TIME = '1', PART_TIME = '2', STUDENT = '3', SPECIAL_NEEDS = '4'};
enum location_of_job{NORTH = '1', SOUTH = '2', CENTER = '3', HAIFA = '4', TEL_AVIV = '5', JUDEA_AND_SAMARIA = '6'};
enum update_job_fields{COMPANY_NAME = '1', ROLE = '2', JOB_DESCRIPTION = '3', JOB_REQUIREMENTS = '4', JOB_TYPE = '5', JOB_CONDITION = '6', LOCATION = '7', BACK_ALL_SUB_J = '8'};




class Job {
public:

    Job();

    Job(char *company_name, char* role, char* job_description, char* job_requirements,
        char* job_type, char* job_condition, char* location, char* date, string id );

    ~Job();

    Job(const Job& job);

    Job& operator=(const Job& job);


    string getId() const;

    void get_role_input();

    void get_job_type_input();

    void get_job_location_input();

    char *getCompanyName() const;

    char *getRole() const;

    char *getJobDescription() const;

    char *getJobRequirements() const;

    char *getJobType() const;

    char *getJobCondition() const;

    bool isSubmitted() const;

    bool isLiked() const;

    char *getLocation() const;

    char *getDate() const;

    Candidate **getJobApplicants() const;

    int getJobApplicantsSize() const;


    void setSubmitted();

    void setLiked();

    void setCompanyName();

    void setRole();

    void setJobDescription();

    void setJobRequirements();

    void setJobType();

    void setJobCondition();

    void setLocation();

    void setJobApplicants(Candidate **jobApplicants);

    void setJobApplicantsSize(int jobApplicantsSize);


    void print() const;

    void printJobApplicants();


    void readMaxIdFromFiles();

    void insertMaxIdToFiles();

    void today();

    void  updateJob();







private:
    char *company_name;
    char* role;
    char* job_description;
    char* job_requirements;
    char* job_type;
    char* job_condition;
    char* location;
    char* date;
    string id;
    int max_id;
    bool submitted;
    bool liked;

    Candidate **jobApplicants;
    int jobApplicantsSize;








};



#endif //CANDIDATE_H_JOB_H
