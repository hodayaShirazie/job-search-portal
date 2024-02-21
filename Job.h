//
// Created by Student on 21/02/2024.
//

#ifndef CANDIDATE_H_JOB_H
#define CANDIDATE_H_JOB_H

#include <iostream>
#include <cstring>



using std::cout;
using std::cin;
using std::endl;
using std::to_string;
using std::string;

//using std::stoi;


enum role_of_job{TEACHING = '1', ENGINEERING = '2', LAW = '3', MEDICINE = '4', RESEARCH = '5', SALES = '6', RESTAURANTS = '7', CLEANING = '8', ECONOMY = '9'};
enum type_of_job{FULL_TIME = '1', PART_TIME = '2', STUDENT = '3', SPECIAL_NEEDS = '4'};
enum location_of_job{NORTH = '1', SOUTH = '2', CENTER = '3', HAIFA = '4', TEL_AVIV = '5', JUDEA_AND_SAMARIA = '6'};




class Job {
public:

    Job();

    Job(char *company_name, char* role, char* job_description, char* job_requirements,
        char* job_type, char* job_condition, char* location, char* date, string id );

    ~Job();

    Job& operator=(const Job& job);

    string getId() const;

    void get_role_input();

    void get_job_type_input();

    void get_job_location_input();

    void print() const;

    void today();

    char *getCompanyName() const;

    char *getRole() const;

    char *getJobDescription() const;

    char *getJobRequirements() const;

    char *getJobType() const;

    char *getJobCondition() const;

    char *getLocation() const;

    char *getDate() const;

    static int getGeneralId();

    static int getMaxId();

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
    static int general_id;
    static int max_id; //TODO  write max id in file









};



#endif //CANDIDATE_H_JOB_H
