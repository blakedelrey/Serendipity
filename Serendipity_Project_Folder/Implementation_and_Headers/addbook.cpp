// ----------------------------------------------------------------------------
// File Name: addbook.cpp                                                     -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To create the functions for looking up a book					  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Display menu for user to enter data on a book					  -
//  Step 2: Add functionality to the menu for each option 				      -
//	Step 3: Save books to DB when user hits 9 and kick out when user hits 10  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// - *refer to invmenu data dictionary* 									  -
// - 																		  -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// - *refer to invmenu data dictionary* 									  -
// ----------------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include "globals.h"
#include "addbook.h"
#include "bookType.h"

#include "bookType.h"

using namespace std;


//name: addBook
//purpose: Allows the user to add a book to the database
//arguments passed: bookCount, bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail
void addBook(unorderedLinkedList<bookType> &bookList)
{
    const string INVENTORY_MENU_TITLE = "Serendipity Booksellers";
    const string INVENTORY_MENU_SUBTITLE = "Inventory Database";
    const int    WINDOW_WIDTH = 120;
    const int    ADD_BOOK_ARRAY_SIZE = 10;

	int borderCounter;
	char borderSymbol;
	double titleCenteringBuffer;
	string menuTitle;
	int borderWidth;
	string menuSubtitle;
	double subtitleCenteringBuffer;
	int menuOptionsCounter;
	int arraySize = ADD_BOOK_ARRAY_SIZE;
	int userChoice;
	bool didSave;
	int tempBooks;
	string menuOptionsArray[arraySize] = {"Enter Book Title", "Enter ISBN", "Enter Author", "Enter Publisher",
								 "Enter Date Added (mm/dd/yyyy)", "Enter Quantity on Hand", "Enter Wholesale Cost",
								 "Enter Retail Price", "Save Book to Database", "Return to Inventory Menu"};

	string userTitle;
	string userIsbn;
	string userAuthor;
	string userPub;
	string userDateAdded;
	int userQty;
	double userWholesale;
	double userRetail;

	string tempTitle;
	string tempIsbn;
	string tempAuthor;
	string tempPub;
	string tempDateAdded;
	int tempQty;
	double tempWholesale;
	double tempRetail;

	bookType *newBook;


	tempBooks = bookList.length();

	ofstream fout;




	menuTitle = "SERENDIPITY BOOKSELLERS";
	menuSubtitle = "ADD BOOK";


	borderWidth = WINDOW_WIDTH;

	borderSymbol = '*';

		tempTitle = "Empty";
		tempIsbn = "Empty";
		tempAuthor = "Empty";
		tempPub = "Empty";
		tempDateAdded = "00/00/0000";
		tempQty = 0;
		tempWholesale = 0.00;
		tempRetail = 0.00;

		didSave = false;

		do
		{

			if (didSave == true)
			{
				tempTitle = "Empty";
				tempIsbn = "Empty";
				tempAuthor = "Empty";
				tempPub = "Empty";
				tempDateAdded = "00/00/0000";
				tempQty = 0;
				tempWholesale = 0.00;
				tempRetail = 0.00;
			}
			didSave = false;

			//creates graphics
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

					cout << borderSymbol << setw(subtitleCenteringBuffer) << " CURRENT BOOK COUNT: " << bookList.length()
										 << setw(borderWidth - subtitleCenteringBuffer - 1 - 9 + 1 - to_string(bookList.length()).length() + 8) << borderSymbol << endl;

					cout << borderSymbol << setw(borderWidth - 1) << borderSymbol
											 << endl;

					cout << borderSymbol  << setw(35 + 17) << "--PENDING VALUES" << setw(90-35 + 12) << borderSymbol << endl;

					cout << borderSymbol << setw(borderWidth - 1) << borderSymbol
																 << endl;

					//creates  centered list of menu options
					for (menuOptionsCounter = 1; menuOptionsCounter <= arraySize;
						 menuOptionsCounter++)
					{
						cout << borderSymbol 	   << " "
							 << menuOptionsCounter << ". "
							 << menuOptionsArray[menuOptionsCounter - 1];

						switch(menuOptionsCounter)
						{
							case 1: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" <<  tempTitle;
									break;
							case 2: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempIsbn;
									break;
							case 3: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempAuthor;
									break;
							case 4: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempPub;
									break;
							case 5: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempDateAdded;
									break;
							case 6: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempQty;
									break;
							case 7: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length() + 1) << "> --$" << fixed << setprecision(2) << tempWholesale;
									break;
							case 8: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length() + 1) << "> --$" << fixed << setprecision(2) << tempRetail;
						}


						switch(menuOptionsCounter)
						{
							case 1:  cout << setw(120 - menuOptionsArray[0].length() - 36 - tempTitle.length() + 11) << '*' << endl;
									 break;
							case 2:  cout << setw(120 - menuOptionsArray[1].length() - 36 - tempIsbn.length() + 5) << '*' << endl;
									 break;
							case 3:  cout << setw(120 - menuOptionsArray[2].length() - 36 - tempAuthor.length() + 7) << '*' << endl;
									 break;
							case 4:  cout << setw(120 - menuOptionsArray[3].length() - 36 - tempPub.length() + 10) << '*' << endl;
							 	 	 break;
							case 5:  cout << setw(120 - menuOptionsArray[4].length() - 36 - tempDateAdded.length() + 24) << '*' << endl;
							 	 	 break;
							case 6:  cout << setw(120 - menuOptionsArray[5].length() - 36 - to_string(tempQty).length() + 17) << '*' << endl;
							 	 	 break;
							case 7:  cout << setw(120 - menuOptionsArray[6].length() - 36 - 4 + 14  - to_string(tempWholesale).length() + 8) << '*' << endl;
							 	 	 break;
							case 8:  cout << setw(120 - menuOptionsArray[7].length() - 36 - 4 + 12 - to_string(tempRetail).length() + 8) << '*' << endl;
							 	 	 break;
							case 9:  cout << setw(120 - menuOptionsArray[8].length() - 5) << '*' << endl;
									 break;
							case 10: cout << setw(120 - menuOptionsArray[9].length() - 6) << '*' << endl;
									 break;
							default: cout << setw(120 - 36 - menuOptionsArray[menuOptionsCounter - 1].length() - 5) << '*'<< endl;
									 break;
						}

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

					//Prompts user to enter book information
					switch(userChoice)
					{
						case 1: cout << "Please enter the book title: ";
								getline(cin, userTitle);
								tempTitle = userTitle;
								break;

						case 2: cout << "Please enter the ISBN for this book: ";
								getline(cin, userIsbn);
								tempIsbn = userIsbn;
								break;

						case 3: cout << "Please enter the author's name for this book: ";
								getline(cin, userAuthor);
								tempAuthor = userAuthor;
								break;

						case 4: cout << "Please enter the publisher's name for this book: ";
								getline(cin, userPub);
								tempPub = userPub;
								break;

						case 5: cout << "Please enter date added: ";
								getline(cin, userDateAdded);
								tempDateAdded = userDateAdded;
								break;

						case 6: cout << "Please enter quantity on hand: ";
								while (!(cin >> userQty) || userQty < 0)
								{
									cin.clear();
									cin.ignore(1000, '\n');
									cout << borderSymbol  << " Invalid input - Please enter an integer greater than 0" << endl;
									cout << "Please enter quantity on hand: ";
								}
								cin.ignore(10000, '\n');
								tempQty = userQty;
								break;

						case 7: cout << "Please enter wholesale cost of this book: ";
								while (!(cin >> userWholesale) || userWholesale < 0)
								{
									cin.clear();
									cin.ignore(1000, '\n');
									cout << borderSymbol  << " Invalid input - Please enter an number greater than 0" << endl;
									cout << "Please enter wholesale cost of this book: ";
								}
								cin.ignore(10000, '\n');
								tempWholesale = userWholesale;
								break;

						case 8: cout << "Please enter the retail cost of this book: ";
								while (!(cin >> userRetail) || userRetail < 0)
								{
									cin.clear();
									cin.ignore(1000, '\n');
									cout << borderSymbol  << " Invalid input - Please enter a number greater than 0" << endl;
									cout << "Please enter the retail cost of this book: ";
								}
								cin.ignore(10000, '\n');
								tempRetail = userRetail;
								break;

						case 9: didSave = true;

								newBook = new bookType(tempTitle, tempIsbn, tempAuthor, tempPub, tempDateAdded, tempQty, tempWholesale, tempRetail);
								bookList.insertLast(*newBook);
								fout.open("database.txt", ofstream::out | ofstream::app);
								if (bookList.length() > 0)
								{
									fout << endl;
								}
								fout << tempTitle << endl;
								fout << tempIsbn << endl;
								fout << tempAuthor << endl;
								fout << tempPub << endl;
								fout << tempDateAdded << endl;
								fout << tempQty << endl;
								fout << tempWholesale << endl;
								fout << tempRetail;
								fout.close();
								bookType::incBookCount();
								break;

						case 10: break;
					}
					system("cls");
			}while(userChoice != 10);




		//Database is full module

	}
