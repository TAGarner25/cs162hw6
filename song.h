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
	// constructor with parameters 
	Song(const char *title, const char *artist, float *duration, const char *album);	
	// functions
	void print(int index) const; // print song
	void getSong();
	 
	// setters
	void setTitle(const char * title);
	void setArtist(const char * artist);
	void setDuration(float * duration);
	void setAlbum(const char * album);

	// getters
	void getTitle(char * title) const;
	void getArtist(char * artist) const;
	float getDuration() const;
	void getAlbum(char * album) const;

private:
	// declare pointers to be initialized upon creation
	char	* title;
	char	* artist;
	float	* duration;
	char	* album;

	void initSong(const char * title, const char * artist, float * duration, const char * album);
};

#endif
