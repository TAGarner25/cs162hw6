// Trevor Garner
// CS 162 HW6
// Header file: SongList class

#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"	// contains class::Song properties

/*
     TODO: update for dynamic memory
     TODO: default constructor initialized memory for Song* list
*/
class SongList
{
private:

     const static int CAP = 100;    // max capacity for list
	int SIZE = 0;
     //Song list[CAP];		    // original arr
     Song* list;    // ptr to song obj

public:

     // constructor & deconstructor
     SongList();		    // default constructor
     SongList(const Song& aSong); // TODO: make a deep copy constructor
     ~SongList();		    // destructor

     // program functions
     void loadSongs(const char fileName[]);
     void saveSongs(const char fileName[]) const;

     // interface functions
     bool addSongs(const Song& newSong);    // TODO: ensure correct format & ensure deep copy of 'aSong'
     void removeSongs(int removeIdx);        // TODO: do I need parameter still?
     void printSongs() const;
     void searchSongs(const char * name, int searchBy) const;  // TODO: need parameter still?
     
};

#endif
