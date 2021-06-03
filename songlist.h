// Trevor Garner
// CS 162 HW5
// Class header: SongList

#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"	// contains class::Song properties

/*
     TODO: update for dynamic memory
*/
class SongList
{
private:

     const static int CAP = 100;    // max capacity for list
	 int SIZE = -1;
     //Song list[CAP];		    // original arr
     Song* list = new Song[SIZE];	    // ptr to song obj

public:

     // constructor & deconstructor
     SongList();		    // default
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
