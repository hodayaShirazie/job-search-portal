//
// Created by Student on 27/02/2024.
//

#include "Colors.h"
#include <iostream>


/*

    setColorANSI(0); // Reset text color.
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




void Colors :: setColorANSI(int colorCode) {
    std::cout << "\033[" << colorCode << "m";
}
void Colors :: enableVirtualTerminalProcessing() {
    // Get the handle to the standard output.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    // Retrieve the current console mode.
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    // Enable Virtual Terminal Processing.
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) return;
}