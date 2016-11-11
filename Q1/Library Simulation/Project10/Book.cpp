/*****************************************************************************
**Author: Shannon Jeffers
**Date: August 3 2016
**Description: implimentation file for book
*******************************************************************************/

#include "Book.hpp"
#include <iostream>
using namespace std; 

//constructor for book
Book::Book(string idc, string t, string a)
{
	idCode = idc;
	title = t;
	author = a;
	checkedOutBy = NULL;
	requestedBy = NULL;
	location = ON_SHELF;
}

int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}

string Book::getIdCode()
{
	return idCode;
}

string Book::getTitle()
{
	return title;
}

string Book::getAuthor()
{
	return author;
}

Locale Book::getLocation()
{
	return location;
}

void Book::setLocation(Locale l)
{
	location = l;
}

Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}

void Book::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
}

Patron* Book::getRequestedBy()
{
	return requestedBy;
}

void Book::setRequestedBy(Patron* r)
{
	requestedBy = r;
}

int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}

void Book::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}