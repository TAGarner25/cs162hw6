// Trevor Garner
// header file for funcs.cpp
// sources: ~lliang/cs162/lectures/module5 (from class lecture)
// called by song.h & interface.cpp

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;
#include <cstring>
#include <iomanip>

const int MAX_CHAR = 101;   // max number of characters for a cstring
const int MAX_SIZE = 101;   // max number of songs in songList

float getFloat();	    // gets floating point number from user
void getString(char str[], int maxChar);    // gets cstring from user
int getInt();				    // get int number from user
char getChar();				    // gets char from user

#endif
