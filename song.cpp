// Trevor Garner
// hw6 Song.cpp src
// contains definitions for Song class members

#include "song.h"

// ! IMPORTANT:
// * HIGHLIGHT:
// ? QUESTION:
// TODO:
// wtf
// normal

// default constructor
Song::Song()
{
    // initialize default data members
    // TODO: dont need to declare new & set = to nullptr...
    //! can do either or, but since not using variable immediately, best to just set = to nullptr
    int size = 1;
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
    ! DEEP COPY
	! Not sure this is needed...
    deep copy with Song object as parameter
    constuctor with parameter
*/
Song::Song(const Song& aSong)
{
    // TODO: no need to declare new song obj here...
    // do i need to copy the object?
}

/*
     default constructor
     deep copy by using 'init' function
*/
/*
     * OKAY *
*/
Song::Song(const char title[], const char artist[], float duration, const char album[])
{
    initSong(title, artist, duration, album);
}
/*
     deconstructor
     * OKAY *
*/
Song::~Song()
{
	delete [] title;
	delete [] artist;
	delete duration;
	delete [] album;
}

/*
  * OKAY *
*/
void Song::initSong(const char * title, const char * artist, float duration, const char * album) 
{
    int lenTtl = strlen(title) + 1;
    int lenArt = strlen(artist) + 1;
    int lenAlb = strlen(album) + 1;
     
    this->title = new char[lenTtl];
    this->artist = new char[lenArt];
    this->duration = new float(duration);
    this->album = new char[lenAlb];

    // * OKAY * this is a deep copy.
    strcpy(this->title, title);        // title
    strcpy(this->artist, artist);      // artist
    strcpy(this->album, album);        // album
}

/******************     SETTERS & GETTERS     *****************************/
                    /*   SET VARIABLES  */
// title
// * OKAY *
void Song::setTitle(const char title[])
{
    int len = strlen(title) + 1;
    this->title = new char[len];
    strcpy(this->title, title);
}

// artist
// * OKAY *
void Song::setArtist(const char artist[])
{
    int len = strlen(artist) + 1;
    this->artist = new char[len];
    strcpy(this->artist, artist);
}

// duration
// * OKAY *
void Song::setDuration(float duration)
{
     // deep copy parameter to this->instance of duration
     this->duration = new float(duration);
}

// album
// * OKAY *
void Song::setAlbum(const char album[])
{
    int len = strlen(album) + 1;
    this->album = new char[len];
    strcpy(this->album, album);
}
                    /*   GET VARIABLES  */

// title
// * OKAY *
void Song::getTitle(char * title) const
{
    int len = strlen(this->title) + 1;
    title = new char[len];
    strcpy(title, this->title);
}

// artist
// * OKAY *
void Song::getArtist(char artist[]) const
{
    int len = strlen(this->artist) + 1;
    artist = new char[len];
    strcpy(artist, this->artist);
}

// duration
// * OKAY *
float Song::getDuration() const
{
     float * temp;
     temp = this->duration;
     return *temp;
}

// album
// * OKAY *
void Song::getAlbum(char album[]) const
{
     int len = strlen(this->album) + 1;
     album = new char[len];
     strcpy(album, this->album);
}

/*****************    MEMBER FUNCTIONS    ******************************/

/*
     function getSong
*/
void Song::getSong()
{
     char ttl[MAX_CHAR];
	 char art[MAX_CHAR];
	 char alb[MAX_CHAR];
     float dur;

     cout << "Please enter song title: ";
     getString(ttl, MAX_CHAR);  // read to temp str
     
    //  int len = strlen(tempStr) + 1; // get str len
    //  title = new char[len];  // declare pointer to title
     
     setTitle(ttl);  // copy value to ptr
     
    //  len = 0; // reset values to 0 for reuse
    //  for (int c : tempStr)
    //  {
    //       tempStr[c] = 0;
    //  } 

     cout << "Please enter song artist: ";
     getString(art, MAX_CHAR);
     
    //  len = strlen(tempStr) + 1; // get str len
    //  artist = new char[len];  // declare pointer to title
     
     setArtist(art);  // copy value to ptr
     
    //  len = 0;  // reset values to 0 for reuse
    //  for (int c : tempStr)
    //  {
    //       tempStr[c] = 0;
    //  }

     cout << "Please enter song duration: ";
    //  duration = new float;
     cin >> dur;
    setDuration(dur);
     
     cout << "Please enter song album: ";
     getString(alb, MAX_CHAR);
     
    //  len = strlen(tempStr) + 1; // get str len
    //  album = new char[len];  // declare pointer to title
     
    setAlbum(alb);  // copy value to ptr
     
    //  len = 0; // reset values to 0 for reuse
    //  for (int c : tempStr).3
    //  {
    //       tempStr[c] = 0;
    //  }
     
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
