/*****************************************************************************
**Author: Shannon Jeffers
**Date: August 3 2016
**Description: implimentation file for library
*******************************************************************************/

#include "Library.hpp"
#include <iostream>
using namespace std;


//constructor for library
Library::Library()
{
	currentDate = 0;
}


/********************************************************************************
**Description:function to add a book to holdings vector
*********************************************************************************/
void Library::addBook(Book* b)
{
	holdings.push_back(b);
}


/********************************************************************************
**Description: function to add patron to members vector
********************************************************************************/
void Library::addPatron(Patron* p)
{
	members.push_back(p);
}

/*********************************************************************************
**Description: function to check out a book from the library
**********************************************************************************/
string Library::checkOutBook(string pID, string bID)
{
	Patron* person;
	person = getPatron(pID);
	Book* text;
	text = getBook(bID);
	Patron* request;
	request = text->getRequestedBy();


	if (person == NULL && text == NULL)
		return "Book not found.";
	else if (text == NULL)
		return "Book not found.";
	else if (person == NULL)
		return "Patron not found.";
	else
	{
		Locale check = text->getLocation();
		if (check == CHECKED_OUT)
			return "book already checked out";
		else if (check == ON_HOLD_SHELF)
		{
			if (request == person)
			{
				text->setCheckedOutBy(person);
				text->setDateCheckedOut(currentDate);
				text->setRequestedBy(NULL);
				text->setLocation(CHECKED_OUT);
				person->addBook(text);
				return "check out successful";
			}
			else
				return "book on hold my other patron";
		}
		else
		{
			text->setCheckedOutBy(person);
			text->setDateCheckedOut(currentDate);
			text->setLocation(CHECKED_OUT);
			person->addBook(text);
			return "check out successful";
		}
	}
}


/********************************************************************************
**Description: function to return a book to the library
*********************************************************************************/
string Library::returnBook(string bID)
{

	Book* text;
	text = getBook(bID);
	Locale check;
	check = text->getLocation();
	Patron* customer;
	Patron* request;
	request = text->getRequestedBy();

	if (text == NULL)
		return "book not found";
	else if (check == ON_SHELF)
		return "book already in library";
	else
	{
		customer = text->getCheckedOutBy();
		customer->removeBook(text);
		if (request != NULL)
			text->setLocation(ON_HOLD_SHELF);
		else
			text->setLocation(ON_SHELF);
		text->setCheckedOutBy(NULL);
		return "return successful";
	}
}


/******************************************************************************
**Description: function to request a book form the library
*******************************************************************************/
string Library::requestBook(string pID, string bID)
{
	Patron* person;
	person = getPatron(pID);
	Book* text;
	text = getBook(bID);
	Patron* request;
	request = text->getRequestedBy();


	if (person == NULL && text == NULL)
		return "Book not found.";
	else if (text == NULL)
		return "Book not found.";
	else if (person == NULL)
		return "Patron not found.";
	else if (request != NULL)
		return "book already on hold";
	else
	{
		Locale check;
		check = text->getLocation();
		text->setRequestedBy(person);
		if (check == ON_SHELF)
			text->setLocation(ON_HOLD_SHELF);
		return "request sucessful";
	}
}


/**************************************************************************
**Description: function that uses amendFine to pay bill
***************************************************************************/
string Library::payFine(string pID, double payment)
{
	Patron* person;
	person = getPatron(pID);

	if (person == NULL)
		return "patron not found";
	else
	{
		payment *= -1;
		person->amendFine(payment);
		return "payment successful";
	}
}


/*******************************************************************************
**Description: function to increment date and add money to fine
********************************************************************************/
void Library::incrementCurrentDate() 
{
	currentDate++;
	for (int i = 0; i < holdings.size(); i++)
	{
		int date = holdings[i]->getDateCheckedOut();
		int max = holdings[i]->getCheckOutLength();
		if (currentDate > (date + max))
		{
			Patron* temp2 = holdings[i]->getCheckedOutBy();
			temp2->amendFine(.10);
		}
	}
}

Patron* Library::getPatron(string pID)
{
	Patron* temp = NULL;
	for (int i = 0; i < members.size(); i++)
	{
		string temp2;
		temp2 = members[i]->getIdNum();
		if (pID == temp2)
			temp = members[i];
	}
	return temp;
}

Book* Library::getBook(std::string bID)
{
	Book* temp = NULL;
	for (int i = 0; i < holdings.size(); i++)
	{
		string temp2;
		temp2 = holdings[i]->getIdCode();
		if (bID == temp2)
			temp = holdings[i];
	}
	return temp;
}