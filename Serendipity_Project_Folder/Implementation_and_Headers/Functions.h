// ----------------------------------------------------------------------------
// File Name: Functions.h                                                     -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: January 16th, 2019                                          -
// Date of Last Modification: JApril 16th, 2019                              -
// ----------------------------------------------------------------------------
// Purpose: To review the material we learned in CS1A and create a function   -
//			that will create a menu displaying different redirection options  -
//			and read in a user input option of where they would like to be    -
//			redirected.	This will be done using cout statements and modifiers -
//			as well as for loops and other selection/repitition statements.   -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Create upper border using a for loop that loops the length of the -
//			window.                                                           -
//	Step 2: Use cout statements to display the menu title and subtitle.       -
//	Step 3: Use for loop to generate a centered numbered list of all the      -
//  		options in the menu array being read into the function.			  -
//	Step 4: Use cout to prompt the user for a choice on which menu they'd like-
//			to go to and read it in using cin.								  -
//	Step 5: Use cin.clear() and cin.ignore() to error check for user input.   -
//	Step 6: Use do while loop to allow user to try again if they input		  -
//			something invalid.												  -
//	Step 6: Return the user's choice.										  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                 	 DATA TYPE               INITIAL VALUE            -
// - -----------          	 -------------           ------------------       -
// - menuOptionsCounter	  	 int					 1					      -
// - borderCounter		  	 int					 1                        -
// - titleCenteringBuffer 	 double				  	 (borderWidth +           -
// - 											  	  menuTitle.length()) / 2 -
// - subtitleCenteringBuffer double					 (borderWidth + 		  -
// -                                                 menuSubtitle.length())/ 2-
// - userChoice				 int					 Input by user			  -
// ----------------------------------------------------------------------------
#ifndef Header_h
#define Header_h

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <windows.h>
#include "prototypes.h"

using namespace std;



int GenerateCenteredMenu(char borderSymbol, int borderWidth, string menuTitle,
					      string menuSubtitle, string menuOptionsArray[],
						  int arraySize)
{
	int menuOptionsCounter;
	int borderCounter;
	double titleCenteringBuffer;
	double subtitleCenteringBuffer;
	int userChoice;

	//do
	//{
		//creates top border
		for (borderCounter = 1; borderCounter <= borderWidth; borderCounter++)
		{
			cout << borderSymbol;
		}

		//creates top double space border
		cout << endl << borderSymbol << setw(borderWidth - 1) << borderSymbol
			 << endl;

		//creates centered title of menu
		titleCenteringBuffer = (borderWidth + menuTitle.length()) / 2;

		cout << borderSymbol << setw(titleCenteringBuffer) << menuTitle
			 << setw(borderWidth - titleCenteringBuffer - 1) << borderSymbol
			 << endl;

		if (menuSubtitle != " ")
		{
			subtitleCenteringBuffer = (borderWidth + menuSubtitle.length()) / 2;

			cout << borderSymbol << setw(subtitleCenteringBuffer)
				 << menuSubtitle << setw(borderWidth
										 - subtitleCenteringBuffer - 1)
				 << borderSymbol << endl;
		}

		// creates second double space border
		cout << borderSymbol << setw(borderWidth - 1) << borderSymbol
			 << endl;

		//creates  centered list of menu options
		for (menuOptionsCounter = 1; menuOptionsCounter <= arraySize;
			 menuOptionsCounter++)
		{
			cout << borderSymbol 	   << setw(titleCenteringBuffer
											   - menuTitle.length())
				 << menuOptionsCounter << ". "
				 << menuOptionsArray[menuOptionsCounter - 1];

			cout << setw(titleCenteringBuffer
						- menuOptionsArray[menuOptionsCounter - 1].length() - 2)
				 << borderSymbol;
			cout << endl;
		}





		//bottom border

		cout << borderSymbol << setw(borderWidth - 1) << borderSymbol << endl;

		for (borderCounter = 1; borderCounter <= borderWidth; borderCounter++)
		{
			cout << borderSymbol;
		}
		cout << endl;
		//End menu graphics


		//User Prompt
		cout << borderSymbol << " Enter Your Choice: ";
		while (!(cin >> userChoice) || (userChoice < 1 || userChoice > arraySize))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << borderSymbol  << " Invalid input - Please enter a number between 1 and " << arraySize << "." << endl;
			cout << borderSymbol <<" Enter Your Choice: ";
		}
		cin.ignore(10000, '\n');
		/*cin  >> userChoice;
		cin.clear();
		cin.ignore(10000, '\n');

		if (userChoice < 1 || userChoice > arraySize)
			{
				system("CLS");

				cout << "Invalid input hit enter to try again ";
				cin.clear();
				cin.ignore(10000, '\n');

				system("CLS");
			}




	} while (userChoice < 1 || userChoice > arraySize);*/
	system("CLS");
	return userChoice;
}


#endif /* Header_h */
