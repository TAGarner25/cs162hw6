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

     title = nullptr;
     artist = nullptr;
     duration = nullptr;
     album = nullptr;
}

/*
     constuctor with parameters
     TODO: why would i use this?...
*/
Song::Song(const Song& aSong)
{
     Song * newSong = new Song;
     *newSong = aSong;
}

/*
     deconstructor
*/
Song::~Song()
{
	delete [] title;
	delete [] artist;
	delete duration;
	delete [] album;
}

/*
  init object song
  params
     char title
     char artist
     float duration
     char album
*/
void Song::initSong(const char * title, const char * artist, float * duration, const char * album) 
{
     size_t lenTtl = strlen(title) + 1;
     size_t lenArt = strlen(artist) + 1;
     size_t lenAlb = strlen(album) + 1;
     
     title = new char[lenTtl];
     artist = new char[lenArt];
     duration = new float;
     album = new char[lenAlb];

     strcpy(this->title, title);        // title
     strcpy(this->artist, artist);      // artist
     this->duration = duration;         // duration
     strcpy(this->album, album);        // album
}

/******************     SETTERS & GETTERS     *****************************/

                    /*   SET VARIABLES  */
// title
void Song::setTitle(const char title[])
{
    size_t len = strlen(title) + 1;
    //this->title;
    strncpy(this->title, title, len);
}

// artist
void Song::setArtist(const char * artist)
{
    size_t len = strlen(artist) + 1;
    strncpy(this->artist, artist, len);
}

// duration
void Song::setDuration(float * duration)
{
     // deep copy parameter to this->instance of duration
     this->duration = new float(*(duration));
}

// album
void Song::setAlbum(const char album[])
{
    size_t len = strlen(album) + 1;
    strncpy(this->album, album, len);
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
     size_t len = strlen(this->artist) + 1;
     strcpy(artist, this->artist);
}

// duration
float Song::getDuration() const
{
     float * temp;
     temp = this->duration;
     return *temp;
}

// album
void Song::getAlbum(char album[]) const
{
     size_t len = strlen(this->album) + 1;
     strcpy(album, this->album);
}

/*****************    MEMBER FUNCTIONS    ******************************/

/*
     function getSong
*/
void Song::getSong()
{
     char tempStr[MAX_CHAR];
     float tempFlt;

     cout << "Please enter song title: ";
     getString(tempStr, MAX_CHAR);  // read to temp str
     int len = strlen(tempStr) + 1; // get str len
     char * title = new char[len];  // declare pointer to title
     strcpy(this->title, tempStr);  // copy value to ptr
     for (auto c : tempStr)
     {
          tempStr[c] = 0;
     } 

     cout << "Please enter song artist: ";
     getString(tempStr, MAX_CHAR);
     int len = strlen(tempStr) + 1; // get str len
     char * artist = new char[len];  // declare pointer to title
     strcpy(this->artist, tempStr);  // copy value to ptr
     for (auto c : tempStr)
     {
          tempStr[c] = 0;
     }

     cout << "Please enter song duration: ";
     float * duration = new float;
     cin >> *duration;
     
     cout << "Please enter song album: ";
     getString(album, MAX_CHAR);
     int len = strlen(tempStr) + 1; // get str len
     char * talbum = new char[len];  // declare pointer to title
     strcpy(this->album, tempStr);  // copy value to ptr
     for (auto c : tempStr)
     {
          tempStr[c] = 0;
     }
     
}


// printSong function
// parameters
//   int index: used to print index position of song in list
void Song::print(int index) const
{
     cout << setprecision(4);
     cout << "Index:     " << index << endl;      // idx of Song list[]
     cout << "Title:     " << *title << endl;      // this-> title
     cout << "Artist:    " << *artist << endl;     // this-> artist
     cout << "Duration:  " << *duration << endl;   // this-> duration
     cout << "Album:     " << *album << endl;      // this-> album
     cout << "--------------------------------------------"
          << endl;
	cout << endl;
}
