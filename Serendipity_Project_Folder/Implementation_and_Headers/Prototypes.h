// ----------------------------------------------------------------------------
// File Name: Prototypes.h                                                   -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: January 16th, 2019                                          -
// Date of Last Modification: April 16th, 2019                              -
// ----------------------------------------------------------------------------
// Purpose: To review the material we learned in CS1A and create prototypes   -
//			for functions used in this project
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Create prototype for GenerateCenteredMenu Function				  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                 DATA TYPE               INITIAL VALUE               -
// - -----------          -------------           ------------------          -
// -																		  -
// ----------------------------------------------------------------------------
#ifndef Prototypes_h
#define Prototypes_h

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int GenerateCenteredMenu(char borderSymbol, int borderSize, string menuTitle, string menuSubtitle,
                          string menuOptionsArray[], int arraySize);



#endif /* Prototypes_h */
