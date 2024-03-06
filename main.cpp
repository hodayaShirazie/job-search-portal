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

    Colors color;
    color.enableVirtualTerminalProcessing();

    Administrator a;
    a.enterSystem();


    return 0;
}



