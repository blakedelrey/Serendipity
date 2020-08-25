// ----------------------------------------------------------------------------
// File Name: deletebook.h                                                    -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To create the function prototype for deleting a book			  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Create prototype for deleteBook								      -
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

#ifndef DELETEBOOK_H_
#define DELETEBOOK_H_

#include "bookType.h"

void deleteBook(unorderedLinkedList<bookType> &bookList);



#endif /* DELETEBOOK_H_ */
