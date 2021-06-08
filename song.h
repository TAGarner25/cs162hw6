// Trevor Garner
// CS 162 HW6
// class header: Song

#ifndef SONG_H
#define SONG_H

#include "utils.h"	// gives extra functionality      

// ! check on
// * completed
// ? not sure what to do... look up
// TODO: items needing completion
// normal

/*
	TODO: update stream operator definitions
*/
class Song
{
public:
    //* ctors & dtor
	Song();   															// default constructor
	Song(const char title[], const char artist[], float duration, const char album[]);
	Song(const Song& copySong);  										// copy constructor
	~Song();  															// destructor
	
	//* assignments
	Song & operator = (const Song & copySong);							// copy assignment
	Song & operator = (Song &&); 										// move assignment
	
	// * subscript - not needed
	// int & operator [] (std::size_t); 									// reference subscript
	// const int & operator [] (std::size_t) const; 						// value subscript
	
	// ! stream operators
	friend std::ostream & operator << (std::ostream & output, const Song & aSong) 	// ? stream insertion
	{
		output << "Title: " << aSong.title << "Artist: " <<  aSong.artist << "Duration: " << *aSong.duration 
			<< "Album: " << aSong.album;
		return output;
	}
	friend std::istream & operator >> (std::istream & input, Song & aSong) 			// ? stream extraction
	{
		input >> aSong.title >> aSong.artist >> *aSong.duration >> aSong.album;
		return input;
	}

	//* functions
	void print(int index) const; 										// * print index in song list
	void getSong();
	 
	//* mutators
	void setTitle(const char * title);	
	void setArtist(const char * artist);
	void setDuration(float duration);
	void setAlbum(const char * album);

	// * accessors;
	char * getTitle() const {return title;}
	char * getArtist() const {return artist;}
	float * getDuration() const {return duration;}
	char * getAlbum() const {return album;}

private:
	
	//* declare pointers 
	char * title = nullptr;
	char * artist = nullptr;
	float * duration = nullptr;
	char * album = nullptr;

	//* init funct
	void init(const char title[], const char artist[], float duration, const char album[]);

};

//* Relational operators
// source: textbook
bool operator == (const Song &, const Song &);	// equal to
bool operator <  (const Song &, const Song &);  // Less than
bool operator != (const Song & lhSong, const Song & rhSong) {return !(lhSong == rhSong);}	// not equal to 
bool operator <= (const Song & lhSong, const Song & rhSong) {return !(lhSong > rhSong);}	// Less than or equal
bool operator >= (const Song & lhSong, const Song & rhSong) {return !(lhSong < rhSong);}  	// Greater than or equal
bool operator >  (const Song & lhSong, const Song & rhSong) {return (rhSong < lhSong);}  	// Greater than

#endif
