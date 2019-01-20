#include "Time.h"

Time::Time() : hours(INT_MAX), minutes(INT_MAX), seconds(INT_MAX)
{
}

Time::Time(std::string timeString)
{
	char sep1, sep2;
	int matched = sscanf(timeString.c_str(), "%d%c%d%c%d", &hours, &sep1, &minutes, &sep2, &seconds);

	if (matched != 5 || sep1 != ':' || sep2 != ':')
		throw std::logic_error("Incorrect time format!");

	if (!isValid())
		throw std::logic_error("Error: time is not valid!");
}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{
}

bool Time::isValid()
{
	if (hours < 0 || hours > 24)
		return false;

	else if (minutes < 0|| minutes > 60)
		return false;

	else if (seconds < 0|| seconds > 60)
		return false;

	else
		return true;
}

Time & Time::operator=(const Time &t) 
{
	this->hours = t.hours;
	this->minutes = t.minutes;
	this->seconds = t.seconds;

	return *this;
}

Time & Time::operator+(const Time &t)
{
	Time res = *this;
	res += t;

	return res;
}

Time & Time::operator+=(const Time & t)
{
	this->hours += t.hours;
	this->minutes += t.minutes;
	this->seconds += t.seconds;

	if (seconds >= 60) {
		minutes += 1;
		seconds -= 60;
	}

	if (minutes >= 60) {
		hours += 1;
		minutes -= 60;
	}

	return *this;
}

Time & Time::operator-=(const Time &t)
{
	this->hours -= t.hours;
	this->minutes -= t.minutes;
	this->seconds -= t.seconds;

	if (seconds < 0)
		seconds += 60;

	if (minutes < 0) {
		minutes += 60;
		hours -= 1;
	}

	if (hours < 0)
		hours += 24;

	return *this;
}

Time & Time::operator-(const Time &t)
{
	Time res = *this;
	res -= t;

	return res;
}

std::ostream & operator<<( std::ostream &stream, const Time & time)
{
	stream << time.getHours() << ':' << time.getMinutes() << ':' << time.getSeconds();

	return stream;
}
