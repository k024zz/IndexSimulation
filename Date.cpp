#include "Date.h"

Date::Date(char* date) {
	string str(date);
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '-') {
			str[i] = ' ';
		}
	}
	stringstream ss(str);
	ss >> year;
	ss >> month;
	ss >> day;
}

void Date::print() {
	cout << year << "/" << month << "/" << day << endl;
}

bool Date::operator >(const Date& date) {
	int a = year * 10000 + month * 100 + day;
	int b = date.year * 10000 + date.month * 100 + date.day;
	return a > b;
}

bool Date::operator <(const Date& date) {
	return !((*this) > date);
}

bool Date::operator ==(const Date& date) {
	int a = year * 10000 + month * 100 + day;
	int b = date.year * 10000 + date.month * 100 + date.day;
	return a == b;
}