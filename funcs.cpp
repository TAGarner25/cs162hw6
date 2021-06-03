// Trevor Garner
// CS 162
// file containing functions to read info from user
// sources: ~lliang/cs162/lectures/module5 (from class lecture)

/*
     TODO: None
     TODO:
*/

#include "funcs.h"

float getFloat()	// get floating point from user
{
    float temp;

    cin >> temp;
    while (!cin)
    {
        cin.clear();
        cin.ignore(MAX_CHAR, '\n');

        cout << "You did not enter duration in floating point form (0.00)" << endl;
        cout << "Please try again: ";
        cin >> temp;
    }
    cin.ignore(MAX_CHAR, '\n');
    return temp;
}

void getString(char str[], int maxChar)	// get string from user
{
     cin.get(str, maxChar, '\n');
     while(!cin)
     {
          cin.clear();
          cin.ignore(maxChar, '\n');
     
          cout << "You did not enter anything. Please try again: ";
          cin.get(str, maxChar, '\n');
     }
     cin.ignore(MAX_CHAR, '\n');
}

int getInt()	// get int from user
{
     int  temp;

     cin >> temp;
     while(!cin)
     {    
          cin.clear();
          cin.ignore(MAX_CHAR, '\n');

          cout << "You entered an illegal integer. Please try again: ";
          cin >> temp;
     }
     cin.ignore(MAX_CHAR, '\n');
     return temp;   
}

char getChar()	// get char from user
{
     char temp;

     cin >> temp;
     while(!cin)
     {    
          cin.clear();
          cin.ignore(MAX_CHAR, '\n');

          cout << "You need to enter a character. Please try again: ";
          cin >> temp;
     }
     cin.ignore(MAX_CHAR, '\n');
     return temp;   
}
