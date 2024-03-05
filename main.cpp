#include <iostream>
#include "CV.h"
//#include "Candidate.h"
#include "Administrator.h"
#include <stdlib.h>
#include <cstring>
#include "Employer.h"
#include "Job.h"



//TODO things that do not work and needs to be checked : after register as candidate user name doest wiat for input
//waits after phone number instead of printing password,email not working sometimes,publish new job employer-job requirements
//void setColorANSI(int colorCode) {
//    std::cout << "\033[" << colorCode << "m";
//}
//void enableVirtualTerminalProcessing() {
//    // Get the handle to the standard output.
//    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    if (hOut == INVALID_HANDLE_VALUE) return;
//
//    // Retrieve the current console mode.
//    DWORD dwMode = 0;
//    if (!GetConsoleMode(hOut, &dwMode)) return;
//
//    // Enable Virtual Terminal Processing.
//    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
//    if (!SetConsoleMode(hOut, dwMode)) return;
//}
int main() {


    /*

     Default: 39
Black: 30
Red: 31
Green: 32
Yellow: 33
Blue: 34
Magenta: 35
Cyan: 36
Light Gray: 37
Dark Gray: 90
Light Red: 91
Light Green: 92
Light Yellow: 93
Light Blue: 94
Light Magenta: 95
Light Cyan: 96
White: 97



     */
    Colors color;
//
    color.enableVirtualTerminalProcessing();
//
//
//
//    // Now try setting the text color.
//    color.setColorANSI(32); // Set text color to red.
//    std::cout << "This text should be red!" << std::endl;
//
//    color.setColorANSI(0); // Reset text color.
//    cout<<"shouyghjk hygthjkol iuj\n";
//    color.setColorANSI(39); // Set text color to red.
//    std::cout << "This text should be red!" << std::endl;
//
//    color.setColorANSI(94); // Set text color to red.
//    std::cout << "This text should be red!" << std::endl;
//
//    color.setColorANSI(33); // Set text color to red.
//    std::cout << "This text should be red!" << std::endl;
//
//    color.setColorANSI(34); // Reset text color.
//    cout<<"shouyghjk hygthjkol iuj\n";
//    color.setColorANSI(35); // Set text color to red.
//    std::cout << "This text should be red!" << std::endl;
//
//    color.setColorANSI(90); // Set text color to red.
//    std::cout << "This text should be red!" << std::endl;


    Administrator a;
    a.enterSystem();
//    a.print();


/*

CV:
098765432 #summary# sum  #experience# poiu  #education# oiuy  #licenses# jhytg  #skills# uytrd  #awards# uytr  #name# TOM  #email# tom@ll.il  #endl#

098765432 #summary# none  #experience# none  #education# none  #licenses# none  #skills# none  #awards# none  #name# Adam  #email# adam.co@gmail.com  #endl#
098765432 4  9  26  27  3  7  endl
c 098765432 9909 hodaya shirazie 0987786756 0547337292 98/8/990
 098765432 4  endl

-personal details-
 c 213445665 WQ1212wq Jhon mark jhon-t1994@gmail.org 0546657867 12.3.1994 hi there, I'm John, on a job portal seeking my next tech challenge. With my profile updated and applications sent, I'm ready for the next big step in my career.
e 098765432 Qq112211 adam levi adam@gmail.com 0987786755

 -------cv----
 213445665 #summary# none #experience# Junior Software Developer, Tech Innovations Inc., 2019-2021. Worked on developing and maintaining high-traffic web applications. #education# B.Sc. in Computer Science, University of Tech, 2019 #licenses# Licensed Professional Engineer (P.E.), Civil Engineering, Board of Professional Engineers, License #12345, Acquired 2022 #skills# Languages: Java, Python, JavaScript #awards# Tools: Git, Docker, Jenkins #name# Jhon mark #email# jhon-t1994@gmail.org #endl#



 */


    return 0;
}



