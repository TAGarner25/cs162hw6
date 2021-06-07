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

	int SIZE = 0;
     Song* list;    // ptr to song obj

public:

     // constructor & deconstructor
     SongList();		    // default constructor
     // ? Do i need this copy?
     SongList(const Song& aSong); // TODO: make a deep copy constructor
     ~SongList();		    // destructor

     // program functions
     void loadSongs(const char fileName[]);
     void saveSongs(const char fileName[]) const;

     // interface functions
     bool addSongs(const Song& newSong);
     void removeSongs(int removeIdx);        // TODO: do I need parameter still?
     void printSongs() const;
     void searchSongs(const char * name, int searchBy) const;  // TODO: need parameter still?
     
     SongList operator=(const int& rhs)
     {
          return *this = rhs;
     }
};

#endif
