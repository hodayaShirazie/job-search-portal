#include <iostream>
#include "CV.h"
#include "Candidate.h"
#include "Administrator.h"
#include <stdlib.h>
#include <cstring>
#include "Employer.h"

//got link: https://github.com/hodayaShirazie/job-search-portal.git

void draftColor()
{
//#include <iostream>
//#include <windows.h>

//// c = 7 for default color
//void setConsoleColor(WORD c)
//{
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
//}
//
//int main()
//{
//    setConsoleColor(FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED );
//    std::cout << "Hello\n";
//    setConsoleColor( BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED );
//    std::cout << "Goodbye\n";
//    setConsoleColor(7);
//}
}

void checkCV(){
    CV cv("rina","hodaya.sh2003@gmail.com");
    cv.createCV();
    cv.print();

}




void validemailC(){
        char buffer [80];
        char* email;
        bool existsSign = false;
        bool invalidEmail = false;
        bool invalidProfix = false;
//    while (!invalidEmail || !invalidProfix || !existsSign) {
        while(!invalidEmail) {
            cout << "email" << endl;
            cin.getline(buffer, 20);
            email = new char[strlen(buffer) + 1];
            strcpy(email, buffer);
            int lenEmail = strlen(email);

//        //if email does not end with .org/.com/.il
//        if ((email[lenEmail - 1] == 'm' && email[lenEmail - 2] == 'o' && email[lenEmail - 3] == 'c' &&
//             email[lenEmail - 4] == '.')
//            || (email[lenEmail - 1] == 'g' && email[lenEmail - 2] == 'r' && email[lenEmail - 3] == 'o' &&
//                email[lenEmail - 4] == '.') ||
//                (email[lenEmail - 1] == 'l' && email[lenEmail - 2] == 'i' && email[lenEmail - 3] == '.'))
//            invalidProfix = true;


            //if email contains invalid characters
            for (int i = 0; email[i] != '\0' && invalidEmail; ++i) {
                if (!(email[i] > 'a' && email[i] < 'z' || email[i] > 'A' && email[i] < 'Z'))
                    if (!(email[i] > '0' && email[i] < '9'))
                        if (!(email[i] == '-' && email[i] < '.'))
                            if (!(email[i] == '@')) {
                                invalidEmail = false; //email is not valid
                                cout << "enter a valid ";
                            }
                            else
                                invalidEmail = true;



//            if (email[i] == '@')
//                existsSign = true;
            }

        }

}



#include <fstream>
using std::ios;
using std::fstream;



int main() {

//    char s [80] = "\0";
//    cout <<"s= "<<s<<endl;
//    strcat(s," uuu");
//    strcat(s," tttttt");




    Administrator a;
//    a.print();
    a.enterSystem();
//TODO fix none in cv
/*

e idemp1 password1 userName email phoneNumber birthDatee
c id1 password4 userName email phoneNumber birthDate freeTxt
e idemp2 password6 userName email phoneNumber birthDate
c id3 password4 userName email phoneNumber birthDate freeTxt
e idemp3 password4 userName email phoneNumber birthDate
c id9 password6 userName email phoneNumber birthDate freeTxt
c id8 password6 userName email phoneNumber birthDate freeTxt

id1 summary ppp ppp pppppp  experience oo oooo oooooo  education llll llll llllll  licenses iii iii iiiiiiii  skills bbbbbb bbb bbbb  awards mmmmmmm mmm mmmm  name pppppp ppp ppp  email oooooo ooo ooo  endl
id3 summary tttttttttttttttttt  experience rrrrrrrrrrrrrrrrrrrrrrr  education wwwwwwwwwwwwwwwwwwwwwww  licenses qqqqqqqqqqqqqqqqqqqqqqq  skills ggggg gggggggg  awards jjjjjj jjjjjjj  name ttttt ttttttt  email rrrrr rrrrrrrrrrrr  endl
id9 summary ppp ppp pppppp  experience oo oooo oooooo  education llll llll llllll  licenses iii iii iiiiiiii  skills bbbbbb bbb bbbb  awards mmmmmmm mmm mmmm  name pppppp ppp ppp  email oooooo ooo ooo  endl




 */


    return 0;
}




