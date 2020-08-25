// ----------------------------------------------------------------------------
// File Name: searchReturnType.cpp                                            -
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
//	Step 1: Create class functions											  -
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

#include "searchReturnType.h"

void searchReturnType::setReturnLocation(int returnValue)
{
	returnLocation = returnValue;
}

void searchReturnType::setSearchTerm(string returnValue)
{
	searchTerm = returnValue;
}

int searchReturnType::getReturnLocation()
{
	return returnLocation;
}

string searchReturnType::getSearchTerm()
{
	return searchTerm;
}

searchReturnType::searchReturnType()
{
	returnLocation = 0;
	searchTerm = "Empty";
}
