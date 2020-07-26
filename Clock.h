#ifndef __CLOCK__
#define __CLOCK__
#define _CRT_SECURE_NO_WARNINGS
/******INCLUDES******/
#include<iostream>
#include<time.h>
#include"MyDate.h"
using namespace std;

/********CLASSES***************/
class Clock
{
	Date date;
	short int seconds;
	short int minutes;
	short int hours;
	static const int ONE_DIGIT = 9;
public:
	Clock();
	void show() const;//show
	friend int compareTime(const Clock& first, const Clock& second);//in case the dates are equal we ar sorting between the time of a day
};

#endif