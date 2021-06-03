// Trevor Garner
// CS 162 HW5
// class header: Song

#ifndef SONG_H
#define SONG_H

#include "funcs.h"	// gives extra functionality (like iostream)       

/*
     TODO: check pointer declaration
     TODO: check function paramters (pointers being passed)
*/
class Song
{
public:
     // constructors & deconstructor
     // order: default, with all params, deconstructor
     Song();
     Song(const char * title, const char * artist, float * duration, const char * album);
     ~Song();
     
     // setters
     void setTitle(const char * title);             // set title
     void setArtist(const char * artist);           // set artist
     void setDuration(float * duration);              // set duration
     void setAlbum(const char * album);             // set album

     // getters
     void getTitle(char * title) const;             // get title
     void getArtist(char * artist) const;           // get artist
     float getDuration() const;                     // get duration
     void getAlbum(char * album) const;             // get album

     // other functions
     void print(int index) const;             // print song information
     void getSong();                             // get song from user

private:
     // NEED TO HAVE MAX_SIZE DYNAMICALLY CHANGE BASED OFF SIZE OF STRING BEING READ IN
     char * title;                        // title c string
     char * artist;                       // artist c string
     float * duration;                              // duration of song
     char * album;                        // album c string
     // used to initialize instance
     void initSong(const char * title, const char * artist, float * duration, const char * album);
};

#endif     


class Song
{
public:
     Song();   // constructor
     ~Song();  // destructor
     Song(const Song& aSong); // copy constructor

     void print() const; // print song

private:

}