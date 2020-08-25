// ----------------------------------------------------------------------------
// File Name: addbook.h           	                                          -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To create the function prototype for adding a book				  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Create prototype for addBook								      -
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

#ifndef ADDBOOK_H_
#define ADDBOOK_H_

#include "bookType.h"
#include "unorderedLinkedList.h"

void addBook(unorderedLinkedList<bookType> &bookList);



#endif /* ADDBOOK_H_ */
