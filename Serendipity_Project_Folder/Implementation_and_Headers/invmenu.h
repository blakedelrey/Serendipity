// ----------------------------------------------------------------------------
// File Name: invmenu.h                                                       -
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
//	Step 1: Create prototypes for all functions in invmenu.cpp				  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                    DATA TYPE               INITIAL VALUE            -
// - -----------             -------------           ------------------       -
// -																		  -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                      DATA TYPE           INITIAL VALUE              -
// - -----------               -------------       ------------------         -
// -																		  -
// ----------------------------------------------------------------------------

#ifndef INVMENU_H_
#define INVMENU_H_



#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <cstring>
#include "prototypes.h"
#include "globals.h"
#include "bookType.h"
#include "unorderedLinkedList.h"

using namespace std;

void invMenu(unorderedLinkedList<bookType> &bookList);

#endif /* INVMENU_H_ */
