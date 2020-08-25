// ----------------------------------------------------------------------------
// File Name: editBook.cpp                                                    -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To create the function for editing a book's information  		  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Call lookupBook													  -
//  Step 2: Display editing menu for searched book.							  -
//  Step 2: Add functionality to the menu for each option using setters	      -
//	Step 3: The user can either exit by saving their changes or manually 	  -
//			exiting															  -
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

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

#include "bookinfo.h"
#include "editbook.h"

#include "bookType.h"
#include "globals.h"
#include "lookupbook.h"



//name: editBook
//purpose: Allows the user to search for and edit a book's information in the database
//arguments passed: bookCount, bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail
void editBook(unorderedLinkedList<bookType> &bookList)
{
	int borderCounter;
	double titleBuffer;
	string userSearch;
	char editPrompt;
	char borderSymbol;
	int borderWidth;
	double titleCenteringBuffer;
	double subtitleCenteringBuffer;
	string menuTitle;
	string menuSubtitle;
	int menuOptionsCounter;
	int arraySize = 10;
	string menuOptionsArray[arraySize] = {"Enter Book Title", "Enter ISBN", "Enter Author", "Enter Publisher",
			 "Enter Date Added (mm/dd/yyyy)", "Enter Quantity on Hand", "Enter Wholesale Cost",
			 "Enter Retail Price", "Save Changes", "Return to Inventory Menu"};
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
	string tempBookTitle;
	string tempIsbn;
	string tempAuthor;
	string tempPublisher;
	string tempDateAdded;
	int    tempQtyOnHand;
	double tempWholesale;
	double tempRetail;
	bool didSave;
	int tempBooks;


	borderSymbol = '*';
	borderWidth = 120;
	menuTitle = "SERENDIPITY BOOKSELLERS";
	menuSubtitle = "EDIT BOOK";



	string userTitle;
	string userIsbn;
	string userAuthor;
	string userPub;
	string userDateAdded;
	int userQty;
	double userWholesale;
	double userRetail;


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
	userChoice = 0;
	didSave = false;

	unorderedLinkedList<bookType> tempList;
	bookType *tempHolder;
	linkedListIterator<bookType> tempIt;

	char upperWord[75];
	string newSearch;
	bookType *newBook;
	bool found;
	int searchCount;
	searchCount = 0;
	found = true;
	int searchLoopStart;
	searchLoopStart = 0;
	linkedListIterator<bookType> newItStart;

	ofstream fout;
	int outputLooper;


	searchReturnType searchResult;

	for (borderCounter = 0; borderCounter < 120; borderCounter++)
	{
		cout << '*';
	}
	cout << endl;
	titleBuffer = 120 / 2;
	cout << '*' << setw(titleBuffer + 12) << "SERENDIPITY  BOOKSELLERS" << setw(titleBuffer - 13) << '*' << endl;
	cout << '*' << setw(titleBuffer + 4)  << "EDIT  BOOK" << setw(titleBuffer - 5) << '*' << endl;
	cout << '*' << setw(119) << '*' << endl;
	cout << '*' << setw(titleBuffer + 7)  << " CURRENT BOOK COUNT: " << bookList.length() <<  setw(titleBuffer - 8 - to_string(bookList.length()).length()) << '*' << endl;
	cout << '*' << setw(119) << '*' << endl;
	for (borderCounter = 0; borderCounter < 120; borderCounter++)
	{
		cout << '*';
	}
	cout << endl;
	cout << "<Hit enter to continue>";
	cin.ignore(10000, '\n');
	system("cls");

	while(!correctBook && !breakBool)
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

			cout << "Is this the book you would like to edit?: ";
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


					 tempBookTitle = bookHolder->getTitle();
					 tempIsbn = bookHolder->getISBN();
					 tempAuthor = bookHolder->getAuthor();
					 tempPublisher = bookHolder->getPub();
					 tempDateAdded = bookHolder->getDateAdded();
					 tempQtyOnHand = bookHolder->getQtyOnHand();
					 tempWholesale = bookHolder->getWholesale();
					 tempRetail    = bookHolder->getRetail();
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



				while((userChoice != 10 && !didSave) && !breakBool)
				{

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

							cout << borderSymbol << setw(subtitleCenteringBuffer)  << " CURRENT BOOK COUNT: " << bookList.length()
												 << setw(borderWidth - subtitleCenteringBuffer - 1 - 9 + 1  - to_string(bookList.length()).length() + 8) << borderSymbol << endl;

							cout << borderSymbol << setw(borderWidth - 1) << borderSymbol
													 << endl;



							cout << borderSymbol << setw(borderWidth - 1) << borderSymbol
																		 << endl;

							for (borderCounter = 1; borderCounter <= borderWidth; borderCounter++)
							{
								cout << borderSymbol;
							}
							cout << endl;

							//creates  centered list of menu options
							for (menuOptionsCounter = 1; menuOptionsCounter <= arraySize;
								 menuOptionsCounter++)
							{
								cout << borderSymbol 	   << " "
									 << menuOptionsCounter << ". "
									 << menuOptionsArray[menuOptionsCounter - 1];

								switch(menuOptionsCounter)
								{
									case 1: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" <<  tempBookTitle;
											break;
									case 2: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempIsbn;
											break;
									case 3: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempAuthor;
											break;
									case 4: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempPublisher;
											break;
									case 5: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempDateAdded;
											break;
									case 6: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length()) << "> --" << tempQtyOnHand;
											break;
									case 7: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length() + 1) << "> --$" << fixed << setprecision(2) << tempWholesale;
											break;
									case 8: cout << setw(36 - menuOptionsArray[menuOptionsCounter - 1].length() + 1) << "> --$" << fixed << setprecision(2) << tempRetail;
								}


								switch(menuOptionsCounter)
								{
									case 1:  cout << setw(120 - menuOptionsArray[0].length() - 36 - tempBookTitle.length() + 11) << '*' << endl;
											 break;
									case 2:  cout << setw(120 - menuOptionsArray[1].length() - 36 - tempIsbn.length() + 5) << '*' << endl;
											 break;
									case 3:  cout << setw(120 - menuOptionsArray[2].length() - 36 - tempAuthor.length() + 7) << '*' << endl;
											 break;
									case 4:  cout << setw(120 - menuOptionsArray[3].length() - 36 - tempPublisher.length() + 10) << '*' << endl;
											 break;
									case 5:  cout << setw(120 - menuOptionsArray[4].length() - 36 - tempDateAdded.length() + 24) << '*' << endl;
											 break;
									case 6:  cout << setw(120 - menuOptionsArray[5].length() - 36 - to_string(tempQtyOnHand).length() + 17) << '*' << endl;
											 break;
									case 7:  cout << setw(120 - menuOptionsArray[6].length() - 36 - 4 + 14 - to_string(tempWholesale).length() + 8) << '*' << endl;
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
									tempBookTitle = userTitle;
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
									tempPublisher = userPub;
									break;

							case 5: cout << "Please enter today's date: ";
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
									tempQtyOnHand = userQty;
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

									bookHolder->setTitle(tempBookTitle);
									bookHolder->setISBN(tempIsbn);
									bookHolder->setAuthor(tempAuthor);
									bookHolder->setPub(tempPublisher);
									bookHolder->setDateAdded(tempDateAdded);
									bookHolder->setQtyOnHand(tempQtyOnHand);
									bookHolder->setWholesale(tempWholesale);
									bookHolder->setRetail(tempRetail);

									tempList.insertFirst(*bookHolder);

									tempBooks++;
									break;

							case 10: tempList.insertFirst(*safetyBook);
									 breakBool = true;

									break;
						}

					system("cls");


				}
	if (found)
	{
		 bookList.initializeList();
		 for (tempIt = tempList.begin(); tempIt != tempList.end(); ++tempIt)
		 {
			tempHolder = new bookType(*tempIt, 3);
			bookList.insertFirst(*tempHolder);
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




//			else if (toupper(editPrompt) == 'N')
//			{
//				system("cls");
//
//				enable = true;
//				isbnSearch = 0;
//				newStart = bookLocation + 1;
//					do
//					{
//
//						for (searchLooper = newStart; searchLooper < bookType::getBookCount(); searchLooper++)
//						{
//							if ((titleSearch == string::npos && userSearch != bookData[searchLooper]->getISBN()) || lastTitle == titleSearch || enable)
//							{
//								enable = false;
//								lastTitle = -1;
//								titleSearch = bookData[searchLooper]->getTitle().find(userSearch);
//								titleHolder = searchLooper;
//
//							}
//
//
//
//
//
//							else if (userSearch == bookData[searchLooper]->getISBN())
//							{
//								isbnSearch = searchLooper;
//							}
//						}
//
//
//
//
//
//
//						if (titleSearch != string::npos)
//						{
//							if (newStart < bookType::getBookCount())
//							{
//								bookLocation = titleHolder;
//								bookData[titleHolder]->bookInfo();
//							}
//
//						}
//
//
//						else if (userSearch == bookData[isbnSearch]->getISBN())
//						{
//
//								cout << "RESULT>: " << bookData[isbnSearch]->getTitle() << endl;
//								cout << "View this book?: ";
//									do
//									{
//										cin >> viewPrompt;
//										cin.clear();
//										cin.ignore(10000, '\n');
//
//										if (toupper(viewPrompt) == 'Y')
//										{
//											system("cls");
//											bookData[titleHolder]->bookInfo();
//
//										}
//										else if (toupper(viewPrompt) == 'N')
//										{
//											newStart = isbnSearch + 1;
//											lastTitle = isbnSearch;
//											bookCounter++;
//											system("cls");
//										}
//										else
//										{
//											cout << "Invalid option please respond with yes or no: ";
//										}
//
//									}while(toupper(viewPrompt) != 'Y' && toupper(viewPrompt) != 'N' );
//						}
//						else
//						{
//							cout << "NO RESULTS - Hit enter to continue.";
//							cin.ignore(10000,'\n');
//							break;
//						}
//					}while(toupper(viewPrompt) == 'N' && bookCounter < bookType::getBookCount());
//			}
//			else
//			{
//				cout << "Invalid option please respond with yes or no: ";
//			}
//
//
//		}while(toupper(editPrompt) != 'Y' && toupper(editPrompt) != 'N' );
//	}while (toupper(editPrompt) == 'N' && newStart < bookType::getBookCount());
//}
//
//}

