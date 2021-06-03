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
	 int SIZE = -1;
     //Song list[CAP];		    // original arr
     Song* list;	    // ptr to song obj

public:

     // constructor & deconstructor
     SongList() {list = new Song[SIZE]};		    // default constructor
     //SongList();           // copy
     ~SongList();		    // destructor

     // program functions
     void loadSongs(const char fileName[]);
     void saveSongs(const char fileName[]) const;

     // interface functions
     bool addSongs(const Song * newSong);
     void removeSongs(int removeIdx);        
     void printSongs() const;
     void searchSongs(const char * name, int searchBy) const;  
};

#endif
