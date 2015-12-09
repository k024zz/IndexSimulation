#pragma once

#include <iostream>
#include <sstream>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;

public:
	Date(char* date);
	void print();

	bool operator >(const Date& date);
	bool operator <(const Date& date);
	bool operator ==(const Date& date);
};