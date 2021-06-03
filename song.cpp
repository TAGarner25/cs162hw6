// Trevor Garner
// hw6 Song.cpp src
// contains definitions for Song class members

#include "song.h"

// default constructor
Song::Song()
{
	int size = 1;
     // initialize default data members
     title = new char[size];
     artist = new char[size];
     duration = new float;
     album = new char[size];
}

/*
     constuctor with parameters
     TODO: why would i use this?...
*/
Song::Song(Song& aSong, int lenTitle, int lenArtist, int LenAlbum)
{
	title = new char[lenTitle];
	artist = new char[lenArtist];
	duration = new float;
	album = new char[lenAlbum];

	strncpy(this->title, aSong->title, lenTitle);
	this->*duration = aSong->duration;
	strncpy(this->artist, aSong->artist, lenArtist);
	strncpy(this->album, aSong->album, lenAlbum);
     // call init function
     initSong(&title, &artist, &duration, &album);

}

/*
     deconstructor
*/
Song::~Song()
{
	delete title[];
	delete artist[];
	delete duration;
	delete album[];
}

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
void Song::setTitle(const char title[])
{
    size_t len = strlen(title) + 1;
    this->title = new char[len];
    strcpy(this->title, title);
}

// artist
void Song::setArtist(const char artist[])
{
    size_t len = strlen(artist) + 1;
    this->artist = new char[len];
    strcpy(this->artist, artist);
}

// duration
void Song::setDuration(float duration)
{
     this->duration = new float;
     duration = duration;
}

// album
void Song::setAlbum(const char album[])
{
    size_t len = strlen(album) + 1;
    this->album = new char[len];
    strcpy(this->album, album);
}
                    /*   GET VARIABLES  */

// title
void Song::getTitle(char * title) const
{
     strcpy(title, this->title);
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
