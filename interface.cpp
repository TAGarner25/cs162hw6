// Trevor Garner
// CS 162 HW5
// Function definitions to run the program
// sources:
//		-> No code was used, but design idea was from:
//			-> ~lliang/cs162/lectures/module5

#include "interface.h"
#include "utils.h"

/*
	function to start the program
*/
void start()  // start prog
{
     char fileName[] = "songs.txt";
     SongList library;
     int action;     

     // * step 1: load songs
     library.loadSongs(fileName);     
     // step 2: display menu -> choose what to do -> execute decision -> repeat until quit
     menu();
     action = readAction();     

     while (action != 5)
     {
          execute(action, library);
          menu();
          action = readAction();
     }
     
     // * step 4: on quit save songs and quit program
     library.saveSongs(fileName);

     cout << "Goodbye." << endl;
}
/*
	function to display the program menu (what the program can do)
*/
void menu()   // display menu
{
     // prompt
	cout << "Welcome to your music collection manager!" << endl;
     cout << endl;
	cout << "You can perform the following operations:" << endl;
     cout << "        1. View song library" << endl;
     cout << "        2. Add song to library" << endl;
     cout << "        3. Remove song from library" << endl;
     cout << "        4. Search library" << endl;
     cout << "        5. Quit program" << endl;
	cout << endl;

}

/*
	function to read user's decision from menu choices
*/
int readAction()    // get user choice
{
     int action;
     // prompt
     cout << "Which operation would you like to perform (choose number)? ";
     // read response
     action = getInt();
	cout << endl;
     return action;
}
/*
	function to execute user's choice from program menu
	paramters:
		int action: which menu choice to execute
		SongList library: the object containing the song list
*/
void execute(int action, SongList& library)    // execute user choice
{
     int cmd = action;
 
     switch (cmd)
     {
          case 1:   // * view song list
               library.printSongs();
               break;
          case 2:   // * add song to list
               char addAgain;
               addToList(library);
               addAgain = repeatAction();
               while (addAgain != 'n')
               {
                    addToList(library);
                    addAgain = repeatAction();
               }
               break;
          case 3:   // * remove song from list
               char removeAgain;
               removeFromList(library);
               removeAgain = repeatAction();
               while (removeAgain != 'n')
               {
                    removeFromList(library);
                    removeAgain = repeatAction();
               }
               break;
          case 4:   // * search the song list for an artist or album
               char searchAgain;
               searchList(library);
               searchAgain = repeatAction();
               while (searchAgain != 'n')
               {
                    searchList(library);
                    searchAgain = repeatAction();
               }
               break;
          case 5:   // quit the program
               break;
          default:	// err msg
               cout << "Please choose a number between 1 and 5!" << endl;
               break;
     }
}

/*
	function to ask user if they'd like to repeat the same action again
*/
char repeatAction()
{
     char response;
     // prompt
     cout << "Would you like to repeat this action? [y/n] ";
     response = getChar();
	cout << endl;     

     while ((response != 'y') && (response != 'n'))
     {
          cout << "Please enter 'y' for yes and 'n' for no." << endl;
          cout << "Would you like to repeat this action? ";
          response = getChar();
		cout << endl;
     }

     return response;
}
/*
	function to add a new song the song list (from user input)
	parameters: SongList object ('library')
*/
void addToList(SongList& library)		// get a new song from user and add to song list
{
     Song newSong;

     newSong.getSong(); // read new song from user

     if (library.addSongs(newSong) == true)  // compare new song to existing songs
     {    // if true then song added successfully
          cout << "Song added successfully." << endl;
     }
     else	// if false, then song already exists -> dont add to list
     {
          cout << "Sorry that song already exists in your list..." << endl;
          cout << "Maybe try another search?" << endl;
		cout << endl;
     }
}
/*
	function to remove song from the song list
	parameters: SongList object ('library')
*/
void removeFromList(SongList& library)
{
     library.printSongs();	// print songs for user to determine which to remove
     cout << "Please choose the index number of the song you want to remove: ";	// prompt
     int removeIdx = getInt();	// position of song to remove
     library.removeSongs(removeIdx);	// remove
}
/*
	function to search song list for a given artist or album
	paramters: SongList object ('library')
*/
void searchList(SongList& library)	
{
     char name[MAX_CHAR];
     int searchBy;
     Song existingSong;

          // prompt for user to input search type and name
     cout << "What would you like to search for?" << endl;
     cout << "      1. Search by artist" << endl;
     cout << "      2. Search by album" << endl;
     cout << "Input choice (number): ";
     searchBy = getInt();
	cout << endl;

     cout << "What is the name you would like to search for? ";
     getString(name, MAX_CHAR);
     cout << endl;
     // search list by name and type of search
     library.searchSongs(name, searchBy);
}

