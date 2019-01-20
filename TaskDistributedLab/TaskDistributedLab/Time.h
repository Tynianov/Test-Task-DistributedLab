#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

class Time
{
	int seconds;
	int minutes;
	int hours;

public:
	Time();
	Time(std::string);
	Time(int, int, int);

	int getSeconds() const;
	int getMinutes() const;
	int getHours() const;
	bool isValid();

	Time & operator=(const Time &);
	Time & operator+(const Time &);
	Time & operator+=(const Time &);
	Time & operator-(const Time &);
	Time & operator-=(const Time &);
	bool operator > (const Time &);
	bool operator < (const Time &);

};

std::ostream & operator << (std::ostream &, const Time &);

inline int Time::getSeconds() const {
	return seconds;
}

inline int Time::getMinutes() const {
	return minutes;
}

inline int Time::getHours() const
{
	return hours;
}

inline bool Time::operator>(const Time & time)
{
	return this->hours > time.hours || this->minutes > time.minutes || this->seconds > time.seconds;
}

inline bool Time::operator<(const Time & time)
{
	return this->hours < time.hours || this->minutes < time.minutes || this->seconds < time.seconds;;
}
