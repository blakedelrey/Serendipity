// ----------------------------------------------------------------------------
// File Name: reports.cpp                                                     -
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
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                    DATA TYPE               INITIAL VALUE            -
// - -----------             -------------           ------------------       -
// - REPORTS_MENU_TITLE      string                  "Serendipity Booksellers"-
// - REPORTS_MENU_SUBTITLE   string					 "Reports"                -
// - WINDOW_WIDTH            int					  90                      -
// - REPORTS_MENU_ARRAY_SIZE int					  4                       -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                     DATA TYPE           INITIAL VALUE               -
// - -----------              -------------       ------------------          -
// - reportsMenuOptionsArray  string			  "Inventory Listing",        -
// -											  "Inventory Wholesale        -
// - 											   Value", "Inventory Resale  -
// - 											   Value", "Listing by        -
// - 											   Quantity", "Listing by     -
// -											   Cost", "Listing by Age",   -
// -											  "Return to Main Menu"       -
// - userSelection		      int				  Input from user             -
// - bookPrintLooper		  int				  Loops through books		  -
// - totalValue				  double			  total wholesale or resale   -
// - numDecimals			  int				   number of decimal points   -
// - pageNumber				  int				  number of pages in print    -
// - totalPages				  int				total number of pages in print-
// - borderCounter			  int				Used for formatting			  -
// - lengthSpacer			  int				Used for formatting			  -
// - bookIt					  LLI				Iterates through Linked List  -
// - bookHolder				  *bookType			Holds books to print		  -
// - totalValue				  double			Holds total val for given listing -
// - qtyBookList			  OLL				database ordered by qty		  -
// - wholesaleBookList		  OLL			    database ordered by wholesale -
// - dateBookList			  OLL			    database ordered by date	  -
// ----------------------------------------------------------------------------


#include "reports.h"
#include "bookType.h"
#include <cmath>
#include <ctime>
#include "globals.h"

//name: reports
//purpose: Creates menu that allows the user to select different book reporting options
//arguments passed: NA
void reports(unorderedLinkedList<bookType> &bookList)
{
    //Constant declarations
    const string REPORTS_MENU_TITLE = "Serendipity Booksellers";
    const string REPORTS_MENU_SUBTITLE = "Reports";
    const int    WINDOW_WIDTH = 90;
    const int    REPORTS_MENU_ARRAY_SIZE = 7;

    //Variable Declarations
    string reportsMenuOptionsArray[REPORTS_MENU_ARRAY_SIZE] =
    	{"Inventory Listing", "Inventory Wholesale Value",
    	 "Inventory Resale Value", "Listing by Quantity",
         "Listing by Cost", "Listing by Age", "Return to Main Menu"};

    int userSelection;
//
//
//    //start main code

    linkedListIterator<bookType> bookIt;
    bookType *bookHolder;
    orderedLinkedList<bookType> qtyBookList;
	orderedLinkedList<bookType> wholesaleBookList;
	orderedLinkedList<bookType> dateBookList;

	qtyBookList.initializeList();
	wholesaleBookList.initializeList();
	dateBookList.initializeList();

	for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
	{
		bookHolder = new bookType(*bookIt, 0);
		qtyBookList.insert(*bookHolder);
		delete bookHolder;

		bookHolder = new bookType(*bookIt, 1);
		wholesaleBookList.insert(*bookHolder);
		delete bookHolder;

		bookHolder = new bookType(*bookIt, 2);
		dateBookList.insert(*bookHolder);
		delete bookHolder;
	}

    do
    {

		//creates main menu graphics
		userSelection = GenerateCenteredMenu('*', WINDOW_WIDTH, REPORTS_MENU_TITLE,
											 REPORTS_MENU_SUBTITLE,
											 reportsMenuOptionsArray,
											 REPORTS_MENU_ARRAY_SIZE);

		switch (userSelection)
		{
			case 1 : repListing(bookList);
					 break;
			case 2 : repWholesale(wholesaleBookList);
					 break;
			case 3 : repRetail(bookList);
					 break;
			case 4 : repQuantity(qtyBookList);
					 break;
			case 5 : repCost(wholesaleBookList);
					 break;
			case 6 : repAge(dateBookList);
					 break;
			case 7 : break;
			default: cout << "INVALID INPUT HIT ENTER TO TRY AGAIN";
		}
		system("cls");
    } while(userSelection != 7);

    system("cls");
}

//name: repListing
//purpose: Displays the replisting
//arguments passed: bookData
void repListing(unorderedLinkedList<bookType> &bookList)
{
	int bookPrintLooper;
	int pageLooper;
	int decimalLooper;
	int numDecimals;
	int pageNumber;
	int totalPages;
	int borderCounter;
	int lengthSpacer;

	time_t t = time(NULL);
	tm* tPtr = localtime(&t);

	numDecimals = 0;
	pageNumber = 1;
	bookPrintLooper = 0;

	linkedListIterator<bookType> bookIt;
	bookType *bookHolder;

	system("cls");

//119
	if (bookList.length() < 10)
	{
		totalPages = 1;
	}
	else
	{
		totalPages = (bookList.length() / 10);
		if (bookList.length() % 10 > 0)
		{
			totalPages++;
		}
	}

	for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
	{
		bookHolder = new bookType(*bookIt, 3);
		if ((bookPrintLooper % 10 == 0 || bookPrintLooper == 0) && pageNumber <= totalPages  )
		{
			if (bookPrintLooper != 0)
			{
				pageNumber++;
				cout << endl;
				cout << "<Press ENTER to continue>";
				cin.ignore(10000, '\n');
				system("cls");
			}
			cout << left;
			for (borderCounter = 0; borderCounter < 122; borderCounter++)
			{
				cout << '*';
			}
			if (pageNumber < 10)
			{
				lengthSpacer = 1;
			}
			else
			{
				lengthSpacer = 0;
			}
			cout << endl;
			cout << "*" << setw(120) << "    " <<  "*" << endl;
			cout << "* " << setw(60 - 13) << " " << "SERENDIPITY  BOOKSELLERS" << setw(63 - 13 - 2) << "    " <<  "*" << endl;
			cout << "* " << setw(60 - 9)  << " " << "REPORT LISTING" << setw(63 - 7 - 2) << "       " <<  "*" << endl;
			cout << "* DATE: " << (tPtr->tm_mon)+1 <<"/" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_year)+1900
				 << "   PAGE: " << pageNumber << " of " << totalPages
				 <<  " "
				 << "  CURRENT BOOK COUNT: " << bookList.length() << setw(to_string(bookList.length()).length() + lengthSpacer) << " "
				 << "                                                          *" << endl;
			cout << "*" << setw(120) << " " <<  "*" << endl;
			cout << "* TITLE                       ISBN          AUTHOR         PUBLISHER      DATE ADDED QTY O/H WHOLESALE COST RETAIL PRICE *" << endl;
			cout << "* --------------------------- ----------    -------------- -------------- ---------- ------- -------------- ------------ *" << endl;
			cout << right;

		}
		cout << left;
		cout << "* " <<bookHolder->getTitle().substr(0,27) << setw(28 - bookHolder->getTitle().substr(0,27).length()) << " "
			 << bookHolder->getISBN() << " "
			 << bookHolder->getAuthor().substr(0,14) << setw(15 - bookHolder->getAuthor().substr(0,14).length()) << " "
			 << bookHolder->getPub().substr(0,14) << setw(15 - bookHolder->getPub().substr(0,14).length()) << " "
			 << bookHolder->getDateAdded() << " ";
		cout << right;
		cout << setw(7) << bookHolder->getQtyOnHand()
			 << " " << setw(6) << "$";
		numDecimals = bookHolder->getWholesale() / 10;
		if (numDecimals >= 1)
		{
			if (numDecimals >= 10)
			{
				numDecimals = 2;
			}
			else
			{
				numDecimals = 3;
			}
		}
		else
		{
			numDecimals = 4;
		}
		for (decimalLooper = 0; decimalLooper < numDecimals; decimalLooper++)
		{
			cout << '.';
		}
		cout << setprecision(2) << fixed << bookHolder->getWholesale();
		cout << "      " << "$";
		numDecimals = bookHolder->getRetail() / 10;
		if (numDecimals >= 1)
		{
			if (numDecimals >= 10)
			{
				numDecimals = 0;
			}
			else
			{
				numDecimals = 1;
			}
		}
		else
		{
			numDecimals = 2;
		}
		for (decimalLooper = 0; decimalLooper < numDecimals; decimalLooper++)
		{
			cout << '.';
		}
		cout << fixed << setprecision(2) << bookHolder->getRetail() << " *" << endl;
		if (bookPrintLooper != bookList.length() - 1)
		{
			cout << "*" << setw(121) << "*" << endl;
		}

		bookPrintLooper++;
	}

	cout << endl << "<Press ENTER to continue>";
	cin.ignore(1000, '\n');
}

//name: repWholesale
//purpose: Displays the wholesale report
//arguments passed: bookData
void repWholesale(orderedLinkedList<bookType> &bookList)
{
	int bookPrintLooper;
		int pageLooper;
		int decimalLooper;
		int numDecimals;
		int pageNumber;
		int totalPages;
		int borderCounter;
		double totalValue;
		int lengthSpacer;

		time_t t = time(NULL);
		tm* tPtr = localtime(&t);

		numDecimals = 0;
		pageNumber = 1;
		totalValue = 0;
		bookPrintLooper =0;

		linkedListIterator<bookType> bookIt;
		bookType *bookHolder;

		system("cls");

	//119

		if (bookList.length() < 10)
		{
			totalPages = 1;
		}
		else
		{
			totalPages = (bookList.length() / 10);
			if (bookList.length() % 10 > 0)
			{
				totalPages++;
			}
		}

		for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
		{
			bookHolder = new bookType(*bookIt, 1);
			if ((bookPrintLooper % 10 == 0 || bookPrintLooper == 0) && pageNumber <= totalPages  )
			{

				if (bookPrintLooper != 0)
				{
					pageNumber++;
					cout << endl;
					cout << "<Press ENTER to continue>";
					cin.ignore(10000, '\n');
					system("cls");
				}
				cout << left;
				for (borderCounter = 0; borderCounter < 116; borderCounter++)
				{
					cout << '*';
				}

				if (pageNumber < 10)
				{
					lengthSpacer = 1;
				}
				else
				{
					lengthSpacer = 0;
				}
				cout << endl;
				cout << "*" << setw(114) << " " <<  "*" << endl;
				cout << "* " << setw(60 - 13) << " " << "SERENDIPITY  BOOKSELLERS" << setw(57 - 13 - 2) << " " <<  "*" << endl;
				cout << "* " << setw(60 - 13)  << " " << "REPORT WHOLESALE LISTING" << setw(57 - 7 - 2 - 6) << " " <<  "*" << endl;
				cout << "* DATE: " << (tPtr->tm_mon)+1 <<"/" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_year)+1900
					 << "   PAGE: " << pageNumber << " of " << totalPages
					 <<  " "
					 << "  CURRENT BOOK COUNT: " << bookList.length() << setw(to_string(bookList.length()).length() + lengthSpacer) << " "
					 << "                                                    *" << endl;
				cout << "*" << setw(114) << " " <<  "*" << endl;
				cout << "* TITLE                                                          ISBN                  QTY O/H      WHOLESALE COST *" << endl;
				cout << "* -------------------------------------------------------------- ----------            -------      -------------- *" << endl;
				cout << right;

			}
			cout << left;
			cout << "* " << bookHolder->getTitle().substr(0,60)
				 << setw(63 - bookHolder->getTitle().substr(0,60).length()) << " "  << bookHolder->getISBN() << " ";
			cout << right;
			cout << setw(15) << bookHolder->getQtyOnHand()
				 << " " << setw(11) << "$";
			numDecimals = bookHolder->getWholesale() / 10;
			if (numDecimals >= 1)
			{
				if (numDecimals >= 10)
				{
					numDecimals = 2;
				}
				else
				{
					numDecimals = 3;
				}
			}
			else
			{
				numDecimals = 4;
			}
			for (decimalLooper = 0; decimalLooper < numDecimals; decimalLooper++)
			{
				cout << '.';
			}
			cout << setprecision(2) << fixed << bookHolder->getWholesale() << " *" << endl;
			totalValue += (bookHolder->getWholesale()) * (bookHolder->getQtyOnHand()) ;


				cout << "*" << setw(115) << "*" << endl;


			bookPrintLooper++;
		}

		cout << right;
		cout << "* TOTAL WHOLESALE VALUE: $" << fixed << setprecision(2) << totalValue << setw(114 - 20 - to_string(totalValue).length()) << '*';
		cout << endl << endl << "<Press ENTER to continue>";
		cin.ignore(1000, '\n');


}

//name: repRetail
//purpose: Dispalys the retail report
//arguments passed: NA
void repRetail(unorderedLinkedList<bookType> &bookList)
{
	int bookPrintLooper;
	int pageLooper;
	int decimalLooper;
	int numDecimals;
	int pageNumber;
	int totalPages;
	int borderCounter;
	double totalValue;
	int lengthSpacer;

	time_t t = time(NULL);
	tm* tPtr = localtime(&t);

	numDecimals = 0;
	pageNumber = 1;
	totalValue = 0;
	bookPrintLooper = 0;

	linkedListIterator<bookType> bookIt;
	bookType *bookHolder;

	system("cls");

//119
	if (bookList.length() < 10)
	{
		totalPages = 1;
	}
	else
	{
		totalPages = (bookList.length() / 10);
		if (bookList.length() % 10 > 0)
		{
			totalPages++;
		}
	}

	for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
	{
		bookHolder = new bookType(*bookIt, 3);

		if ((bookPrintLooper % 10 == 0 || bookPrintLooper == 0) && pageNumber <= totalPages  )
		{
			if (bookPrintLooper != 0)
			{
				pageNumber++;
				cout << endl;
				cout << "<Press ENTER to continue>";
				cin.ignore(10000, '\n');
				system("cls");
			}
			cout << left;
			for (borderCounter = 0; borderCounter < 113; borderCounter++)
			{
				cout << '*';
			}


			if (pageNumber < 10)
			{
				lengthSpacer = 1;
			}
			else
			{
				lengthSpacer = 0;
			}
			cout << endl;
			cout << "*" << setw(111) << " " <<  "*" << endl;
			cout << "* " << setw(60 - 13) << " " << "SERENDIPITY  BOOKSELLERS" << setw(54 - 13 - 2) << " " <<  "*" << endl;
			cout << "* " << setw(60 - 13)  << " " << "REPORT RETAIL LISTING" << setw(57 - 7 - 2 - 6) << " " <<  "*" << endl;
			cout << "* DATE: " << (tPtr->tm_mon)+1 <<"/" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_year)+1900
				 << "   PAGE: " << pageNumber << " of " << totalPages
				 <<  " "
				 << "  CURRENT BOOK COUNT: " << bookList.length() << setw(to_string(bookList.length()).length() + lengthSpacer) << " "
				 << "                                                 *" << endl;
			cout << "*" << setw(111) << " " <<  "*" << endl;
			cout << "* TITLE                                                          ISBN                  QTY O/H      RETAIL COST *" << endl;
			cout << "* -------------------------------------------------------------- ----------            -------      ----------- *" << endl;
			cout << right;

		}
		cout << left;
		cout << "* " << bookHolder->getTitle().substr(0,60)
			 << setw(63 - bookHolder->getTitle().substr(0,60).length()) << " "  << bookHolder->getISBN() << " ";
		cout << right;
		cout << setw(15) << bookHolder->getQtyOnHand()
			 << setw(9) << "$";
		numDecimals = bookHolder->getRetail() / 10;
		if (numDecimals >= 1)
		{
			if (numDecimals >= 10)
			{
				numDecimals = 2;
			}
			else
			{
				numDecimals = 3;
			}
		}
		else
		{
			numDecimals = 4;
		}
		for (decimalLooper = 0; decimalLooper < numDecimals; decimalLooper++)
		{
			cout << '.';
		}
		cout << fixed << setprecision(2) << bookHolder->getRetail() << " *" << endl;
		totalValue += (bookHolder->getRetail()) * (bookHolder->getQtyOnHand()) ;


			cout << "*" << setw(112) << "*" << endl;


			bookPrintLooper++;
	}

	cout << right;
	cout << "* TOTAL RETAIL VALUE: $" << fixed << setprecision(2) << totalValue << setw(120 - 26 - to_string(totalValue).length()) << '*';
	cout << endl << endl << "<Press ENTER to continue>";
	cin.ignore(1000, '\n');
}

//name: repQuantity
//purpose: Displays text that the switch has succeeded
//arguments passed: NA
void repQuantity(orderedLinkedList<bookType> &bookList)
{
	int bookPrintLooper;
		int pageLooper;
		int decimalLooper;
		int numDecimals;
		int pageNumber;
		int totalPages;
		int borderCounter;
		double totalValue;
		int lengthSpacer;

		time_t t = time(NULL);
		tm* tPtr = localtime(&t);

		numDecimals = 0;
		pageNumber = 1;
		totalValue = 0;
		bookPrintLooper = 0;

		linkedListIterator<bookType> bookIt;
		bookType *bookHolder;

		system("cls");

	//119
		if (bookList.length() < 10)
		{
			totalPages = 1;
		}
		else
		{
			totalPages = (bookList.length() / 10);
			if (bookList.length() % 10 > 0)
			{
				totalPages++;
			}
		}

		for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
		{
			bookHolder = new bookType(*bookIt, 3);

			if ((bookPrintLooper % 10 == 0 || bookPrintLooper == 0) && pageNumber <= totalPages  )
			{
				if (bookPrintLooper != 0)
				{
					pageNumber++;
					cout << endl;
					cout << "<Press ENTER to continue>";
					cin.ignore(10000, '\n');
					system("cls");
				}
				cout << left;
				for (borderCounter = 0; borderCounter < 113; borderCounter++)
				{
					cout << '*';
				}


				if (pageNumber < 10)
				{
					lengthSpacer = 1;
				}
				else
				{
					lengthSpacer = 0;
				}
				cout << endl;
				cout << "*" << setw(111) << " " <<  "*" << endl;
				cout << "* " << setw(60 - 13) << " " << "SERENDIPITY  BOOKSELLERS" << setw(54 - 13 - 2) << " " <<  "*" << endl;
				cout << "* " << setw(55 - 13)  << " " << "REPORT BY QUANTITY ON HAND (HI-LOW)" << setw(48 - 7 - 2 - 6) << " " <<  "*" << endl;
				cout << "* DATE: " << (tPtr->tm_mon)+1 <<"/" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_year)+1900
					 << "   PAGE: " << pageNumber << " of " << totalPages
					 <<  " "
					 << "  CURRENT BOOK COUNT: " << bookList.length() << setw(to_string(bookList.length()).length() + lengthSpacer) << " "
					 << "                                                 *" << endl;
				cout << "*" << setw(111) << " " <<  "*" << endl;
				cout << "* TITLE                                                                  ISBN                           QTY O/H *" << endl;
				cout << "* --------------------------------------------------------------         ----------                     ------- *" << endl;
				cout << right;

			}
			cout << left;
			cout << "* " << bookHolder->getTitle().substr(0,60)
				 << setw(71 - bookHolder->getTitle().substr(0,60).length()) << "         "  << bookHolder->getISBN() << "          ";
			cout << right;
			cout << setw(15) << bookHolder->getQtyOnHand() << " *" << endl;


			cout << "*" << setw(112) << "*" << endl;


				bookPrintLooper++;
		}


		cout << endl << endl << "<Press ENTER to continue>";
		cin.ignore(1000, '\n');
}

//name: repCost
//purpose: Displays text that the switch has succeeded
//arguments passed: NA
void repCost(orderedLinkedList<bookType> &bookList)
{
	int bookPrintLooper;
	int pageLooper;
	int decimalLooper;
	int numDecimals;
	int pageNumber;
	int totalPages;
	int borderCounter;
	double totalValue;
	int lengthSpacer;

	time_t t = time(NULL);
	tm* tPtr = localtime(&t);

	numDecimals = 0;
	pageNumber = 1;
	totalValue = 0;
	bookPrintLooper =0;

	linkedListIterator<bookType> bookIt;
	bookType *bookHolder;

	system("cls");

//119

	if (bookList.length() < 10)
	{
		totalPages = 1;
	}
	else
	{
		totalPages = (bookList.length() / 10);
		if (bookList.length() % 10 > 0)
		{
			totalPages++;
		}
	}

	for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
	{
		bookHolder = new bookType(*bookIt, 1);
		if ((bookPrintLooper % 10 == 0 || bookPrintLooper == 0) && pageNumber <= totalPages  )
		{

			if (bookPrintLooper != 0)
			{
				pageNumber++;
				cout << endl;
				cout << "<Press ENTER to continue>";
				cin.ignore(10000, '\n');
				system("cls");
			}
			cout << left;
			for (borderCounter = 0; borderCounter < 116; borderCounter++)
			{
				cout << '*';
			}

			if (pageNumber < 10)
			{
				lengthSpacer = 1;
			}
			else
			{
				lengthSpacer = 0;
			}
			cout << endl;
			cout << "*" << setw(114) << " " <<  "*" << endl;
			cout << "* " << setw(60 - 13) << " " << "SERENDIPITY  BOOKSELLERS" << setw(57 - 13 - 2) << " " <<  "*" << endl;
			cout << "* " << setw(58 - 13)  << " " << "REPORT WHOLESALE COST (HI-LOW)" << setw(53 - 7 - 2 - 6) << " " <<  "*" << endl;
			cout << "* DATE: " << (tPtr->tm_mon)+1 <<"/" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_year)+1900
				 << "   PAGE: " << pageNumber << " of " << totalPages
				 <<  " "
				 << "  CURRENT BOOK COUNT: " << bookList.length() << setw(to_string(bookList.length()).length() + lengthSpacer) << " "
				 << "                                                    *" << endl;
			cout << "*" << setw(114) << " " <<  "*" << endl;
			cout << "* TITLE                                                          ISBN                  QTY O/H      WHOLESALE COST *" << endl;
			cout << "* -------------------------------------------------------------- ----------            -------      -------------- *" << endl;
			cout << right;

		}
		cout << left;
		cout << "* " << bookHolder->getTitle().substr(0,60)
			 << setw(63 - bookHolder->getTitle().substr(0,60).length()) << " "  << bookHolder->getISBN() << " ";
		cout << right;
		cout << setw(15) << bookHolder->getQtyOnHand()
			 << " " << setw(11) << "$";
		numDecimals = bookHolder->getWholesale() / 10;
		if (numDecimals >= 1)
		{
			if (numDecimals >= 10)
			{
				numDecimals = 2;
			}
			else
			{
				numDecimals = 3;
			}
		}
		else
		{
			numDecimals = 4;
		}
		for (decimalLooper = 0; decimalLooper < numDecimals; decimalLooper++)
		{
			cout << '.';
		}
		cout << setprecision(2) << fixed << bookHolder->getWholesale() << " *" << endl;
		totalValue += (bookHolder->getWholesale()) * (bookHolder->getQtyOnHand()) ;


			cout << "*" << setw(115) << "*" << endl;


		bookPrintLooper++;
	}

	cout << endl << endl << "<Press ENTER to continue>";
	cin.ignore(1000, '\n');
}

//name: repAge
//purpose: Displays text that the switch has succeeded
//arguments passed: NA
void repAge(orderedLinkedList<bookType> &bookList)
{
	int bookPrintLooper;
	int pageLooper;
	int decimalLooper;
	int numDecimals;
	int pageNumber;
	int totalPages;
	int borderCounter;
	double totalValue;
	int lengthSpacer;

	time_t t = time(NULL);
	tm* tPtr = localtime(&t);

	numDecimals = 0;
	pageNumber = 1;
	totalValue = 0;
	bookPrintLooper =0;

	linkedListIterator<bookType> bookIt;
	bookType *bookHolder;

	system("cls");

//119

	if (bookList.length() < 10)
	{
		totalPages = 1;
	}
	else
	{
		totalPages = (bookList.length() / 10);
		if (bookList.length() % 10 > 0)
		{
			totalPages++;
		}
	}

	for (bookIt = bookList.begin(); bookIt != bookList.end(); ++bookIt)
	{
		bookHolder = new bookType(*bookIt, 1);
		if ((bookPrintLooper % 10 == 0 || bookPrintLooper == 0) && pageNumber <= totalPages  )
		{

			if (bookPrintLooper != 0)
			{
				pageNumber++;
				cout << endl;
				cout << "<Press ENTER to continue>";
				cin.ignore(10000, '\n');
				system("cls");
			}
			cout << left;
			for (borderCounter = 0; borderCounter < 116; borderCounter++)
			{
				cout << '*';
			}

			if (pageNumber < 10)
			{
				lengthSpacer = 1;
			}
			else
			{
				lengthSpacer = 0;
			}
			cout << endl;
			cout << "*" << setw(114) << " " <<  "*" << endl;
			cout << "* " << setw(60 - 13) << " " << "SERENDIPITY  BOOKSELLERS" << setw(57 - 13 - 2) << " " <<  "*" << endl;
			cout << "* " << setw(60 - 13)  << " " << "REPORT BY AGE (OLDEST FIRST)" << setw(53 - 7 - 2 - 6) << " " <<  "*" << endl;
			cout << "* DATE: " << (tPtr->tm_mon)+1 <<"/" <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_year)+1900
				 << "   PAGE: " << pageNumber << " of " << totalPages
				 <<  " "
				 << "  CURRENT BOOK COUNT: " << bookList.length() << setw(to_string(bookList.length()).length() + lengthSpacer) << " "
				 << "                                                    *" << endl;
			cout << "*" << setw(114) << " " <<  "*" << endl;
			cout << "* TITLE                                                          ISBN                  QTY O/H      WHOLESALE COST *" << endl;
			cout << "* -------------------------------------------------------------- ----------            -------      -------------- *" << endl;
			cout << right;

		}
		cout << left;
		cout << "* " << bookHolder->getTitle().substr(0,60)
			 << setw(63 - bookHolder->getTitle().substr(0,60).length()) << " "  << bookHolder->getISBN() << " ";
		cout << right;
		cout << setw(15) << bookHolder->getQtyOnHand()
			 << " " << setw(19) << bookHolder->getDateAdded() << " *" << endl;



			cout << "*" << setw(115) << "*" << endl;


		bookPrintLooper++;
	}

	cout << endl << endl << "<Press ENTER to continue>";
	cin.ignore(1000, '\n');
}





