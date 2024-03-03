//
// Created by Student on 27/02/2024.
//

#include "Colors.h"


void Colors :: setConsoleColor(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}