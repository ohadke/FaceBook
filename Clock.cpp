#include"Clock.h"
/******************IMPLEMENTATION_OF_CLOCK_METHOD************************/
Clock::Clock()
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	seconds = timeinfo->tm_sec;
	minutes = timeinfo->tm_min;
	hours = timeinfo->tm_hour;
}
void Clock::show()const
{
	if (hours <= ONE_DIGIT)
		cout << '0';
	cout << hours << ':';
	if (minutes <= ONE_DIGIT)
		cout << '0';
	cout << minutes << "  ";
	date.show();
}

int compareTime(const Clock& first, const Clock& second)
{
	int compare_date = compareDate(first.date, second.date);
	if (compare_date != Date::compare::EQUAL)
		return compare_date;
	if (first.hours > second.hours)
		return Date::compare::FIRST;
	else if (first.hours == second.hours)
	{
		if (first.minutes > second.minutes)
			return Date::compare::FIRST;
		else if (first.minutes == second.minutes)
			if (first.seconds >= second.seconds)
				return Date::compare::FIRST;
	}
	return Date::compare::SECOND;
}
