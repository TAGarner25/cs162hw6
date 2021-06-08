// Trevor Garner
// CS 162 HW6
// class header: Song

#ifndef SONG_H
#define SONG_H

#include "utils.h"	// gives extra functionality      

// ! IMPORTANT:
// * HIGHLIGHT:
// ? QUESTION:
// TODO:
// wtf: what was I thinking?...
// normal

/*
	TODO: update relational operators definitions
*/
class Song
{
public:
    // ctors
	Song();   // default constructor
	Song(const char * title, const char * artist, float * duration, const char * album);
	
	// big three
	~Song();  // destructor
    Song(const Song& copySong);  // copy constructor	
	Song & operator = (const Song & copySong);	// copy assignment
	
	// functions
	void print(int index) const; // ! print index in song list
	void getSong();
	 
	// setters
	void setTitle(const char * title);
	void setArtist(const char * artist);
	void setDuration(float duration);
	void setAlbum(const char * album);

	// getters
	void getTitle(char * title) const;
	void getArtist(char * artist) const;
	void getDuration(float * duration) const;
	void getAlbum(char * album) const;

	// operator overloads
	// Song & operator = (Song &&); 										// move assignment
	// int & operator [] (std::size_t); 									// reference subscript
	// const int & operator [] (std::size_t) const; 						// value subscript
	// friend std::ostream & operator << (std::ostream &, const Song &); 	// stream insertion
	// friend std::istream & operator >> (std::istream &, Song &); 		// stream extraction

private:
	// declare pointers 
	char * title = nullptr;
	char * artist = nullptr;
	float * duration = nullptr;
	char * album = nullptr;

};

// TODO: Relational operators
// bool operator == (const Song &, const Song &);	// equal to

// ! NOT USED
// bool operator != (const Song &, const Song &);	// not equal to 
// bool operator <  (const Song &, const Song &);  // Less than
// bool operator <= (const Song &, const Song &);  // Less than or equal
// bool operator >= (const Song &, const Song &);  // Greater than or equal
// bool operator >  (const Song &, const Song &);  // Greater than

#endif
