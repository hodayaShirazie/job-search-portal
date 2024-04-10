Job Search Portal Backend

Description
This project is a backend system for a job search portal, built using C++ and Object-Oriented Programming (OOP) principles. It allows users to search for job opportunities, apply for jobs, manage their job applications, and like job postings. The backend handles user authentication, job data management, and application processing.

Features
User Registration and Authentication
Job Search and Filtering
Job Application Submission
Job Liking
Application Tracking and Management
Admin Panel for Job Posting and Application Review

Design
Data Flow Diagrams
The data flow diagrams for the system can be found in the DFD.pdf file

Database
The project uses flat text files as the database for storing user data, job postings, and application records.

Implementation Technologies Used
-C++
-Standard Template Library (STL)
-File I/O
-Object-Oriented Programming (OOP)

Code Structure
The code is organized into the following classes:

-Administrator: Manages other classes and system operations.
-Employer: Handles employer-related functionality.
-Candidate: Handles job seeker-related functionality.
-Job: Represents job postings.
-CV: Represents candidate resumes or curricula vitae.
-Colors: Utility class for colored console output.

Testing
Test cases for the system are documented in the JSP_test_cases.pdf file.

Setup and Usage
Create a directory named ObjectOrientedProgramming on your C drive: C:\ObjectOrientedProgramming
Clone the repository into the ObjectOrientedProgramming directory: git clone https://github.com/yourusername/job-search-portal.git
Navigate to the project directory: cd job-search-portal
Compile the source code: g++ -o job-portal src/*.cpp
Run the executable: ./job-portal

Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

License
This project is licensed under the MIT License.
