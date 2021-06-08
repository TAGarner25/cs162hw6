// Trevor Garner
// CS 162 HW6
// Header file: SongList class

#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"	// contains class::Song properties

// ! IMPORTANT:
// * HIGHLIGHT:
// ? QUESTION:
// TODO:
// wtf
// normal

/*
     TODO: update for dynamic memory
     TODO: default constructor initialized memory for Song* list
*/
class SongList
{
private:
     Song * list;    // ptr to song obj
     int SIZE;
public:
     // constructor & deconstructor
     SongList();		    // default constructor
     // ? Do i need this copy?
     SongList(const Song& aSong); 
     ~SongList();		    // destructor

     // program functions
     void loadSongs(const char fileName[]);
     void saveSongs(const char fileName[]) const;

     // interface functions
     bool addSongs(const Song& newSong);
     void removeSongs(int removeIdx);       
     void printSongs() const;
     void searchSongs(const char name[], int searchBy) const;  
     
     
};

#endif
