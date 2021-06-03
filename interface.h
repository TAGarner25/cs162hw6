// Trevor Garner
// CS162 HW5
// Header file for interface.cpp
// Contains prototypes of the functions that are used to run main.cpp

#ifndef INTERFACE_H
#define INTERFACE_H

#include "songlist.h"


/*
     TODO:
*/

// prototypes
void start();                                // Run program
void menu();                                 // Display menu options
int readAction();                            // Read user decision
void execute(int action, SongList& list);	// Execute users decision
char repeatAction();                         // Ask if user wants to repeat action
void addToList(SongList& list);			// Add a song to the songlist
void removeFromList(SongList& list);		// Remove a song from the songlist
void searchList(SongList& list);			// Search the song list for a given string & print result


#endif
