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


// TODO: update constructors, and function definitions

// default constructor
Song::Song()
{
	// initialize default data members
	title = nullptr;
	artist = nullptr;
	duration = nullptr;
	album = nullptr;
}

// constructor with pointers to all Song variables as parameters
Song::Song(const char * title, const char * artist, float * duration, const char * album)
{
	// allocate memory
	this->title = new char[strlen(title) + 1];
	this->artist = new char[strlen(artist) + 1];
	this->duration = new float(*duration);   // allocated and initialized to value pointed to by duration
	this->album = new char[strlen(album) + 1];

	// copy params to allocated memory
	strcpy(this->title, title);        // title
	strcpy(this->artist, artist);      // artist
	strcpy(this->album, album);        // album
}

// * BIG THREE
// dtor
Song::~Song()
{
	delete [] this->title;
	delete [] this->artist;
	delete this->duration;
	delete [] this->album;
}

// copy constructor
Song::Song(const Song& aSong)
{
	// allocate memory
	this->title = new char[strlen(aSong.title) + 1];
	this->artist = new char[strlen(aSong.artist) + 1];
	this->duration = new float;
	this->album = new char[strlen(aSong.album) + 1];

	// copy 
	strcpy(this->title, aSong.title);
	strcpy(this->artist, aSong.artist);
	aSong.getDuration(this->duration);
	strcpy(this->album, aSong.album);
}

// copy assignment
Song & Song::operator = (const Song & rhsSong) 
{
	// self assignment check
	if (this == &rhsSong)
	{
		return * this;
	}

	// check ptrs
	delete [] title;
	delete [] artist;
	delete duration;
	delete [] album;

	// memory allocation
	this->title = new char[strlen(rhsSong.title) + 1];
	this->artist = new char[strlen(rhsSong.artist) + 1];
	this->duration = new float;
	this->album = new char[strlen(rhsSong.album) + 1];

	// copy 
	strcpy(this->title, rhsSong.title);
	strcpy(this->artist, rhsSong.artist);
	rhsSong.getDuration(this->duration);
	strcpy(this->album, rhsSong.album);

	return *this;
}

/*
!   *****************     SETTERS & GETTERS     ****************************
*/
// !   SET VARIABLES

// title
void Song::setTitle(const char title[])
{
	this->title = new char[strlen(title) + 1];	// allocate memory
	strcpy(this->title, title); // copy info to memory
}

// artist
void Song::setArtist(const char artist[])
{
	this->artist = new char[strlen(artist) + 1]; // allocate memory
	strcpy(this->artist, artist); // copy info to memory
}

// duration
void Song::setDuration(float duration)
{
	 this->duration = new float(duration); // allocated and initialized to value pointed to by duration
}

// album
void Song::setAlbum(const char album[])
{
	this->album = new char[strlen(album) + 1]; // allocate memory
	strcpy(this->album, album); // copy info to memory
}

// !  GET VARIABLES

// title
void Song::getTitle(char * title) const
{
	//title = new char[strlen(this->title) +1];
	strcpy(title, this->title);
}

// artist
void Song::getArtist(char * artist) const
{
	//artist = new char[strlen(this->artist) +1];
	strcpy(artist, this->artist);
}

// duration
void Song::getDuration(float * duration) const
{
	duration = this->duration;
}

// album
void Song::getAlbum(char * album) const
{
	//album = new char[strlen(this->album) +1];
	strcpy(album, this->album);
}

/*
! *****************    MEMBER FUNCTIONS    ******************************
*/

/*
	 function to get new Song from user
*/
void Song::getSong()
{
	char ttl[MAX_CHAR];
	char art[MAX_CHAR];
	char alb[MAX_CHAR];
	float dur;

	cout << "Please enter song title: ";
	getString(ttl, MAX_CHAR);  // read to temp str
	setTitle(ttl);  // copy value to ptr
	cout << "Please enter song artist: ";
	getString(art, MAX_CHAR);
	setArtist(art);  // copy value to ptr
	cout << "Please enter song duration: ";
	cin >> dur;
	setDuration(dur);   // copy val to ptr
	cout << "Please enter song album: ";
	getString(alb, MAX_CHAR);
	setAlbum(alb);  // copy value to ptr
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
	cout << "--------------------------------------------" << endl;
	cout << endl;
}

/*
						TODO: Update functions below...

	! ********************** OPERATOR OVERLOADS *********************************
*/

// Song & Song::operator = (Song &&)
// {

// } // move assignment

// int & Song::operator [] (std::size_t)
// {

// } // reference subscript

// const int & Song::operator [] (std::size_t) const
// {

// } // value subscript

// std::ostream & operator << (std::ostream &, const Song &)
// {

// } // stream insertion

// std::istream & operator >> (std::istream &, Song &)
// {

// } // stream extraction

// bool operator == (const Song &, const Song &)
// {

// } // equal to

// bool operator != (const Song &, const Song &)
// {

// }	// not equal to

// bool operator <  (const Song &, const Song &)
// {

// }  // Less than

// bool operator <= (const Song &, const Song &)
// {

// }  // Less than or equal

// bool operator >= (const Song &, const Song &)
// {

// }  // Greater than or equal

// bool operator >  (const Song &, const Song &)
// {

// }  // Greater than