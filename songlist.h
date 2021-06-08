// Trevor Garner
// CS 162 HW6
// Header file: SongList class

#ifndef SONGLIST_H
#define SONGLIST_H

#include "song.h"	// contains class::Song properties

// ! check on
// * completed
// ? not sure what to do...
// TODO: items needing completion
// normal

/*
     TODO: 
*/
class SongList
{
public:
    // constructor & deconstructor
    SongList();		                    	// default ctor
    SongList(const Song& aSong);        	// copy ctor
    ~SongList();		                	// dtor

	// assignment operators: take values from rhs and store in lhs
    SongList & operator = (const Song &); 	// copy assign
    SongList & operator = (Song &&);		// move assign
    
	// array subscript operators:
    Song & operator [] (int); 				// reference subscript
	const Song & operator [] (int) const; 	// value subscript
	
	// stream operators
	friend std::ostream & operator << (std::ostream &, const SongList &); 	// stream insertion
	friend std::istream & operator >> (std::istream &, SongList &);         // stream extraction

     
    // program functions
    void loadSongs(const char fileName[]);
    void saveSongs(const char fileName[]) const;
	int * size() const;

    // mutators
    bool addSongs(const Song& newSong);
    void removeSongs(int removeIdx);

	// accessors       
    void printSongs() const;
    void searchSongs(const char name[], int searchBy) const;  

private:

    Song * list;    // ptr to song obj
    int SIZE;

};

// relational operators
bool operator == (const SongList &, const SongList &);  // Equal
bool operator <  (const SongList &, const SongList &);  // Less than
bool operator <= (const SongList & lhs, const SongList & rhs) {return !(lhs > rhs);}  // Less than or equal
bool operator != (const SongList & lhs, const SongList & rhs) {return !(lhs == rhs);}  // Not equal
bool operator >= (const SongList & lhs, const SongList & rhs) {return !(lhs < rhs);}  // Greater than or equal
bool operator >  (const SongList & lhs, const SongList & rhs) {return (rhs > lhs)}  // Greater than

#endif
