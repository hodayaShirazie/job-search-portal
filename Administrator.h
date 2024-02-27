//
// Created by Student on 15/02/2024.
//
#include "Candidate.h"
#include "Employer.h"
#ifndef CANDIDATE_H_ADMINISTRATOR_H
#define CANDIDATE_H_ADMINISTRATOR_H


class Administrator {
public:

    Administrator();

    ~Administrator();

    void enterSystem();

    void print() const;

    void emptyFiles();

    void copyJobsFromFile();

    void copyPersonalDetailsFromFile();

    void copySubFromFile();

    void copyCVfromFile();








private:
    Candidate** candidate_arr;
    Employer** employers_arr;
    int candidate_arr_size;
    int employers_arr_size;


};


#endif //CANDIDATE_H_ADMINISTRATOR_H
