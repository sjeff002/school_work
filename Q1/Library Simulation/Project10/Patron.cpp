/*****************************************************************************
**Author: Shannon Jeffers
**Date: August 3 2016
**Description: implimentation file for patron
*******************************************************************************/


#include "Patron.hpp"
using namespace std;


//contructor for patron
Patron::Patron(string idn, string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0.0;
}

string Patron::getIdNum()
{
	return idNum;
}

string Patron::getName()
{
	return name;
}

vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}


/**************************************************************************************
**Description: function to add a book class to checkedOutBooks vector
***************************************************************************************/
void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}

/***************************************************************************************
**Description: function to remove book clas form checkedOutBooks vector
****************************************************************************************/
void Patron::removeBook(Book* b)
{
	for (int i = 0; i < checkedOutBooks.size(); i++)
	{
		if (checkedOutBooks[i] == b)
			checkedOutBooks.erase(checkedOutBooks.begin() + i);
	}
}

double Patron::getFineAmount()
{
	return fineAmount;
}


/*****************************************************************************************
**Description: function to add or subtract money from the fine
******************************************************************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}

