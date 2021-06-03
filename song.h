// Trevor Garner
// CS 162 HW5
// class header: Song

#ifndef SONG_H
#define SONG_H

#include "utils.h"	// gives extra functionality (like iostream)       

/*
     TODO: check pointer declaration
     TODO: check function paramters (pointers being passed)
*/
class Song
{
public:
    Song();   // constructor
    ~Song();  // destructor
    Song(const Song& aSong); // copy constructor
	
	// functions
	void print() const; // print song
	void getSong();
	 
	// setters
	void setTitle(const char * ttl);
	void setArtist(const char * art);
	void setDuration(float * dur);
	void setAlbum(const char * alb);

	// getters
	void getTitle(char * ttl) const;
	void getArtist(char * art) const;
	float getDuration() const;
	void getAlbum(char * alb) const;

private:
	// declare pointers to be initialized upon creation
	char* title;
	char* artist;
	float* duration;
	char* album;

	void initSong(const char * ttl, const char * art, float * dur, const char * alb);
};

#endif
