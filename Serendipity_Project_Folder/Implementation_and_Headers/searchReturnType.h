// ----------------------------------------------------------------------------
// File Name: searchReturnType.cpp                                            -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                 -
// ----------------------------------------------------------------------------
// Purpose: To create the definition for searchReturnType class				  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Create class definition											  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// - 																		  -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// - returnLocation		  int					  Location in LL of book	  -
// - searchTerm			  string				  book being searched for 	  -
// ----------------------------------------------------------------------------

#include <iostream>

using namespace std;

class searchReturnType
{
private:
	int returnLocation;
	string searchTerm;

public:
	void setReturnLocation(int returnValue);
	void setSearchTerm(string returnValue);

	int getReturnLocation();
	string getSearchTerm();

	searchReturnType();
};


