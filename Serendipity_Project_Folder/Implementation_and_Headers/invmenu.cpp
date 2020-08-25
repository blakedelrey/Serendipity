// ----------------------------------------------------------------------------
// File Name: invmenu.cpp                                                     -
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
// - INVENTORY_MENU_TITLE    string                  "Serendipity Booksellers"-
// - INVENTORY_MENU_SUBTITLE string					 "Inventory Database"     -
// - WINDOW_WIDTH            int					  90                      -
// - REPORTS_MENU_ARRAY_SIZE int					  4                       -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                      DATA TYPE           INITIAL VALUE              -
// - -----------               -------------       ------------------         -
// - inventoryMenuOptionsArray string			  "Look Up a Book", "Add      -
// -											   a Book", "Add a Book's     -
// - 											   Record", "Delete a Book",  -
// - 											   "Return to the Main Menu"  -
// - userSelection		       int				   Input from user            -
// - userSearch				   string			   Input from user			  -
// - upperBookTitleArray	   string array		   Based on user input		  -
// - searchLooper			   int				   0						  -
// - titleSearch			   int				   Based on user input		  -
// - titleHolder			   int				   Based on user input		  -
// - isbnSearch				   int				   0						  -
// - newSearch				   string			   Based on user input		  -
// - viewPrompt				   char				   Input by user			  -
// - newStart				   int				   Based on user input		  -
// - lastTitle				   int				   Based on user input		  -
// - bookCounter			   int				   0					      -
// - enable					   bool				   true						  -
// - name					   char				   "John"					  -
// - upperWord				   char				   Based on userInput		  -
// - upperWordInArray		   char				   Based on user input		  -
// - searchContinuer		   bool				   false					  -
// - menuOptionsCounter	  	 int					 1					      -
// - borderCounter		  	 int					 1                        -
// - titleCenteringBuffer 	 double				  	 (borderWidth +           -
// - 											  	  menuTitle.length()) / 2 -
// - subtitleCenteringBuffer double					 (borderWidth + 		  -
// -                                                 menuSubtitle.length())/ 2-
// - userChoice				 int					Input by user			  -
// - didSave				 bool					false					  -
// - tempBooks				 int					Based on user input	  	  -
// - menuOptionsArray		 string				    Various strings		  	  -
// - tempBookTitle			 string					Based on user input	 	  -
// - tempAuthor				 string					Based on user input		  -
// - tempPublisher			 string					Based on user input		  -
// - tempDateAdded			 string					Based on user input	 	  -
// - tempQtyOnHand			 int					Based on user input	   	  -
// - tempWholesale			 double					Based on user input	 	  -
// - tempRetail				 double					Based on user input	  	  -
// - arraySize				 int					9						  -
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


#include "invmenu.h"
#include "lookupbook.h"
#include "addbook.h"
#include "editbook.h"
#include "bookinfo.h"
#include "deletebook.h"
#include "globals.h"



//name: invMenu
//purpose: Creates menu that allows the user to select different book inventory management options
//arguments passed: bookCount, bookTitle, isbn, author, publisher, dateAdded, qtyOnHand, wholesale, retail
void invMenu(unorderedLinkedList<bookType> &bookList)
{
    //Constant declarations
    const string INVENTORY_MENU_TITLE = "Serendipity Booksellers";
    const string INVENTORY_MENU_SUBTITLE = "Inventory Database";
    const int    WINDOW_WIDTH = 90;
    const int    INVENTORY_MENU_ARRAY_SIZE = 5;

    //Variable Declarations
    string inventoryMenuOptionsArray[INVENTORY_MENU_ARRAY_SIZE] =
    {"Look Up a Book", "Add a Book", "Edit a Book's Record", "Delete a Book",
     "Return to the Main Menu"};
    int userSelection;


    //start main code

    do
    {
		//creates main menu graphics
		userSelection = GenerateCenteredMenu('*', WINDOW_WIDTH,
											 INVENTORY_MENU_TITLE,
											 INVENTORY_MENU_SUBTITLE,
											 inventoryMenuOptionsArray,
											 INVENTORY_MENU_ARRAY_SIZE);

		switch (userSelection)
		   {
			   case 1 : lookUpBook(bookList);
						break;
			   case 2 : addBook(bookList);
						break;
			   case 3 : editBook(bookList);
						break;
			   case 4 : deleteBook(bookList);
						break;
			   case 5 : break;

			   default: cout << "INVALID INPUT HIT ENTER TO TRY AGAIN";

		   }


		system("cls");

    }while (userSelection != 5);

    system("cls");
}







