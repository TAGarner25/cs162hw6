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
     TODO: null
*/
class SongList
{
public:
    // constructor & deconstructor
    SongList();		                    	// default ctor
    SongList(const Song &);        			// copy ctor
	SongList(Song &&);						// move ctor
    ~SongList();		                	// dtor

	// assignment operators: take values from rhs and store in *this
    SongList & operator = (const Song &); 	// copy assign
    SongList & operator = (Song &&);		// move assign
    
	// array subscript operators:
    int & operator [] (size_t); 		    // reference subscript
	const int & operator [] (size_t) const; // value subscript
	
	// stream operators
    // SongList & operator << (const Song &);                     // insert
    // SongList & operator >> (Song &);                           // extract
	friend ostream & operator << (ostream &, const SongList &);   // stream insertion
	friend istream & operator >> (istream &, SongList &);         // stream extraction

    /*
		Operations
			load list
			save list
			display list
			add song
			remove song
			search list
	*/
    void loadSongs(const char fileName[]);
    void saveSongs(const char fileName[]) const;
    bool addSongs(const Song & newSong);
    void removeSongs(int removeIdx);
    void printSongs() const;
    void searchSongs(const char name[], int searchBy) const;  

private:

    Song * list;    // list of songs 
    int length;

};

// relational operators
// bool operator == (const SongList &, const SongList &);  // Equal
// bool operator <  (const SongList &, const SongList &);  // Less than
// bool operator <= (const SongList & lhs, const SongList & rhs) {return !(lhs > rhs);}  // Less than or equal
// bool operator != (const SongList & lhs, const SongList & rhs) {return !(lhs == rhs);}  // Not equal
// bool operator >= (const SongList & lhs, const SongList & rhs) {return !(lhs < rhs);}  // Greater than or equal
// bool operator >  (const SongList & lhs, const SongList & rhs) {return !(lhs <= rhs);}  // Greater than

#endif
