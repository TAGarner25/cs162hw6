// Trevor Garner
// CS 162 HW6
// Function definitions for SongList class

#include "songlist.h"
#include <fstream>

// ! IMPORTANT:
// * HIGHLIGHT:
// ? QUESTION:
// TODO:
// wtf
// normal

/*
     TODO: update for using pointers
     TODO: New constructor for pointers(?)
     TODO: 
*/

               /*   CONSTRUCTORS & DECONSTRUCTOR  */

// default constructor
SongList::SongList()
{
    SIZE = 0;
    list = nullptr;	// declare pointer array to list

}

// TODO: needs to perform a *deep* copy of 'aSong' data to new Song object in list
SongList::SongList(const Song& aSong)
{
    // TODO: definition goes here

}
// destructor
SongList::~SongList() 
{
     delete [] list;
     list = nullptr;
}

/******************          FUNCTIONS          ******************************/

                    /*   PROGRAM FUNCTIONS   */

/*
     function to load song collection from file
     receives fileName on call
     creates Song obj called 'thisSong' and adds to Song list
*/
void SongList::loadSongs(const char fileName[])
{
    ifstream inFile;         // ifstream operator
	Song aSong;
	
    // temp values to read into pointers
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    float duration;
    char album[MAX_CHAR];

    // open file
    inFile.open(fileName);
     
    // error msg if not open
    if (!inFile)
    {
         cerr << "The file does not exist...";
         exit(1);
    }

    // read first item
    inFile.get(title, MAX_CHAR, ';');

    // read info until end of file
    while (!inFile.eof())
    {
        inFile.get();  // discard ';'
        inFile.get(artist, MAX_CHAR, ';');
        inFile.get();  // discard ';'
        inFile >> duration;
        inFile.get();  // discard ';'
        inFile.get(album, MAX_CHAR, '\n');
        inFile.ignore(MAX_CHAR, '\n');     // discard new line
        // set info to thisSong obj
        
        aSong.setTitle(title);
        aSong.setArtist(artist);
        aSong.setDuration(duration);
        aSong.setAlbum(album);

        // add newSong to songlist list
        addSongs(aSong);
        // repeat
        inFile.get(title, MAX_CHAR, ';');
    }
    // close inFile
    inFile.close();
}

/*
     function to save song list to file
     receives file name on call
*/
void SongList::saveSongs(const char fileName[]) const
{
    ofstream outFile;
    char title[MAX_CHAR];
    char artist[MAX_CHAR];
    float * duration;
    char album[MAX_CHAR];

    // open save file
    outFile.open(fileName);
    
    // error msg if cannot open file
    if (!outFile)
    {
        cerr << "Save location not found..." << endl;
		exit(1);
    }

    // loop through list, get info, then print to file
    for (auto idx = 0; idx < SIZE; idx++)
    {
        // get info for Song obj
		list[idx].getTitle(title);
        list[idx].getDuration(duration);
        list[idx].getArtist(artist);
        list[idx].getAlbum(album);

        

        // write to file
        outFile   << title << ';'
                  << artist << ';'
                  << duration << ';'
                  << album << endl;
    }
 
     // close outfile
    outFile.close();
}

                    /*   USER INTERFACE FUNCTIONS */

/*
     function to add song to song list
     parameters
          Song newSong -> the newSong object the user has provided
*/
bool SongList::addSongs(const Song& newSong)
{     
    bool found;
	// ptrs will point to ptrs... need to use ** to access values
	// int len = 0;
    char newTitle[MAX_CHAR];
    char newArtist[MAX_CHAR];
    char existingTitle[MAX_CHAR];
    char existingArtist[MAX_CHAR];
      
    //get newSong's information
    newSong.getTitle(newTitle);
    newSong.getArtist(newArtist);
    
	for (int idx = 0; idx < SIZE; idx++)
	{  
        list[idx].getTitle(existingTitle);
        list[idx].getArtist(existingArtist);

        if ((strcmp(existingTitle, newTitle) == 0) && (strcmp(existingArtist, newArtist) == 0))
		{
			found = true;
		}
	}
     
    if (found == false) // if not already in list
    {
    	list[SIZE] = newSong;    // add newSong to list
        SIZE++;
        return true;
    }
    else
    {
    	return false;	// item already exists, do not add to list
    }
}         

/*
     function to remove song
     parameter
          index position of song to remove (provided by user)
*/
void SongList::removeSongs(int removeIdx)
{
    // old code
    // loop through list and remove desired song
    for (int idx = removeIdx; idx < SIZE; idx++)
    {
        list[idx] = list[idx + 1];     // delete song
    }

    SIZE--;   // decrease size by 1

    // new code
    // delete pointer to specific item
	// will delete contents of dereferenced memory
    // pointer needs to be reassigned (use loop above)
    // new empty pointer needs to be set to nullptr

}

/*
     function to print all songs in list
*/
void SongList::printSongs() const
{
    // loop through list and have obj print contents
    for (auto idx = 0; idx < SIZE; idx++)
    {
        int pos = idx;			// song index
        list[idx].print(pos);	// print song
    }
}

/*
    wtf
    TODO: FIX ME!
    function to search list of songs
    parameters
        const char name[] -> the search string provided by user
		int search by -> the type of search user wants (1 = artist, 2 = album)
*/
void SongList::searchSongs(const char name[], int searchBy) const
{
    bool found = false;						// flag to determine if item was found
     
    char listArtist[MAX_CHAR];                  	// search item from list
    char listAlbum[MAX_CHAR];                   	// search item from list 

    int index;							// used to print index position of song in list
     

    switch (searchBy)
    {
        case 1:   // artist
		// loop through list and compare name to artist
            for (int idx = 0; idx < SIZE; idx++)
            {

                //strcpy(listArtist, artist);
                index = idx;

                if (strcmp(listArtist, name) == 0)     // compare list artist to search name
                {	// if are same print results
                    found = true;
                         list[idx].print(index);
                }
			}
               if (found == false) // if not found, display err msg
               {
                    cout << "Sorry, can't find what you're looking for..." << endl;
                    cout << "Maybe try another search." << endl;
				break;
               }
          case 2:   // album
			// loop through list and compare name to album
               for (int idx = 0; idx < SIZE; idx++)
               {

                    //strcpy(listAlbum, album);
                    index = idx;
                    if (strcmp(listAlbum, name) == 0)      // compare list album to search name
                    {	// if are the same, print results
                        found = true;
                        list[idx].print(index);
                    }
			}
               if (found == false) // if not found, display err msg
               {
                    cout << "Sorry, can't find what you're looking for..." << endl;
                    cout << "Maybe try another search." << endl;
				break;
               }
     }//end switch
}
