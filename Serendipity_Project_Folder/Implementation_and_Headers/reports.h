// ----------------------------------------------------------------------------
// File Name: reports.h                                                       -
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
//	Step 1: Create prototypes for all functions defined in reports.cpp		  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                    DATA TYPE               INITIAL VALUE            -
// - -----------             -------------           ------------------       -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                     DATA TYPE           INITIAL VALUE               -
// - -----------              -------------       ------------------          -
// -																		  -
// ----------------------------------------------------------------------------

#ifndef REPORTS_H_
#define REPORTS_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <windows.h>
#include "prototypes.h"
#include "bookType.h"
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"



using namespace std;

void reports(unorderedLinkedList<bookType> &bookList);

void repListing(unorderedLinkedList<bookType> &bookList);

void repWholesale(orderedLinkedList<bookType> &bookList);

void repRetail(unorderedLinkedList<bookType> &bookList);

void repQuantity(orderedLinkedList<bookType> &bookList);

void repCost(orderedLinkedList<bookType> &bookList);

void repAge(orderedLinkedList<bookType> &bookList);

#endif /* REPORTS_H_ */
