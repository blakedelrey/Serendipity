// ----------------------------------------------------------------------------
// File Name: bookType.cpp                                                    -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To create the functions used in our bookType class				  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Create class functions and operator overloads					  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// - DBSIZE				 const int				  20                          -
// - 																		  -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// - bookTitle			  string				  various					  -
// - isbn				  string				  various					  -
// - author				  string				  various					  -
// - publisher			  string				  various					  -
// - dateAdded		   	  string				  various					  -
// - qtyOnHand			  int					  various					  -
// - wholesale			  double				  various					  -
// - retail				  double				  various					  -
// - day1				  int					  dayAdded				      -
// - day2				  int					  other dayAdded			  -
// - month1				  int					  monthAdded				  -
// - month2				  int					  other monthAdded			  -
// - year1				  int					  yearAdded				      -
// - year2				  int					  other yearAdded			  -
// ----------------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

#include "bookType.h"
using namespace std;

//Setters
void bookType::setTitle(string titleName)
{
	bookTitle = titleName;
}

void bookType::setISBN(string isbnNum)
{
	isbn = isbnNum;
}

void bookType::setAuthor(string authorName)
{
	author = authorName;
}

void bookType::setPub(string publisherName)
{
	publisher = publisherName;
}

void bookType::setDateAdded(string dateAddedString)
{
	dateAdded = dateAddedString;
}

void bookType::setQtyOnHand(int qtyInStock)
{
	qtyOnHand = qtyInStock;
}

void bookType::setWholesale(float wholesaleValue)
{
	wholesale = wholesaleValue;
}

void bookType::setRetail(float retailValue)
{
	retail = retailValue;
}

void bookType::setSortType(int sortNum)
{
	sortType = sortNum;
}

void bookType::setQtyInPurchase(int qty)
{
	qtyInPurchase = qty;
}




void bookType::incBookCount()
{
	bookCount++;
}

void bookType::decBookCount()
{
	bookCount--;
}






//Getters
string bookType::getTitle() const
{
	return bookTitle;
}

string bookType::getISBN() const
{
	return isbn;
}

string bookType::getAuthor() const
{
	return author;
}

string bookType::getPub() const
{
	return publisher;
}

string bookType::getDateAdded() const
{
	return dateAdded;
}

int bookType::getQtyOnHand() const
{
	return qtyOnHand;
}

float bookType::getWholesale() const
{
	return wholesale;
}

float bookType::getRetail() const
{
	return retail;
}

int bookType::getBookCount()
{
	return bookCount;
}

int bookType::getSortType() const
{
	return sortType;
}

int bookType::getQtyInPurchase() const
{
	return qtyInPurchase;
}

void bookType::bookInfo()
{
    //Constant declarations
    const string INFO_MENU_TITLE    = "Serendipity Booksellers";
    const string INFO_MENU_SUBTITLE = "Book Information";
    const char   INFO_MENU_BORDER_DESIGN = '*';
    const int    WINDOW_WIDTH = 90;


    //Variable Declarations
    double titleCenteringBuffer;
    double subtitleCenteringBuffer;

    //start main code

    //creates book info menu graphics
    titleCenteringBuffer = (WINDOW_WIDTH + INFO_MENU_TITLE.length()) / 2;
    cout << setw(titleCenteringBuffer) << INFO_MENU_TITLE << endl;

    subtitleCenteringBuffer = (WINDOW_WIDTH + INFO_MENU_SUBTITLE.length()) / 2;
    cout << setw(subtitleCenteringBuffer) << INFO_MENU_SUBTITLE << endl << endl;

    cout << INFO_MENU_BORDER_DESIGN << " Book Title:-----------------------------------  > " << bookTitle << endl;
    cout << INFO_MENU_BORDER_DESIGN << " ISBN:-----------------------------------------  > " << isbn	   << endl;
    cout << INFO_MENU_BORDER_DESIGN << " Author:---------------------------------------  > " << author	   << endl;
    cout << INFO_MENU_BORDER_DESIGN << " Publisher:------------------------------------  > " << publisher << endl;
    cout << INFO_MENU_BORDER_DESIGN << " Date Added:-----------------------------------  > " << dateAdded << endl;
    cout << INFO_MENU_BORDER_DESIGN << " Quantity-On-Hand:-----------------------------  > " << qtyOnHand - qtyInPurchase << endl;
    cout << INFO_MENU_BORDER_DESIGN << " Wholesale Cost:-------------------------------  > " << wholesale << endl;
    cout << INFO_MENU_BORDER_DESIGN << " Retail Price:---------------------------------  > " << retail    << endl;

    cout << endl << "Please hit enter to continue.";
    cin.ignore(10000, '\n');
}

bool bookType::equals(bookType book2)
{
	bool isEqual;
	isEqual = bookTitle == book2.bookTitle && isbn == book2.isbn && author == book2.author && publisher == book2.publisher
		   && dateAdded == book2.dateAdded && qtyOnHand == book2.qtyOnHand && wholesale == book2.wholesale && retail == book2.retail;

	return isEqual;
}

bookType::bookType()
{
	bookTitle = "Empty";
	isbn = "Empty";
	author = "Empty";
	publisher = "Empty";
	dateAdded = "Empty";
	qtyOnHand = 0;
	wholesale = 0.00;
	retail = 0.00;
	sortType = 0;
	qtyInPurchase = 0;
}

bookType::bookType(string titleName, string isbnNum, string authorName, string publisherName, string dateAddedString, int qtyInStock, float wholesaleValue, float retailValue)
{
	bookTitle = titleName;
	isbn = isbnNum;
	author = authorName;
	publisher = publisherName;
	dateAdded = dateAddedString;
	qtyOnHand = qtyInStock;
	wholesale = wholesaleValue;
	retail = retailValue;
	sortType = 0;
	qtyInPurchase = 0;
}

bookType::bookType(const bookType &otherBook, int sortNum)
{
	bookTitle = otherBook.bookTitle;
	isbn = otherBook.isbn;
	author = otherBook.author;
	publisher = otherBook.publisher;
	dateAdded = otherBook.dateAdded;
	qtyOnHand = otherBook.qtyOnHand;
	wholesale = otherBook.wholesale;
	retail = otherBook.retail;
	sortType = sortNum;
	qtyInPurchase = otherBook.qtyInPurchase;
}

int bookType::bookCount = 0;

//Operator Overloading
bool bookType::operator>=(const bookType& otherBook) const
{
	bool returnBool;
	returnBool = false;
	int year1;
	int year2;
	int month1;
	int month2;
	int day1;
	int day2;
	year1 = stoi(dateAdded.substr(6,4));
	year2 = stoi(otherBook.dateAdded.substr(6,4));
	month1 = stoi(dateAdded.substr(0,2));
	month2 = stoi(otherBook.dateAdded.substr(0,2));
	day1 = stoi(dateAdded.substr(3,2));
	day2 = stoi(otherBook.dateAdded.substr(3,2));
	switch(sortType)
	{
		case 0: if (qtyOnHand <= otherBook.qtyOnHand)
				{
					returnBool = true;
				}
				break;
		case 1: if (wholesale <= otherBook.wholesale)
				{
					returnBool = true;
				}
				break;
		case 2: if (year1 > year2)
				{
					returnBool = true;
				}
				else
				{
					if (year1 == year2)
					{
						if (month1 > month2)
						{
							returnBool = true;
						}
						else
						{
							if (month1 == month2)
							{
								if (day1 >= day2)
								{
										returnBool = true;
								}

							}
						}
					}

				}
				break;
	}
	return returnBool;
}

bool bookType::operator==(const bookType& otherBook) const
{
	bool returnBool;
	char upperWord[75];
	string newWord;
	returnBool = false;
	switch(sortType)
	{
		case 0: if (qtyOnHand == otherBook.qtyOnHand)
				{
					returnBool = true;
				}
				break;
		case 1: if (wholesale == otherBook.wholesale)
				{
					returnBool = true;
				}
				break;
		case 2: if (dateAdded.substr(6,4) == otherBook.dateAdded.substr(6,4))
				{
					returnBool = true;
				}
				break;
		case 3:
				strcpy(upperWord, bookTitle.c_str());
				for (int letterCounter = 0; letterCounter < bookTitle.length(); letterCounter++)
				{
					upperWord[letterCounter] = toupper(upperWord[letterCounter]);
				}
				newWord = upperWord;
				if ((newWord.find(otherBook.bookTitle) != string::npos) || (isbn == otherBook.bookTitle))
				{
					returnBool = true;
				}

				if (bookTitle == otherBook.bookTitle)
				{
					returnBool = true;
				}

				break;
		case 4: if (bookTitle == otherBook.bookTitle)
				{
					returnBool = true;
				}
				break;
	}

	return returnBool;
}

bool bookType::operator!=(const bookType& otherBook) const
{
	bool returnBool;
	char upperWord[75];
	string newWord;
	returnBool = false;
	switch(sortType)
	{
		case 0: if (qtyOnHand != otherBook.qtyOnHand)
				{
					returnBool = true;
				}
				break;
		case 1: if (wholesale != otherBook.wholesale)
				{
					returnBool = true;
				}
				break;
		case 2: if (dateAdded.substr(6,4) != otherBook.dateAdded.substr(6,4))
				{
					returnBool = true;
				}
				break;
		case 3:
				strcpy(upperWord, bookTitle.c_str());
				for (int letterCounter = 0; letterCounter < bookTitle.length(); letterCounter++)
				{
					upperWord[letterCounter] = toupper(upperWord[letterCounter]);
				}
				newWord = upperWord;
				if ((newWord.find(otherBook.bookTitle) == string::npos) && (isbn != otherBook.bookTitle))
				{
					returnBool = false;
				}

				if (bookTitle == otherBook.bookTitle)
				{
					returnBool = true;
				}
				break;
		case 4: if (bookTitle != otherBook.bookTitle)
				{
					returnBool = true;
				}
		break;
	}
		return returnBool;
}


