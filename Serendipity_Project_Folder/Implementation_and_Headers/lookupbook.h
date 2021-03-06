// ----------------------------------------------------------------------------
// File Name: lookupbook.h                                                    -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To create the function prototype for looking up a book			  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Create prototype for lookUpBook								      -
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

#ifndef LOOKUPBOOK_H_
#define LOOKUPBOOK_H_

#include "globals.h"
#include "bookType.h"
#include "unorderedLinkedList.h"
#include "searchReturnType.h"










searchReturnType lookUpBook(unorderedLinkedList<bookType> bookList);




#endif /* LOOKUPBOOK_H_ */
