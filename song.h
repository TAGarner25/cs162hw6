// Trevor Garner
// CS 162 HW5
// class header: Song

#ifndef SONG_H
#define SONG_H

#include "utils.h"	// gives extra functionality      

/*
     TODO: check pointer declaration
     TODO: check function paramters (pointers being passed)
*/
class Song
{

public:
    Song();   // default constructor
    ~Song();  // destructor
    Song(const Song& aSong); // ! deep copy constructor
	// constructor with parameters 
	Song(const char title[], const char artist[], float duration, const char album[]);	
	// functions
	void print(int index) const; // ! print index in song list
	void getSong();
	 
	// setters
	void setTitle(const char title[]);
	void setArtist(const char  artist[]);
	void setDuration(float duration);
	void setAlbum(const char album[]);

	// getters
	void getTitle(char * title) const;
	void getArtist(char * artist) const;
	float getDuration() const;
	void getAlbum(char * album) const;

private:
	// declare pointers 
	char * title;
	char * artist;
	float duration;
	char * album;

	// ? is this correct ?
	void initSong(const char title[], const char artist[], float duration, const char album[]);

// ! add operator declarations (operator overload)
//	used to help 'streamline' the coding process. 

// friend:

};

#endif
