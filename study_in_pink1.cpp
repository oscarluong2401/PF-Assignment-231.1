#include "study_in_pink1.h"

bool readFile(const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3){
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Support functions
bool checkEventCode(int E) { return E >= 0 && E <= 99; }
int roundUp(double val) { return int(val + 0.999); } // changed because ceil(400*1.1) = 441?!?
void updateHP(int &HP) { if (HP < 0) HP = 0; if (HP > 666) HP = 666; }
void updateEXP(int &EXP) { if (EXP < 0) EXP = 0; if (EXP > 600) EXP = 600; }
void updateM(int &M ){ if (M < 0) M = 0; if (M > 3000) M = 3000; }

// Task 1
void info1(int & EXP2, int E1) { EXP2 += roundUp(double(E1) / 4 + 19); }
void info2(int & EXP2, int E1) { EXP2 += roundUp(double(E1) / 9 + 21); }
void info3(int & EXP2, int E1) { EXP2 += roundUp(double(E1) / 16 + 17); }
int firstMeet(int & EXP1, int & EXP2, int E1) {
    if (!checkEventCode(E1)) return -99;
    updateEXP(EXP1); updateEXP(EXP2);
    if (E1 <= 3){
        if (E1 == 0) EXP2 += 29;
        else if (E1 == 1) EXP2 += 45;
        else if (E1 == 2) EXP2 += 75;
        else EXP2 += 149;
        updateEXP(EXP2);
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2) EXP1 = roundUp(EXP1 - (double)D / 100);
        else EXP1 = roundUp(EXP1 + (double)D / 200);
        updateEXP(EXP1);
    } else {
        if (E1 <= 19) info1(EXP2, E1);
        else if (E1 <= 49) info2(EXP2, E1);
        else if (E1 <= 65) info3(EXP2, E1);
        else if (E1 <= 79){
            info1(EXP2, E1); if (EXP2 > 200) info2(EXP2, E1);
        } else {
            info1(EXP2, E1); info2(EXP2, E1);
            if (EXP2 > 400){
                info3(EXP2, E1); EXP2 = roundUp(EXP2 * 1.15);
            }
        }
        EXP1 -= E1;
        updateEXP(EXP1);updateEXP(EXP2);
    }
    return EXP1 + EXP2;
}

// Task 2
void recover(int &HP1, int &M1){
    if (HP1 < 200){
        HP1 = roundUp(HP1 * 1.3); M1 -= 150;
    } else {
        HP1 = roundUp(HP1 * 1.1); M1 -= 70;
    } 
    updateHP(HP1); updateM(M1);
}
void travel(int &EXP1, int &M1){
    if (EXP1 < 400) M1 -= 200; else M1 -= 120;
    EXP1 = roundUp(EXP1 * 1.13); updateEXP(EXP1);
    updateEXP(EXP1); updateM(M1);
}
void follow(int &EXP1, int &M1){
    if (EXP1 < 300) M1 -= 100; else M1 -= 120;
    EXP1 = roundUp(EXP1 * 0.9);
    updateEXP(EXP1); updateM(M1);
}
double expToProb(int val){
    int k = (int(sqrt(val) + 0.5))*(int(sqrt(val) + 0.5));
    return val >= k ? 1.0 : (1.0 * val / k + 80) / 123;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (!checkEventCode(E2)) return -99;
    updateHP(HP1); updateEXP(EXP1); updateM(M1);
    double P1 = expToProb(EXP1);
    int initM = M1;
    // if M1 = 0, stop immediately
    if (E2 % 2){
        while (M1){
            recover(HP1, M1); if ((double)M1 < (double)initM / 2) break;
            travel(EXP1, M1); if ((double)M1 < (double)initM / 2) break;
            follow(EXP1, M1); if ((double)M1 < (double)initM / 2) break;
        }
    } else {
        if (M1) recover(HP1, M1);
        if (M1) travel(EXP1, M1);
        if (M1) follow(EXP1, M1);
    }
    HP1 = roundUp(HP1 * 0.83); updateHP(HP1);
    EXP1 = roundUp(EXP1 * 1.17); updateEXP(EXP1);
    double P2 = expToProb(EXP1);
    double P[10] {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
    double P3 = P[(E2 / 10 + E2) % 10];
    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 = roundUp(EXP1 * 0.75); updateEXP(EXP1);
    } else if (P1 + P2 + P3 < 1.5) {
        HP1 = roundUp(HP1 * 0.85); updateHP(HP1);
        EXP1 = roundUp(EXP1 * 1.15); updateEXP(EXP1);
    } else {
        HP1 = roundUp(HP1 * 0.9); updateHP(HP1);
        EXP1 = roundUp(EXP1 * 1.2); updateEXP(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (!checkEventCode(E3)) return -99;
    updateHP(HP1); updateEXP(EXP1); updateHP(HP2); updateEXP(EXP2);
    int arr[10][10], smaller = 0, larger = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = (E3 * j + 2 * i) * (i - j);
            if (arr[i][j] > 2 * E3) larger++;
            if (arr[i][j] < -E3) smaller++;
        }
    }
    int x = larger % 9 ? larger % 9 : (larger ? 9 : 0);
    int y = smaller % 9 ? smaller % 9 : (smaller ? 9 : 0);
    int max = INT_MIN;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i + j == x + y || i - j == x - y) {
                if (arr[i][j] > max) max = arr[i][j];
            }
        }
    }
    int catchCoeff = abs(arr[x][y]) > abs(max) ? -1 : 1;
    EXP1 = roundUp(EXP1 * (1 + 0.12 * catchCoeff)); updateEXP(EXP1);
    EXP2 = roundUp(EXP2 * (1 + 0.12 * catchCoeff)); updateEXP(EXP2);
    HP1 = roundUp(HP1 * (1 + 0.1 * catchCoeff)); updateHP(HP1);
    HP2 = roundUp(HP2 * (1 + 0.1 * catchCoeff)); updateHP(HP2);
    return abs(arr[x][y]) > abs(max) ? arr[x][y] : max;
}

// Task 4
bool isSpecial(char c) { return c == '!' || c == '@' || c == '#' || c == '$' || c == '%'; }
int checkPassword(const char *s, const char *email) {
    int len = (int)strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;
    // get the substring before @ (guaranteed to exist)
    string se;
    for (int i = 0; email[i] != '@'; i++) se += email[i];
    if (strstr(s, se.c_str()) != NULL){
        // find the first occurrence of se in s (pointer style)
        return -300 - (int)(strstr(s, se.c_str()) - s);
    }
    for (int i = 0; i < len - 2; i++) {
        if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2])) return -400 - i;
    }
    bool specialCharFound = false;
    for (int i = 0; i < len; i++) {
        if (isSpecial(s[i])) {
            specialCharFound = true;
        }
    }
    if (!specialCharFound) return -5;
    for (int i = 0; i < (int)strlen(s); i++) if (!isalnum(s[i]) && !isSpecial(s[i])) return i;
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    if (num_pwds <= 0) return -1;
    int max_count = 0, max_length = 0, correct_index = -1;
    for (int i = 0; i < num_pwds; i++) {
        const char *pwd = arr_pwds[i];
        int length = strlen(pwd), count = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(pwd, arr_pwds[j]) == 0) count++;
        }
        if (count > max_count || (count == max_count && length > max_length)) {
            max_count = count; max_length = length;
            correct_index = i;
        }
    }
    return correct_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////