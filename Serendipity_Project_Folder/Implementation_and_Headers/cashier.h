// ----------------------------------------------------------------------------
// File Name: cashier.h                                                       -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: January 16th, 2019                                          -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To recall how to use cout and cin statements to both take user    -
// 			input from the console and calculate and display new data based   -
// 			on those inputs. We will also gather some data from structs.	  -											  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Make prototype for cashier function.							  -
// ----------------------------------------------------------------------------
// -                            Data Dictionary                               -
// - CONSTANTS                                                                -
// -                                                                          -
// - NAME                    DATA TYPE               INITIAL VALUE            -
// - -----------             -------------           ------------------       -
// -                                                                          -
// - VARIABLES                                                                -
// -                                                                          -
// - NAME                    DATA TYPE           INITIAL VALUE                -
// - -----------             -------------       ------------------           -
// -																		  -
// ----------------------------------------------------------------------------

#ifndef CASHIER_H_
#define CASHIER_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <array>
#include <stdlib.h>
#include <windows.h>
#include "globals.h"
#include "bookType.h"
#include "unorderedLinkedList.h"


using namespace std;

void cashier(unorderedLinkedList<bookType> &bookList);



#endif /* CASHIER_H_ */
