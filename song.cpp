// Trevor Garner
// hw6 Song.cpp src
// contains definitions for Song class members

#include "song.h"

// ! check on
// * completed
// ? not sure what to do...
// TODO: items needing completion
// normal


// TODO: stream operator definitions

//* default constructor
Song::Song()
{
	// initialize default data members
	title = nullptr;
	artist = nullptr;
	duration = nullptr;
	album = nullptr;
}

//* constructor with pointers to all Song variables as parameters
Song::Song(const char title[], const char artist[], float duration, const char album[])
{
	// pass params to init function
	init(title, artist, duration, album);
}

//* init function
void Song::init(const char title[], const char artist[], float duration, const char album[])
{
	// allocate dynamic memory
	this->title = new char[strlen(title) + 1];
	this->artist = new char[strlen(artist) + 1];
	this->duration = new float(duration);   		// allocated and initialized to value
	this->album = new char[strlen(album) + 1];

	// copy params to allocated memory
	strcpy(this->title, title);        // title
	strcpy(this->artist, artist);      // artist
	strcpy(this->album, album);        // album
}

//* dtor
Song::~Song()
{
	delete [] this->title;
	delete [] this->artist;
	delete this->duration;
	delete [] this->album;
}

//* copy constructor - relies on copy assignment
Song::Song(const Song& aSong)
{
	// allocate memory
	this->title = nullptr;
	this->artist = nullptr;
	this->duration = nullptr;
	this->album = nullptr;

	// copy 
	*this = aSong;
}

/*
						TODO: Update functions below...

	! ********************** OPERATOR OVERLOADS *********************************
*/
//* copy assignment
Song & Song::operator = (const Song & aSong) 
{
	// self assignment check
	if (this == &aSong)
	{
		return * this;
	}

	// check ptrs
	delete [] title;
	delete [] artist;
	delete duration;
	delete [] album;

	// memory allocation
	this->title = new char[strlen(aSong.title) + 1];
	this->artist = new char[strlen(aSong.artist) + 1];
	this->duration = new float;
	this->album = new char[strlen(aSong.album) + 1];

	// copy 
	strcpy(this->title, aSong.title);
	strcpy(this->artist, aSong.artist);
	this->duration = aSong.duration;
	strcpy(this->album, aSong.album);

	return *this;
}

// move assignment
// Song & Song::operator = (Song && aSong){}

// *  reference subscript
// int & Song::operator [] (std::size_t index)
// {
// 	return aSong[index];
// } 
// // value subscript
// const int & Song::operator [] (std::size_t) const
// {
// 	// * DEFINITION GOES HERE
// } 

// ? stream insertion
std::ostream & operator << (std::ostream &, const Song &)
{
	// ! DEFINITION GOES HERE
}

// ? stream extraction
std::istream & operator >> (std::istream &, Song &)
{
	// ! DEFINITION GOES HERE
}

/*
!   *****************     SETTERS & GETTERS     ****************************
*/
// *   SET VARIABLES

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

// *  GET VARIABLES
// Can remove commented out code below, 
// functions were declared inline.

// // title
// char * Song::getTitle() const
// {
// 	return title;
// }
// // artist
// char * Song::getArtist() const
// {
// 	return artist;
// }
// // duration
// float * Song::getDuration() const
// {
// 	return duration;
// }
// // album
// char * Song::getAlbum() const
// {
// 	return album;
// }

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
	cout << "Title:     " << *title << endl;      // this-> title
	cout << "Artist:    " << *artist << endl;     // this-> artist
	cout << "Duration:  " << *duration << endl;   // this-> duration
	cout << "Album:     " << *album << endl;      // this-> album
	cout << "--------------------------------------------" << endl;
	cout << endl;
}

/*
*	******************** RELATIONAL OPERATORS *********************************
*/

// equal to
bool operator == (const Song & lhSong, const Song & rhSong)
{
	// returns true if song variables are the same for both objects
	return (*lhSong.getTitle() == *rhSong.getTitle() &&
			*lhSong.getArtist() == *rhSong.getArtist() &&
			*lhSong.getDuration() == *rhSong.getDuration() &&
			*lhSong.getAlbum() == *rhSong.getAlbum());
}

// Less than
// bool operator < (const Song & lhSong, const Song & rhSong)
// {
// 	bool address, title, artist, duration, album;
// 	if (&lhSong < &rhSong)	// compare addresses
// 		address = true;
// 	if (*lhSong.getTitle() < *rhSong.getTitle()) // compare dereferenced title val
// 		title = true;
// 	if (*lhSong.getArtist() < *rhSong.getArtist()) // compare dereferenced artist val
// 		artist = true;
// 	if (*lhSong.getDuration() < *rhSong.getDuration()) // compare dereferenced duration val
// 		duration = true;
// 	if (*lhSong.getAlbum() < *rhSong.getAlbum()) // compare dereferenced album val
// 		album = true;
// 	// if lhSong address is less than rhSong address (address == true)
// 	// OR
// 	// lhSong (title, artist, duration, and album) are less then rhSong (==true)
// 	// then : return true, 
// 	// otherwise : return false
// 	if ((address == true) || (title && artist && duration && album))
// 		return true;
// 	else
// 		return false;
// }  