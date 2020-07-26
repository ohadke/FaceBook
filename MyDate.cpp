#include"MyDate.h"

/******************IMPLEMENTATION_OF_DATE_METHOD************************/
Date::Date()
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}
Date::Date(short int day, short int month, short int year):day(day),month(month),year(year){}
void Date::show() const
{
	if (day <= ONE_DIGIT)
		cout << "0";
	cout << day << '/';
	if (month <= ONE_DIGIT)
		cout << "0";
	cout << month << '/' << year;;
}
int compareDate(const Date& first, const Date& second)
{
	if (first.year > second.year)
		return Date::compare::FIRST;
	else if (first.year < second.year)
		return Date::compare::SECOND;
	else {
		if (first.month > second.month)
			return Date::compare::FIRST;
		else if (first.month < second.month)
			return Date::compare::SECOND;
		else
		{
			if (first.day > second.day)
				return Date::compare::FIRST;
			else if (first.day < second.day)
				return Date::compare::SECOND;
			else
				return Date::compare::EQUAL;
		}
	}
}


