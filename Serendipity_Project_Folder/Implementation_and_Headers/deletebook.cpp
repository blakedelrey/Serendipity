// ----------------------------------------------------------------------------
// File Name: deleteBook.cpp                                                  -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To create the function for deleting a book.						  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Call lookupBook													  -
//  Step 2: Display information on searched for book						  -
//  Step 3: If searched book is desired book to delete, delete the node		  -
//  Step 4: Prompt user for another book, if not save database and exit func  -
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
// - didSave			  bool					  Checks if data is deleted   -
// - bookIt				  LLI					  Iterates through bookList	  -
// - deletedBookIt		  LLI					  Iterates through deletedBook-
// - deletedBookHolder    *bookType				  Pointer to deletedBook	  -
// - searchMover		  int					  Loops through list forsearch-
// - deletedBooks		  ULL					  Holds deleted books		  -
// - bookHolder 		  *bookType				  holds books				  -
// - safetyBook			  *bookType				  Holds orig books JIC		  -
// - correctBook		  bool					  checks if book is found	  -
// - breakBool			  bool					  checks if func should break -
// - continueSearch		  bool					  checks if search should cont-
// - tempList			  ULL					  Holds books			      -
// - tempListIt			  LLI					  Iterates through tempList	  -
// - tempHolder			  *bookType				  Holds temp book			  -
// - upperWord			  char					  Makes searchTerm uppercase  -
// - newSearch			  string				  Holds uppercase searchterm  -
// - newBook			  *bookType				  Holds newBook				  -
// - found				  bool					  Checks if book is found	  -
// - searchCount		  int					  Saves location of book	  -
// - searchLoopStart	  int					  Updates search start loc	  -
// - newItStart			  LLI					  new iterator for search	  -
// - editPrompt			  char					  Prompts user for delete	  -
// - searchResult		  searchResultType		  Saves book search info	  -
// - fout				  Output stream			  Output stream				  -
// - outputLooper		  int					  Loops through output		  -
// ----------------------------------------------------------------------------



#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include "lookupbook.h"
#include "globals.h"
#include "deletebook.h"
#include "bookinfo.h"
#include "bookType.h"

using namespace std;


//name: deleteBook
//purpose: Allows the user to search for and delete a book's information in the database
//arguments passed: bookCount, bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail
void deleteBook(unorderedLinkedList<bookType> &bookList)
{

	int borderCounter;
	double titleBuffer;
	string userSearch;
	char deletePrompt;
	char borderSymbol;
	int borderWidth;
	double titleCenteringBuffer;
	double subtitleCenteringBuffer;
	string menuTitle;
	string menuSubtitle;
	int menuOptionsCounter;
	int arraySize = 9;
	string menuOptionsArray[arraySize] = {"Enter Book Title", "Enter ISBN", "Enter Author", "Enter Publisher",
			 "Enter Date Added (mm/dd/yyyy)", "Enter Quantity on Hand", "Enter Wholesale Cost",
			 "Enter Retail Price", "Return to Inventory Menu"};
	int userChoice;
	int bookLocation;
	int searchLooper;
	int newStart;
	bool enable;
	int isbnSearch;
	int titleSearch;
	int lastTitle;
	int titleHolder;
	int bookCounter;
	char viewPrompt;
	int deleteCounter;
	bool deleteBool;
	char deleteAnother;


	bool didSave;
	linkedListIterator<bookType> bookIt;
	linkedListIterator<bookType> deletedBookIt;
	bookType *deletedBookHolder;
	int searchMover;
	unorderedLinkedList<bookType> deletedBooks;
	bookType *bookHolder;
	bookType *safetyBook;
	bool correctBook;
	bool breakBool;
	bool continueSearch;

	didSave = false;

	unorderedLinkedList<bookType> tempList;
	bookType *tempHolder;
	linkedListIterator<bookType> tempIt;

	char upperWord[75];
	string newSearch;
	bookType *newBook;
	bool found;
	int searchCount;

	int searchLoopStart;

	linkedListIterator<bookType> newItStart;
	char editPrompt;

	searchReturnType searchResult;
	ofstream fout;
	int outputLooper;



	borderSymbol = '*';
	borderWidth = 120;
	menuTitle = "SERENDIPITY BOOKSELLERS";
	menuSubtitle = "EDIT BOOK";

	deleteBool = true;


		for (borderCounter = 0; borderCounter < 120; borderCounter++)
		{
			cout << '*';
		}
		cout << endl;
		titleBuffer = 120 / 2;
		cout << '*' << setw(titleBuffer + 12) << "SERENDIPITY  BOOKSELLERS" << setw(titleBuffer - 13) << '*' << endl;
		cout << '*' << setw(titleBuffer + 4)  << "DELETE  BOOK" << setw(titleBuffer - 5) << '*' << endl;
		cout << '*' << setw(119) << '*' << endl;
		cout << '*' << setw(titleBuffer - 10) << " CURRENT BOOK COUNT " << bookList.length() <<  setw(titleBuffer + 9 - to_string(bookList.length()).length()) << '*' << endl;
		cout << '*' << setw(119) << '*' << endl;
		for (borderCounter = 0; borderCounter < 120; borderCounter++)
		{
			cout << '*';
		}
		cout << endl;
		cout << "<Please press enter to continue>";
		cin.ignore(10000, '\n');
		system("cls");
		while(deleteBool)
		{
			deleteBool = false;
			searchCount = 0;
			found = true;
			continueSearch = false;
			userChoice = 0;
			searchLoopStart = 0;
			breakBool = false;
			correctBook = false;

			while(!correctBook && !breakBool && !breakBool)
			{
				searchCount = 0;

				if (!continueSearch)
				{
					searchResult = lookUpBook(bookList);
				}
				else
				{
					strcpy(upperWord, searchResult.getSearchTerm().c_str());
					for (int letterCounter = 0; letterCounter < searchResult.getSearchTerm().length(); letterCounter++)
					{
						upperWord[letterCounter] = toupper(upperWord[letterCounter]);
					}
					newSearch = upperWord;
					newBook = new bookType;
					newBook->setTitle(newSearch);
					newBook->setSortType(3);





				newItStart = bookList.begin();
				for (int searchIncrementor = 0; searchIncrementor < searchLoopStart; searchIncrementor++)
				{
					++newItStart;
				}

				for (bookIt = newItStart; bookIt != bookList.end();
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
								//bookHolder = new bookType(*bookIt, 3);
							system("cls");
							bookHolder->bookInfo();
							found = true;
							//test
							searchResult.setReturnLocation(searchCount + searchLoopStart);
							}
							else
							{
								found = false;
								searchCount++;
							}




						}


					}


					if (!found)
					{
						system("cls");
						cout << "**BOOK COULD NOT BE FOUND**" << endl << endl
							 << "<Press ENTER to continue>";
						searchResult.setReturnLocation(-1);
						cin.ignore(10000, '\n');
					}
				}

				cout << endl << endl;




				if (searchResult.getReturnLocation() >= 0 && !breakBool && found)
				{


					bookIt = bookList.begin();
					for (searchMover = 0; searchMover < searchResult.getReturnLocation(); searchMover++)
					{
						++bookIt;
					}

					bookHolder = new bookType(*bookIt, 3);


					cout << "Is this the book you would like to delete?: ";
					do
					{
						cin >> editPrompt;
						cin.clear();
						cin.ignore(10000, '\n');
						if (toupper(editPrompt)!= 'Y' && toupper(editPrompt) != 'N')
						{
							cout << "**Invalid Input - Please enter yes or no**";
						}
					}while(toupper(editPrompt)!= 'Y' && toupper(editPrompt) != 'N');

						if (toupper(editPrompt) == 'Y')
						{
							tempList.initializeList();
							for (tempIt = bookList.begin(); tempIt != bookList.end(); ++tempIt)
							{
								tempHolder = new bookType(*tempIt, 4);
								tempList.insertLast(*tempHolder);
								delete tempHolder;

							}
							bookHolder = new bookType(*bookIt, 3);
							safetyBook = new bookType(*bookHolder, 3);
							tempList.deleteNode(*safetyBook);
							correctBook = true;




							 didSave = false;
							 system("cls");

							cout << "Delete Successful!!" << endl << endl << "Would you like to delete another book?";
							do
							{
								cin >> deleteAnother;
								cin.clear();
								cin.ignore(10000, '\n');

								if (toupper(deleteAnother) == 'Y')
								{
									deleteBool = true;
									system("cls");
								}
								else if (toupper(deleteAnother) == 'N')
								{
									deleteBool = false;
								}
								else
								{
									cout << "Invalid option please respond with yes or no: ";
								}
							}while (toupper(deleteAnother) != 'Y' && toupper(deleteAnother) != 'N' );



						}
						else
						{
							searchLoopStart = searchResult.getReturnLocation() + 1;
							correctBook = false;
							continueSearch = true;
							found = false;
						}

					}
					else
					{
						correctBook = true;
						breakBool = true;
						found = false;

					}
				}




				breakBool = true;




				if (found)
				{
					 bookList.initializeList();
					 for (tempIt = tempList.begin(); tempIt != tempList.end(); ++tempIt)
					 {
						tempHolder = new bookType(*tempIt, 3);
						bookList.insertFirst(*tempHolder);
					 }
				}
			}
		 bookIt = bookList.begin();
		 fout.open("database.txt", ofstream::out | ofstream::trunc);
		 for (outputLooper = 0; outputLooper < bookList.length(); outputLooper++)
		 {
			 fout << (*bookIt).getTitle() << endl;
			 fout << (*bookIt).getISBN() << endl;
			 fout << (*bookIt).getAuthor() << endl;
			 fout << (*bookIt).getPub() << endl;
			 fout << (*bookIt).getDateAdded() << endl;
			 fout << (*bookIt).getQtyOnHand() << endl;
			 fout << (*bookIt).getWholesale() << endl;
			 fout << (*bookIt).getRetail();
			 if (outputLooper != bookList.length() - 1)
			 {
				 fout << endl;
			 }
			 ++bookIt;
		 }
		 fout.close();
}


//		bookLocation = lookUpBook(bookList);
//		cout << endl << endl;
//		if (bookLocation >= 0)
//		{
//			do
//			{
//			cout << "Is this the book you would like to delete?: ";
//			do
//			{
//				cin >> deletePrompt;
//				cin.clear();
//				cin.ignore(10000, '\n');
//
//				if (toupper(deletePrompt) == 'Y')
//				{
//					for (deleteCounter = bookLocation; deleteCounter < bookType::getBookCount() - 1; deleteCounter++)
//					{
//						bookData[deleteCounter]->setTitle(bookData[deleteCounter + 1]->getTitle());
//						bookData[deleteCounter]->setISBN(bookData[deleteCounter + 1]->getISBN());
//						bookData[deleteCounter]->setAuthor(bookData[deleteCounter + 1]->getAuthor());
//						bookData[deleteCounter]->setPub(bookData[deleteCounter + 1]->getPub());
//						bookData[deleteCounter]->setDateAdded(bookData[deleteCounter + 1]->getDateAdded());
//						bookData[deleteCounter]->setQtyOnHand(bookData[deleteCounter + 1]->getQtyOnHand());
//						bookData[deleteCounter]->setWholesale(bookData[deleteCounter + 1]->getWholesale());
//						bookData[deleteCounter]->setRetail(bookData[deleteCounter + 1]->getRetail());
//					}
//					delete bookData[bookType::getBookCount() - 1];
//					bookType::decBookCount();
//					cout << "Book Deleted" << endl;
//				}
//				else if (toupper(deletePrompt) == 'N')
//				{
//					system("cls");
//					enable = true;
//					isbnSearch = 0;
//					newStart = bookLocation + 1;
//						do
//						{
//
//							for (searchLooper = newStart; searchLooper < bookType::getBookCount(); searchLooper++)
//							{
//								if ((titleSearch == string::npos && userSearch != bookData[searchLooper]->getISBN()) || lastTitle == titleSearch || enable)
//								{
//									enable = false;
//									lastTitle = -1;
//									titleSearch = bookData[searchLooper]->getTitle().find(userSearch);
//									titleHolder = searchLooper;
//
//								}
//
//
//
//
//
//								else if (userSearch == bookData[searchLooper]->getISBN())
//								{
//									isbnSearch = searchLooper;
//								}
//							}
//
//
//
//
//
//
//							if (titleSearch != string::npos)
//							{
//								if (newStart < bookType::getBookCount())
//								{
//									bookLocation = titleHolder;
//									bookData[titleHolder]->bookInfo();
//								}
//									/*if (bookCounter >= 1)
//									{
//										cout << " >>> BOOK LOOK UP <<<" << endl;
//										cout << "  Search: >" << userSearch << endl;
//									}
//
//									cout << titleHolder << "RESULT>: " << bookTitle[titleHolder] << endl;
//									cout << "View this book?: ";
//										do
//										{
//											cin >> viewPrompt;
//											cin.clear();
//											cin.ignore(10000, '\n');
//
//											if (toupper(viewPrompt) == 'Y')
//											{
//												system("cls");
//												bookInfo(numBooks,  bookTitle,  isbn,  author,  publisher,  dateAdded,  qtyOnHand,  wholesale,  retail, titleHolder);
//
//											}
//											else if (toupper(viewPrompt) == 'N')
//											{
//												newStart = titleHolder + 1;
//												lastTitle = titleSearch;
//												bookCounter++;
//												system("cls");
//
//											}
//											else
//											{
//												cout << "Invalid option please respond with yes or no: ";
//											}
//
//										}while(toupper(viewPrompt) != 'Y' && toupper(viewPrompt) != 'N' );*/
//							}
//
//
//							else if (userSearch == bookData[isbnSearch]->getISBN())
//							{
//
//									cout << "RESULT>: " << bookData[isbnSearch]->getTitle() << endl;
//									cout << "View this book?: ";
//										do
//										{
//											cin >> viewPrompt;
//											cin.clear();
//											cin.ignore(10000, '\n');
//
//											if (toupper(viewPrompt) == 'Y')
//											{
//												system("cls");
//												bookData[titleHolder]->bookInfo();
//
//											}
//											else if (toupper(viewPrompt) == 'N')
//											{
//
//												newStart = isbnSearch + 1;
//												lastTitle = isbnSearch;
//												bookCounter++;
//												system("cls");
//											}
//											else
//											{
//												cout << "Invalid option please respond with yes or no: ";
//											}
//
//										}while(toupper(viewPrompt) != 'Y' && toupper(viewPrompt) != 'N' );
//							}
//							else
//							{
//								cout << "NO RESULTS - Hit enter to continue.";
//								cin.ignore(10000,'\n');
//								break;
//							}
//						}while(toupper(viewPrompt) == 'N' && bookCounter < bookType::getBookCount());
//				}
//				else
//				{
//					cout << "Invalid option please respond with yes or no: ";
//				}
//
//
//			}while(toupper(deletePrompt) != 'Y' && toupper(deletePrompt) != 'N' );
//		}while (toupper(deletePrompt) == 'N' && newStart < bookType::getBookCount());
//	}
//	cout << "Would you like to delete another book?";
//	do
//	{
//		cin >> deleteAnother;
//		cin.clear();
//		cin.ignore(10000, '\n');
//
//		if (toupper(deleteAnother) == 'Y')
//		{
//			deleteBool = true;
//			system("cls");
//		}
//		else if (toupper(deleteAnother) == 'N')
//		{
//			deleteBool = false;
//		}
//		else
//		{
//			cout << "Invalid option please respond with yes or no: ";
//		}
//	}while (toupper(deleteAnother) != 'Y' && toupper(deleteAnother) != 'N' );
//


