/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"

using namespace std;

void sa_tc_01() {
//    cout << firstMeet(EXP1, EXP2, E1) << endl;
    cout << "----- Disrespect Testcase 02 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
        cout << traceLuggage(HP1, EXP1, M1, E2) << endl;
    }
//    cout << chaseTaxi(HP1, EXP1, HP2, EXP2, E3) << endl;
//    cout << "----- Sample Testcase 02 -----" << endl;
//    const char* s = "HhTdgc@RkFHNxoVyYppiDKCmCXPLj!DclXjT";
//    const char* email = "wJeVUUzXbLwMqqcihYMXhMnUykGkbOORgaEdsjaLCCk@hotmail.com";
//    cout << checkPassword(s, email) << endl;
//    cout << "----- Sample Testcase 03 -----" << endl;
//    const char* arr_pwds[] = {"F%gIcRy!LIaJ","lGK@$EbX#VoeGYuJnT%a","pwiJUBo@vX","R$IfrnZgKG","LdsRePMB@F","GnFpXqYvZ@y","oltdXeOJviQJq%XTw","GnFpXqYvZ@y","#fSIwMpay","lGK@$EbX#VoeGYuJnT%a","F%gIcRy!LIaJ","RMrSVSPA#W","#iu!CFQVuwZ","oltdXeOJviQJq%XTw"};
//    cout << findCorrectPassword(arr_pwds, 14) << endl;
//    cout << ceil(440*1.1) << endl;
//    cout << int(floor(440*1.1 + 0.999)) << endl;
//    cout << ceil(440 + 440*0.1) << endl;
}

int main(int argc, const char * argv[]) {
    cout << "----- Disrespect Testcase 02 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
//    if (readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
//        cout << chaseTaxi(HP1, EXP1, HP2, EXP2, E3) << endl;
//        cout << HP1 << " " << HP2 << " " << EXP1 << " " << EXP2 << endl;
//    }
//    return 0;
    sa_tc_01();
    return 0;
}