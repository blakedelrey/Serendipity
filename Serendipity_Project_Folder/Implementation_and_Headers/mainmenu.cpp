// ----------------------------------------------------------------------------
// File Name: mainmenu.cpp                                                    -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: January 16th, 2019                                          -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To review the material we learned in CS1A and call upon functions -
//          to create a graphical menu that the user can input selections in. -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Call menu creating function from header file.					  -
//	Step 2: Store user menu choice in a variable.							  -
//	Step 3: Use switch statement to direct the user to a new menu in the 	  -
//			console based on their input.									  -
//  Step 4: When the user selects 4 save DB and exit the program.			  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// - MAIN_MENU_TITLE      string                  "Serendipity Booksellers"   -
// - WINDOW_WIDTH         int					  90                          -
// - MAIN_MENU_ARRAY_SIZE int					  4                           -
// - DBSIZE				  int					  20						  -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// - mainMenuOptionsArray string				  "Cashier Module", "Inventory-
// -											   Database Module", "Report  -
// - 											   Module", "Exit"            -
// - userSelection		  int					  Input from user             -
// - databaseFiller		  bookType*				  fills database with books   -
// - tempTitle			  string				  Holds database titles		  -
// - tempISBN			  string				  database book isbn		  -
// - tempAuthor			  string				  database book author		  -
// - tempPub			  string				  database book string		  -
// - tempDateAdded		  string				  database date added		  -
// - tempQtyOnHand		  int					  database qty on hand		  -
// - tempWholesale		  double				  database book wholesale val -
// - tempRetail			  double				  database book retail value  -
// - fout				  ofstream				  output stream				  -
// - fin				  ifstream				  input stream				  -
// - mainBookList		  ULL					  Holds all books in program  -
// - bookIt				  linkedListIterator	  Iterator for mainbookList	  -
// - outputLooper		  int					  Loops through db and outputs-
// ----------------------------------------------------------------------------



#include <string>
#include <iostream>
#include <iomanip>
#include "Prototypes.h"
#include "Functions.h"
#include <windows.h>
#include <fstream>
#include "cashier.h"
#include "bookinfo.h"
#include "invmenu.h"
#include "reports.h"
#include "globals.h"
#include "bookType.h"
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"



using namespace std;





//name: main
//purpose: Runs the main program
//arguments passed: NA
int main()
{

	//Constant declarations

	const string MAIN_MENU_TITLE = "Serendipity Booksellers";
	const int    WINDOW_WIDTH = 90;
	const int    MAIN_MENU_ARRAY_SIZE = 4;

	//Variable Declarations
	string mainMenuOptionsArray[MAIN_MENU_ARRAY_SIZE] =
	{"Cashier Module", "Inventory Database Module", "Report Module", "Exit"};   /* IN & CALC - Used to store menu options in gui
																							   for the user to pick from
																				*/

	int userSelection;															/*IN & CALC - Used to store user's menu
																							  selection that redirects
																							  to another page in the program
																				*/



	bookType *databaseFiller;
	string tempTitle;
	string tempISBN;
	string tempAuthor;
	string tempPub;
	string tempDateAdded;
	int tempQtyOnHand;
	double tempWholesale;
	double tempRetail;

	ofstream fout;
	ifstream fin;


	//variables to be passed

	//Creates Linked Lists
	unorderedLinkedList<bookType> mainBookList;
	linkedListIterator<bookType> bookIt;
	int outputLooper;



	//start main code


	fin.open("database.txt");
	while(!fin.eof() && !fin.fail())
	{
		getline(fin, tempTitle);
		getline(fin, tempISBN);
		getline(fin, tempAuthor);
		getline(fin, tempPub);
		getline(fin, tempDateAdded);
		fin >> tempQtyOnHand >> tempWholesale >> tempRetail;
		fin.ignore(10000, '\n');
		databaseFiller = new bookType(tempTitle, tempISBN, tempAuthor, tempPub, tempDateAdded, tempQtyOnHand, tempWholesale, tempRetail);
		mainBookList.insertLast(*databaseFiller);
		delete databaseFiller;

	}
	fin.close();

	system("cls");

	do
	{

		//creates main menu graphics
		userSelection = GenerateCenteredMenu('-', WINDOW_WIDTH, MAIN_MENU_TITLE,
											 " ", mainMenuOptionsArray,
											 MAIN_MENU_ARRAY_SIZE);



		//Redirects the user to a new page in the program
		switch (userSelection)
		{
			case 1 : cashier(mainBookList);
					 break;
			case 2 : invMenu(mainBookList);
					 break;
			case 3 : reports(mainBookList);
					 break;
			case 4 :
					 bookIt = mainBookList.begin();

					 fout.open("database.txt", ofstream::out | ofstream::trunc);
					 for (outputLooper = 0; outputLooper < mainBookList.length(); outputLooper++)
					 {
						 fout << (*bookIt).getTitle() << endl;
						 fout << (*bookIt).getISBN() << endl;
						 fout << (*bookIt).getAuthor() << endl;
						 fout << (*bookIt).getPub() << endl;
						 fout << (*bookIt).getDateAdded() << endl;
						 fout << (*bookIt).getQtyOnHand() << endl;
						 fout << (*bookIt).getWholesale() << endl;
						 fout << (*bookIt).getRetail();
						 if (outputLooper != mainBookList.length() - 1)
						 {
							 fout << endl;
						 }
						 ++bookIt;
					 }
						 fout.close();

					 break;
			default: cout << "INVALID INPUT HIT ENTER TO TRY AGAIN";

		}

	} while (userSelection != 4);

	return 0;
}

