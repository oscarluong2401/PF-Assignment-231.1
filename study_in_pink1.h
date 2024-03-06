/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Support functions
bool checkEventCode(int E);
int roundUp(double val);
void updateHP(int &HP);
void updateEXP(int &EXP);
void updateM(int &M);

// Task 1
void info1(int & EXP2, int E1);
void info2(int & EXP2, int E1);
void info3(int & EXP2, int E1);
int firstMeet(int & EXP1, int & EXP2, int E1);

// Task 2
void recover(int &HP1, int &M1);
void travel(int &EXP1, int &M1);
void follow(int &EXP1, int &M1);
double expToProb(int val);
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
bool isSpecial(char c);
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
