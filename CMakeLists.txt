cmake_minimum_required(VERSION 3.22)
project(jobSearch)

set(CMAKE_CXX_STANDARD 23)

add_executable(jobSearch main.cpp Employer.cpp Employer.h Candidate.cpp Candidate.h Date.cpp Date.h CV.cpp CV.h Administrator.cpp Administrator.h Job.cpp Job.h)
