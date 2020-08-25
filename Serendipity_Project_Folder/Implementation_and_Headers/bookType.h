// ----------------------------------------------------------------------------
// File Name: bookType.h  	                                                  -
// ProjectName: Serendipity                                                   -
// ----------------------------------------------------------------------------
// Creator's name and email: Blake Del Rey & bcdelrey@gmail.com               -
// Course-Section: 23655                                                      -
// Creation Date: March 4th, 2019                                             -
// Date of Last Modification: May 18th, 2019                                  -
// ----------------------------------------------------------------------------
// Purpose: To create the definition for our bookType class					  -
// ----------------------------------------------------------------------------
// Algorithm:																  -
//	Step 1: Create bookType definition					 					  -
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
// - bookTitle			  string				  book title				  -
// - isbn				  string				  book isbn					  -
// - author				  string				  book author				  -
// - publisher			  string				  book publisher			  -
// - dateAdded			  string				  book dateAdded			  -
// - qtyOnHand			  int					  book qtyOnHand			  -
// - wholesale			  float				  	  book wholesaleValue		  -
// - retail				  float					  book retailValue			  -
// - sortType			  int					  book sortType 			  -
// ----------------------------------------------------------------------------

#ifndef BOOKTYPE_H_
#define BOOKTYPE_H_

#include "globals.h"
using namespace std;

class bookType
{
	private:
		string bookTitle;
		string isbn;
		string author;
		string publisher;
		string dateAdded;
		int qtyOnHand;
		float wholesale;
		float retail;
		int sortType;
		int qtyInPurchase;

		static int bookCount;

	public:
		void setTitle(string titleName);
		void setISBN(string isbnNum);
		void setAuthor(string authorName);
		void setPub(string publisherName);
		void setDateAdded(string dateAddedString);
		void setQtyOnHand(int qtyInStock);
		void setWholesale(float wholesaleValue);
		void setRetail(float retailValue);
		void setSortType(int sortNum);
		void setQtyInPurchase(int qty);

		static void incBookCount();
		static void decBookCount();

		string getTitle() const;
		string getISBN() const;
		string getAuthor() const;
		string getPub() const;
		string getDateAdded() const;
		int getQtyOnHand() const;
		float getWholesale() const;
		float getRetail() const;
		static int getBookCount();
		int getSortType() const;
		int getQtyInPurchase() const;

		void bookInfo();
		bool equals(bookType book2);
		bookType();
		bookType(string titleName, string isbnNum, string authorName, string publisherName,
				 string dateAddedString, int qtyInStock, float wholesaleValue, float retailValue);
		bookType(const bookType &otherBook, int sortNum);

		bool operator>=(const bookType& otherBook) const;
		bool operator==(const bookType& otherBook) const;
		bool operator!=(const bookType& otherBook) const;




};








#endif /* BOOKTYPE_H_ */
