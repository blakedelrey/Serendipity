// ----------------------------------------------------------------------------
// File Name: cashier.cpp 													  -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: January 16th, 2019                                          -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To recall how to use cout and cin statements to both take user    -
// 			input from the console and calculate and display new data based   -
// 			on those inputs.												  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Display menu title and subtitle using cout.  					  -
//	Step 2: Prompt user for date, quantity of book they want to buy, ISBN	  -
//			of that book, title of the book, and price of the book using cout -
//			and cin statements.												  -
//	Step 3: Calculate subtotal for the books being purchased as well as 	  -
//			the total accounting for sales tax.								  -
//	Step 4: Display all relevant information in an organized menu.			  -
//  Step 5: Allow user to choose if they would like to make a receipt for 	  -
// 			another book or return to the main menu and save DB.			  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                    DATA TYPE               INITIAL VALUE            -
// - -----------             -------------           ------------------       -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                    DATA TYPE           INITIAL VALUE                -
// - -----------             -------------       ------------------           -
// - day 					 string			     Input from structArray		  -
// - bookQuantity			 int				 Input from user              -
// - isbn					 string				 Input from structArray		  -
// - bookTitle				 string				 Input from user			  -
// - bookPrice				 float				 Input from structArray		  -
// - singleSubtotal			 float				 Calculated using user input  -
// - salesTax				 float				 Calculated using user input  -
// - totalSale				 float				 Calculated using user input  -
// - userSelection			 char				 Input from user			  -
// - userBool				 bool				 Calculated using user input  -
// - bookLocation			 int				 location of book being purch -
// - changeQtyPrompt		 int				 prompt to change bookQty	  -
// - goodQty				 bool				 Checks if qty is valid		  -
// - breakBool				 bool				 checks if func should break  -
// - borderAdjuster			 int				 Used for formatting border   -
// - bookIt					 LLI				 Iterates through bookList	  -
// - deletedBookIt			 LLI				 Iterates through deletedBooks-
// - purchasedBookIt		 LLI				 Iterates through purchasedBoo-
// - bookCopier				 LLI			     Iterates through bookListCopy-
// - purchasedBookHolder	 *bookType			 Holds purchased book		  -
// - searchMover			 Int				 Moves search start to new loc-
// - deletedBooks			 ULL				 Holds deleted books		  -
// - bookListCopy			 ULL				 Copy of bookList			  -
// - purchasedBooks			 ULL				 Holds purchased books		  -
// - tempList				 ULL				 Holds bookList books		  -
// - bookHolder				 *bookType			 Holds books				  -
// - correctBook			 bool				 Checks if bookHolder has book-
// - startOver				 bool				 Checks if func should startov-
// - tempBook				*bookType			 Holds books				  -
// - purchaseFound			 bool				Checks if purch book exists   -
// - finalSaleLooper		 int				 Loops through purch books	  -
// - restartSearch		     bool				Checks if search needs restart-
// - continueSearch			 bool				Checks if search needs contd  -
// - quantitySet			 *bookType			Updates purchasedBook qty	  -
// - testIt					 LLI				Used for error checking		  -
// - testBookHolder		     *bookType			Used for error checking		  -
// ----------------------------------------------------------------------------

#include <fstream>
#include "cashier.h"
#include "lookUpBook.h"
#include "globals.h"
#include <cmath>
#include <ctime>


//name: reports
//purpose: Allows user to input book info and determine total cost for those books
//arguments passed: NA
void cashier(unorderedLinkedList<bookType> &bookList)
{
    //Constant declarations

    //Variable Declarations


    //start main code
	string day;
	int bookQuantity;
	string isbn;
	string bookTitle;
	float salesTax;
	float totalSale;
	char userSelection;
	char confirmSale;
	int borderLength;
	int bookLocation;
	int changeQtyPrompt;
	bool goodQty;
	bool breakBool;

	int borderAdjustor;



	//New Variables
	linkedListIterator<bookType> bookIt;
	linkedListIterator<bookType> deletedBookIt;
	linkedListIterator<bookType> purchasedBookIt;
	linkedListIterator<bookType> bookCopier;
	linkedListIterator<bookType> returnBookIt;
	linkedListIterator<bookType> tempIt;
	bookType *purchasedBookHolder;
	int searchMover;
	unorderedLinkedList<bookType> deletedBooks;
	unorderedLinkedList<bookType> bookListCopy;
	unorderedLinkedList<bookType> purchasedBooks;
	unorderedLinkedList<bookType> tempList;
	bookType *bookHolder;
	bool correctBook;
	bool startOver;
	bookType *tempBook;
	bool purchaseFound;
	int finalSaleLooper;
	bool restartSearch;
	bool continueSearch;



	bookType *quantitySet;
	linkedListIterator<bookType> testIt;
	bookType *testBookHolder;


	searchReturnType searchResult;



	char purchasePrompt;

	double subtotal;

	ofstream fout;
	int outputLooper;

	char upperWord[75];
	string newSearch;
	bookType *newBook;
	bool found;
	int searchCount;
	linkedListIterator<bookType> newItStart;
	int searchLoopStart;
	continueSearch = false;


	time_t t = time(NULL);
	tm* tPtr = localtime(&t);


	cout << endl << endl;
	cout << "Serendipity Book Sellers " << endl;
	cout << " Cashier Module" << endl << endl;

	cout << "Date: " << (tPtr->tm_mon)+1 <<"/" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_year)+1900<< endl;

	startOver = true;
	while (startOver && !breakBool)
	{
		deletedBooks.initializeList();
		bookListCopy.initializeList();
		purchasedBooks.initializeList();
		tempList.initializeList();

		startOver = true;
		purchaseFound = false;
		subtotal = 0;
		goodQty = true;
		breakBool = false;
		finalSaleLooper = 0;

		correctBook = false;
		confirmSale = 'Z';
		restartSearch = true;
		//Check crash

		bookListCopy.initializeList();
		for (bookCopier = bookList.begin(); bookCopier != bookList.end(); ++bookCopier)
		{
			bookHolder = new bookType(*bookCopier, 3);
			bookListCopy.insertLast(*bookHolder);
		}

		bookList.initializeList();
		for (bookCopier = bookListCopy.begin(); bookCopier != bookListCopy.end(); ++bookCopier)
		{
			bookHolder = new bookType(*bookCopier, 3);
			bookList.insertLast(*bookHolder);
		}
		//Check crash

		while(!correctBook && !breakBool)
		{
			while(restartSearch)
			{
				found = false;
				restartSearch = false;
				if (!continueSearch)
				{
					searchResult = lookUpBook(bookList);
					if (searchResult.getReturnLocation() > -1)
					{
						found = true;
					}
				}
				else
				{
					searchCount = 0;
					continueSearch = false;
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
						breakBool = true;
						cin.ignore(10000, '\n');
					}
				}


				cout << endl << endl;


				if (searchResult.getReturnLocation() >= 0 && found)
				{
					bookIt = bookList.begin();
					for (searchMover = 0; searchMover < searchResult.getReturnLocation(); searchMover++)
					{
						++bookIt;
					}



					cout << "Is this the book you would like to purchase?: ";
					do
					{
						cin >> purchasePrompt;
						cin.clear();
						cin.ignore(10000, '\n');
						if (toupper(purchasePrompt)!= 'Y' && toupper(purchasePrompt) != 'N')
						{
							cout << "**Invalid Input - Please enter yes or no**";
						}
					}while(toupper(purchasePrompt)!= 'Y' && toupper(purchasePrompt) != 'N');

						if (toupper(purchasePrompt) == 'Y')
						{
							correctBook = true;
							purchasedBookHolder = new bookType(*bookIt, 4);
							if (!purchasedBooks.search(*purchasedBookHolder))
							{
								purchasedBooks.insertLast(*purchasedBookHolder);
							}
							else
							{
								for (purchasedBookIt = purchasedBooks.begin(); purchasedBookIt != purchasedBooks.end(); ++purchasedBookIt)
								{
									if (*purchasedBookHolder == *purchasedBookIt)
									{
										tempBook = new bookType(*purchasedBookIt, 4);
										*purchasedBookHolder = *tempBook;
										delete tempBook;
									}
								}
							}

							do
							{
								cout << "Quantity of Book: ";
								cin  >> bookQuantity;
								cin.clear();
								cin.ignore(10000, '\n');
								if (bookQuantity < 1)
								{
									cout << "Invalid Input - Please enter a number greater than 0!";
									cout << endl;
								}
							} while (bookQuantity < 1);

							if (bookQuantity <= purchasedBookHolder->getQtyOnHand() - purchasedBookHolder->getQtyInPurchase())
							{
								goodQty = true;
							}
							else
							{
								goodQty = false;
							}

							while (bookQuantity > purchasedBookHolder->getQtyOnHand() - purchasedBookHolder->getQtyInPurchase() && !goodQty)
							{

								cout << endl;
								cout << "**Purchase Failed - Quantity of Title In Sale Exceeds Quantity On Hand**" << endl;
								cout << "Quantity in Sale: " << bookQuantity << "    Quantity on Hand: " << purchasedBookHolder->getQtyOnHand() - purchasedBookHolder->getQtyInPurchase() << endl << endl;
								cout << "<1> Change Quantity To Be Purchased." << endl
									 << "<2> Search For Another Title" << endl
									 << "<3> Return To Main Menu" << endl << endl;

								cout << "Enter your choice: ";
								cin >> changeQtyPrompt;
								cin.clear();
								cin.ignore(10000, '\n');


									switch(changeQtyPrompt)
									{
									case 1:
										do
										{
											cout << "Quantity of Book: ";
											cin  >> bookQuantity;
											cin.clear();
											cin.ignore(10000, '\n');
											if (bookQuantity < 1)
											{
												cout << "Invalid Input - Please enter a number greater than 0!";
												cout << endl;
											}
										} while (bookQuantity < 1);
										if (bookQuantity <= purchasedBookHolder->getQtyOnHand() - purchasedBookHolder->getQtyInPurchase() && bookQuantity > 0)
										{
											goodQty = true;
										}
									break;

									case 2: bookQuantity = -1;
											correctBook = false;
											goodQty = true;
											restartSearch = true;
											purchasedBooks.deleteNode(*purchasedBookHolder);
											system("cls");
											break;

									case 3: breakBool = true;
											goodQty = true;


											break;

									}
							}

							if (goodQty && !breakBool && !restartSearch)
							{
								purchasedBookHolder->setQtyInPurchase(purchasedBookHolder->getQtyInPurchase() + bookQuantity);

								bookListCopy.initializeList();
								for (bookCopier = bookList.begin(); bookCopier != bookList.end(); ++bookCopier)
								{
									bookHolder = new bookType(*bookCopier, 3);
									bookListCopy.insertLast(*bookHolder);
								}

								bookList.initializeList();
								for (bookCopier = bookListCopy.begin(); bookCopier != bookListCopy.end(); ++bookCopier)
								{
									bookHolder = new bookType(*bookCopier, 4);
									bookList.insertLast(*bookHolder);
								}

								for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
								{
									if (*purchasedBookHolder == *bookIt)
									{
										quantitySet = new bookType(*purchasedBookHolder, 3);
										bookList.deleteNode(*purchasedBookHolder);
										bookList.insertFirst(*quantitySet);
									}
								}

								bookListCopy.initializeList();
								for (bookCopier = bookList.begin(); bookCopier != bookList.end(); ++bookCopier)
								{
									bookHolder = new bookType(*bookCopier, 3);
									bookListCopy.insertLast(*bookHolder);
								}

								bookList.initializeList();
								for (bookCopier = bookListCopy.begin(); bookCopier != bookListCopy.end(); ++bookCopier)
								{
									bookHolder = new bookType(*bookCopier, 3);
									bookList.insertLast(*bookHolder);
								}







								if (purchasedBooks.search(*purchasedBookHolder))
								{
									for (purchasedBookIt = purchasedBooks.begin(); purchasedBookIt != purchasedBooks.end(); ++purchasedBookIt)
									{
										if (*purchasedBookHolder == *purchasedBookIt)
										{
											purchasedBooks.deleteNode(*purchasedBookIt);
											purchasedBooks.insertLast(*purchasedBookHolder);
										}
									}

								}
								else
								{
									purchasedBooks.insertLast(*purchasedBookHolder);
								}

							}




							if (!breakBool && !restartSearch)
							{
								system("cls");
								cout << "**Purchase successful!**" << endl << endl;
								cout << "Would you like to purchase another book?";
								do
								{
									cin >> purchasePrompt;
									cin.clear();
									cin.ignore(10000, '\n');

									if (toupper(purchasePrompt) == 'Y')
									{
										system("cls");
										correctBook = false;
										restartSearch = true;
									}
									else if (toupper(purchasePrompt) == 'N')
									{
										correctBook = true;
									}
									else
									{
										cout << "Invalid option please respond with yes or no: ";
									}
								}while (toupper(purchasePrompt) != 'Y' && toupper(purchasePrompt) != 'N' );
							}
						}
						else
						{
							system("cls");
							correctBook = false;
							restartSearch = true;
							continueSearch = true;
							searchLoopStart = searchResult.getReturnLocation() + 1;
							found = false;
						}

				}
				else
				{
					breakBool = true;
					cout << "**Book could not be found**";
				}
			}
		}
		if (!breakBool)
		{
			for (purchasedBookIt = purchasedBooks.begin(); purchasedBookIt != purchasedBooks.end(); ++purchasedBookIt)
			{
				bookHolder = new bookType(*purchasedBookIt, 3);
				subtotal += bookHolder->getRetail() * bookHolder->getQtyInPurchase();
			}




			//Sale screen Graphics and Calculations
			cout << "Serendipity Book Sellers " << endl << endl;
			cout << "Date: " << (tPtr->tm_mon)+1 <<"/" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_year)+1900<< endl << endl;

			cout << left;
			cout << setw(4) << "Qty" << setw(14) << "ISBN"
				 << setw(90) << "Title" << setw(9) << "Price"
				 << setw(9) << "Total" << endl;

			for (borderLength = 1; borderLength <= 10 + 1 + 4 + 90 + 9 + 9 + 5; borderLength++)
			{
				cout << "-";
			}
			cout << endl;



			cout << endl;
			cout << right;





			for (purchasedBookIt = purchasedBooks.begin(); purchasedBookIt != purchasedBooks.end(); ++purchasedBookIt)
			{
				bookHolder = new bookType(*purchasedBookIt, 3);
				double priceChecker = bookHolder->getRetail();
				if (priceChecker >= 100)
				{
					borderAdjustor = 1;
				}
				else
				{
					borderAdjustor = 0;
				}

				cout << left;
				cout << setw(4) << bookHolder->getQtyInPurchase() << setw(bookHolder->getISBN().length() + 1) << bookHolder->getISBN()
					 << setw(90) << bookHolder->getTitle() << setw(2) << "$";
				cout << left  << fixed << setprecision(2) << setw(7) << bookHolder->getRetail()
					 << "$";
				cout << left <<  setprecision(2)  << " "   << bookHolder->getRetail() * bookHolder->getQtyInPurchase();


				cout << endl;
			}

			cout << right;



			cout << endl << endl << endl;

			cout << setw(16) << "";
			cout << "Subtotal";
			cout << setw(7 + 10 + 1 + 90 - 23) << "$"
				 << setw(6) << subtotal << endl;

			salesTax = subtotal * .06;
			cout << setw(16) << "";
			cout << "Tax";
			cout << setw(7 + 10 + 1 + 90 - 18) << "$"
				 << setw(6) << salesTax << endl;

			totalSale = subtotal + salesTax;
			cout << setw(16) << "";
			cout << "Total";
			cout << setw(7 + 10 + 1 + 90 - 20) << "$"
				 << setw(6) << totalSale << endl;

			cout << endl << endl;
			cout << "Are you sure you would like to make this purchase?";

			while (!breakBool && toupper(confirmSale) != 'Y' && toupper(confirmSale) != 'N' )
			{
				cin >> confirmSale;
				cin.clear();
				cin.ignore(10000, '\n');

				if (toupper(confirmSale) == 'Y')
				{
					tempList.initializeList();
					for (tempIt = bookList.begin(); tempIt != bookList.end(); ++tempIt)
					{
						tempBook = new bookType(*tempIt, 4);
						tempList.insertLast(*tempBook);
					}


					bookIt = bookList.begin();
					finalSaleLooper = bookList.length();
					bookList.initializeList();


					for (purchasedBookIt = purchasedBooks.begin(); purchasedBookIt != purchasedBooks.end(); ++purchasedBookIt)
					{
						for (tempIt = tempList.begin(); tempIt != tempList.end(); ++ tempIt)
						{

							if (*tempIt == *purchasedBookIt)
							{
								tempBook = new bookType(*purchasedBookIt, 4);
								tempList.deleteNode(*tempIt);
								tempBook->setQtyOnHand(tempBook->getQtyOnHand() - tempBook->getQtyInPurchase());
								tempBook->setQtyInPurchase(0);
								tempList.insertFirst(*tempBook);
							}

						}

					}
					for (bookIt = tempList.begin(); bookIt != tempList.end(); ++bookIt)
					{
						bookList.insertLast(*bookIt);
					}





					cout << "Thank You for Shopping at Serendipity!";
					cout << endl << endl;
					cout << "Would you like to enter a new bill?";

					do
					{
						cin >> userSelection;
						cin.clear();
						cin.ignore(10000, '\n');

						if (toupper(userSelection) == 'Y')
						{
							startOver = true;
							system("cls");
						}
						else if (toupper(userSelection) == 'N')
						{
							startOver = false;
						}
						else
						{
							cout << "Invalid option please respond with yes or no: ";
						}

					}while(toupper(userSelection) != 'Y' && toupper(userSelection) != 'N' );

				}
				else if (toupper(confirmSale) == 'N')
				{
					tempList.initializeList();
					for (tempIt = bookList.begin(); tempIt != bookList.end(); ++tempIt)
					{
						tempBook = new bookType(*tempIt, 4);
						tempList.insertLast(*tempBook);
					}


					bookIt = bookList.begin();
					finalSaleLooper = bookList.length();
					bookList.initializeList();


					for (purchasedBookIt = purchasedBooks.begin(); purchasedBookIt != purchasedBooks.end(); ++purchasedBookIt)
					{
						for (tempIt = tempList.begin(); tempIt != tempList.end(); ++ tempIt)
						{

							if (*tempIt == *purchasedBookIt)
							{
								tempBook = new bookType(*purchasedBookIt, 4);
								tempList.deleteNode(*tempIt);
								tempBook->setQtyInPurchase(0);
								tempList.insertFirst(*tempBook);
							}

						}

					}
					for (bookIt = tempList.begin(); bookIt != tempList.end(); ++bookIt)
					{
						bookList.insertLast(*bookIt);
					}
					cout << endl << endl;
					cout << "Would you like to enter a new bill?";

					do
					{
						cin >> userSelection;
						cin.clear();
						cin.ignore(10000, '\n');

						if (toupper(userSelection) == 'Y')
						{
							startOver = true;
							system("cls");
						}
						else if (toupper(userSelection) == 'N')
						{
							startOver = false;
						}
						else
						{
							cout << "Invalid option please respond with yes or no: ";
						}

					}while(toupper(userSelection) != 'Y' && toupper(userSelection) != 'N' );
				}
				else
				{
					cout << "Invalid option please respond with yes or no: ";
				}

			}
		}
	}
	system("cls");
	if (breakBool)
	{
		bookListCopy.initializeList();
		for (bookCopier = bookList.begin(); bookCopier != bookList.end(); ++bookCopier)
		{
			bookHolder = new bookType(*bookCopier, 3);
			bookHolder->setQtyInPurchase(0);
			bookListCopy.insertLast(*bookHolder);
		}
		bookList.initializeList();
		for (bookIt = bookListCopy.begin(); bookIt != bookListCopy.end(); ++bookIt)
		{
			bookHolder = new bookType(*bookIt, 3);
			bookHolder->setQtyInPurchase(0);
			bookList.insertLast(*bookHolder);
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

