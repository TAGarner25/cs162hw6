// Trevor Garner
// hw5 Song.cpp src
// contains definitions for Song class members

#include "song.h"

// default constructor
Song::Song()
{
     // initialize default data members
     title = nullptr;
     artist = nullptr;
     duration = nullptr;
     album = nullptr;
}

/*
     constuctor with parameters
     TODO: why would i use this?...
*/
Song::Song(const char *  title, const char * artist, float * duration, const char * album)
{
     // call init function
     initSong(title, artist, duration, album);

}

/*
     deconstructor
*/
Song::~Song() {}

/*
  init object song
  params
     char title
     char artist
     float duration
     char album
*/
void Song::initSong(const char * ttl, const char * art, float * dur, const char * alb) 
{
     size_t lenTtl = strlen(ttl) + 1;
     size_t lenArt = strlen(art) + 1;
     size_t lenAlb = strlen(alb) + 1;
     
     title = new char[lenTtl];
     artist = new char[lenArt];
     duration = new float;
     album = enw char[lenAlb];

     strcpy(this->title, ttl);        // title
     strcpy(this->artist, art);      // artist
     this->duration = dur;         // duration
     strcpy(this->album, alb);        // album
}

/******************     SETTERS & GETTERS     *****************************/

                    /*   SET VARIABLES  */
// title
void Song::setTitle(const char * ttl)
{
    size_t len = strlen(ttl) + 1;
    title = new char[len];
    strcpy(this->title, ttl);
}

// artist
void Song::setArtist(const char * art)
{
    size_t len = strlen(art) + 1;
    artist = new char[len];
    strcpy(this->artist, art);
}

// duration
void Song::setDuration(float * dur)
{
     duration = new float;
     duration = dur;
}

// album
void Song::setAlbum(const char * alb)
{
    size_t len = strlen(alb) + 1;
    album = new char[len];
    strcpy(this->album, alb);
}
                    /*   GET VARIABLES  */

// title
void Song::getTitle(char * title) const
{
     temp = new title;
     temp = &title;
     strcpy( this->title);
}

// artist
void Song::getArtist(char artist[]) const
{
     strcpy(artist, this->artist);
}

// duration
float Song::getDuration() const
{
     return duration;
}

// album
void Song::getAlbum(char album[]) const
{
     strcpy(album, this->album);
}

/*****************    MEMBER FUNCTIONS    ******************************/

/*
     function getSong
*/
void Song::getSong()
{
 
     cout << "Please enter song title: ";
     getString(title, MAX_CHAR);
    
     cout << "Please enter song artist: ";
     getString(artist, MAX_CHAR);

     cout << "Please enter song duration: ";
     duration = getFloat();
     
     cout << "Please enter song album: ";
     getString(album, MAX_CHAR);
     
}


// printSong function
// parameters
//   int index: used to print index position of song in list
void Song::print(int index) const
{
     cout << setprecision(4);
     cout << "Index:     " << index << endl;      // idx of Song list[]
     cout << "Title:     " << title << endl;      // this-> title
     cout << "Artist:    " << artist << endl;     // this-> artist
     cout << "Duration:  " << duration << endl;   // this-> duration
     cout << "Album:     " << album << endl;      // this-> album
     cout << "--------------------------------------------"
          << endl;
	cout << endl;
}


