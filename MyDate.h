#ifndef __MY_DATE__
#define __MY_DATE__
#define _CRT_SECURE_NO_WARNINGS

/******INCLUDES******/
#include<iostream>
#include<time.h>
using namespace std;

/********CLASSES***************/
class Date
{
	short int day;
	short int month;
	int year;
	static const int ONE_DIGIT = 9;
public:
	enum compare { FIRST, SECOND, EQUAL };//compare times to sort
	Date();//c'tor for the current statues
	Date(short int day, short int month, short int year);//c;tor to insert a birthday
	void show() const;//show the date(birthday or status
	friend int compareDate(const Date& first, const Date& second);//compare dates to sort
};


#endif 
