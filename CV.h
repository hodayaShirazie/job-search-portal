//
// Created by Student on 14/02/2024.
//

#ifndef JOBSEARCH_CV_H
#define JOBSEARCH_CV_H




#include <iostream>
#include <limits>

using std:: numeric_limits;
using std:: streamsize;




class CV {
public:

    CV();

    CV(char* summary, char* experience, char* education, char* licenses, char* skills, char* awards, char* name, char* email);

    CV(char* name, char*email);

    ~CV();

    CV(const CV& cv);

    CV&operator=(const CV& cv);

    char *getSummary() const;

    char *getExperience() const;

    char *getEducation() const;

    char *getLicenses() const;

    char *getSkills() const;

    char *getAwards() const;

    char *getName() const;

    char *getEmail() const;

    void setName(char* name);

    void setEmail(char* email);

    void change_cv();

    void createCV();

    void print () const;

    void setSummary();

    void setExperience();

    void setEducation();

    void setLicenses();

    void setSkills();

    void setAwards();








private:
    char* summary;
    char* experience;
    char* education;
    char* licenses;
    char* skills;
    char* awards;
    char* name;
    char* email;

};


#endif //JOBSEARCH_CV_H
