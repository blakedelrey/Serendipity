// ----------------------------------------------------------------------------
// File Name: lookupbook.cpp                                                  -
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
//	Step 1: Allow user to enter a book or isbn	to be searched for			  -
//  Step 2: Convert user search to upper									  -
//  Step 3: Search through array of structs for the usersearch				  -
//  Step 4: Return the location of the searched book or -1 if not found	      -
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
#include "bookinfo.h"
#include "globals.h"
#include "lookupbook.h"
#include "string"
#include "unorderedLinkedList.h"

using namespace std;



//name: lookUpBook
//purpose: Allows the user to search for and get information for a book in the database
//arguments passed: bookCount, bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail
searchReturnType lookUpBook(unorderedLinkedList<bookType> bookList)
{
	string userSearch;
	//string upperBookTitleArray[DBSIZE];
	int searchLooper;
	int titleSearch;
	int titleHolder;
	int isbnSearch;
	string newSearch;
	char viewPrompt;
	int newStart;
	int lastTitle;
	int bookCounter;
	bool enable;
	//char name[10] = "John";
	char upperWord[50];
	char upperWordInArray[50];
	bool searchContinuer;
	int returnLocation;
	bool bookFound;

	isbnSearch = 0;
	enable = true;
	searchContinuer = true;
	bookCounter = 0;
	returnLocation = -1;
	bookFound = false;
	viewPrompt = 'N';
	newStart = 0;


	nodeType<bookType> *current;
	bool found = false;
	bookType *newBook;
	unorderedLinkedList<bookType> tempBookList;
	nodeType<bookType> *head;
	linkedListIterator<bookType> bookIt;
	bookType *bookHolder;
	searchReturnType searchReturn;



	int searchCount;
	searchCount = 0;



	for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
	{
		newBook = new bookType(*bookIt, 3);
		tempBookList.insertLast(*newBook);
	}




//	for (int wordCounter = 0; wordCounter < bookType::getBookCount(); wordCounter++)
//	{
//		strcpy(upperWordInArray, bookData[wordCounter]->getTitle().c_str());
//		for (int letterCounter = 0; letterCounter < bookData[wordCounter]->getTitle().length(); letterCounter++)
//		{
//			upperWordInArray[letterCounter] = toupper(upperWordInArray[letterCounter]);
//		}
//		upperBookTitleArray[wordCounter] = upperWordInArray;
//	}


	cout << " >>> BOOK LOOK UP <<<" << endl;
	cout << "  Search: >";
	getline(cin, userSearch);
	searchReturn.setSearchTerm(userSearch);


	system("cls");

	strcpy(upperWord, userSearch.c_str());
	for (int letterCounter = 0; letterCounter < userSearch.length(); letterCounter++)
	{
		upperWord[letterCounter] = toupper(upperWord[letterCounter]);
	}
	newSearch = upperWord;
	newBook = new bookType;
	newBook->setTitle(newSearch);
	newBook->setSortType(3);





	for (bookIt = tempBookList.begin(); bookIt != tempBookList.end();
            ++bookIt)
	{
		bookHolder = new bookType(*bookIt, 3);
		//cin.ignore(10000, '\n');


		if (!found)
		{
			//cin.ignore(10000, '\n');
			//search the list
			if (*bookHolder == *newBook)
			{
				//searchItem is found

				//cin.ignore(10000, '\n');
				//bookHolder = new bookType(*bookIt, 3);
				cout << "RESULT>: " << bookHolder->getTitle() << endl;

				cout << "View this book?: ";


				//Asks user if they would like to view this book if the title was found
				do
				{

					cin >> viewPrompt;
					cin.clear();
					cin.ignore(10000, '\n');


					if (toupper(viewPrompt) == 'Y')
					{
						system("cls");
						bookHolder->bookInfo();
						found = true;
						returnLocation = searchCount;
					}
					else if (toupper(viewPrompt) == 'N')
					{
						found = false;
						searchCount++;

						system("cls");

					}
					else
					{
						cout << "Invalid option please respond with yes or no: ";
					}

				}while(toupper(viewPrompt) != 'Y' && toupper(viewPrompt) != 'N' );
			}
			else
			{
				searchCount++;
			}


		}

	}


	if (!found)
	{
		cout << "**BOOK COULD NOT BE FOUND**" << endl << endl
			 << "<Press ENTER to continue>";
		cin.ignore(10000, '\n');
	}


//	do
//	{
//
//		for (searchLooper = newStart; searchLooper < bookType::getBookCount(); searchLooper++)
//		{
//			if ((titleSearch == string::npos) || lastTitle == titleSearch || enable)
//			{
//				enable = false;
//				titleSearch = upperBookTitleArray[searchLooper].find(newSearch);
//				titleHolder = searchLooper;
//
//			}
//
//			if (bookData[searchLooper]->getISBN() == newSearch)
//			{
//				isbnSearch = searchLooper;
//			}
//
//		}
//
//
//
//
//
//
//		if (titleSearch != string::npos && lastTitle != titleSearch)
//		{
//
//				//For formatting purposes
//				if (bookCounter >= 0)
//				{
//					cout << " >>> BOOK LOOK UP <<<" << endl;
//					cout << "  Search: >" << userSearch << endl;
//				}
//
//
//				//Displays result of search if title was found
//				cout << "RESULT>: " << bookData[titleHolder]->getTitle() << endl;
//				cout << "View this book?: ";
//
//					//Asks user if they would like to view this book if the title was found
//					do
//					{
//						cin >> viewPrompt;
//						cin.clear();
//						cin.ignore(10000, '\n');
//
//						if (toupper(viewPrompt) == 'Y')
//						{
//							system("cls");
//							bookData[titleHolder]->bookInfo();
//							bookFound = true;
//							returnLocation = titleHolder;
//						}
//						else if (toupper(viewPrompt) == 'N')
//						{
//							newStart = titleHolder + 1;
//							lastTitle = titleSearch;
//							bookCounter++;
//							system("cls");
//
//						}
//						else
//						{
//							cout << "Invalid option please respond with yes or no: ";
//						}
//
//					}while(toupper(viewPrompt) != 'Y' && toupper(viewPrompt) != 'N' );
//		}
//
//
//		//Checks to see if isbn is found
//		else if (newSearch == bookData[isbnSearch]->getISBN() && searchContinuer)
//		{
//
//			if (bookCounter >= 0)
//			{
//				cout << " >>> BOOK LOOK UP <<<" << endl;
//				cout << "  Search: >" << userSearch << endl;
//			}
//
//				cout << "RESULT>: " << bookData[isbnSearch]->getTitle() << endl;
//				cout << "View this book?: ";
//
//					//If isbn is found checks if the user would like to view this book
//					do
//					{
//						cin >> viewPrompt;
//						cin.clear();
//						cin.ignore(10000, '\n');
//
//						if (toupper(viewPrompt) == 'Y')
//						{
//							system("cls");
//							bookData[titleHolder]->bookInfo();
//							bookFound = true;
//							returnLocation = isbnSearch;
//						}
//						else if (toupper(viewPrompt) == 'N')
//						{
//							searchContinuer = false;
//							newStart = isbnSearch + 1;
//							lastTitle = isbnSearch;
//							bookCounter++;
//							system("cls");
//						}
//						else
//						{
//							cout << "Invalid option please respond with yes or no: ";
//						}
//
//					}while(toupper(viewPrompt) != 'Y' && toupper(viewPrompt) != 'N' );
//		}
//		else
//		{
//			bookCounter++;
//		}
//		if(!bookFound && bookCounter == bookType::getBookCount())
//		{
//			cout << "Book could not be found - Hit enter to continue.";
//			cin.ignore(10000,'\n');
//			returnLocation = -1;
//		}
//	}while(toupper(viewPrompt) == 'N' && bookCounter < bookType::getBookCount());

	searchReturn.setReturnLocation(returnLocation);
	return searchReturn;







}
