#pragma once
#include"CompareDecorator.h"
#include<sstream>
#include<fstream>
#include<iostream>
#include <tchar.h>
using namespace std;

CompareDecorator::CompareDecorator(Simulator* sim) : Decorator(sim) {
	stringstream strStream;
	char szSub[100];
	char TradeDate[26] = "";
	double AdjClose;

	char buffer[100];
	ifstream file("RealIndex.csv");
	while (!file.eof())
	{
		file.getline(buffer, 100);
		for (int i = 0; i<strlen(buffer); ++i) {
			if (buffer[i] == ',') {
				buffer[i] = ' ';
			}
		}
		stringstream ss(buffer);
		string date;
		double index;
		ss >> date;
		ss >> index;
		m_realIndexMap[date] = index;
	}
}

void CompareDecorator::run(string date) {
	Decorator::run(date);
	double real = 0;
	if (date != "exit" && getRealIndexMap().find(date) != getRealIndexMap().end()) {
		cout << "Real Dow Jones Index: " << real + getRealIndexMap().find(date)->second << endl;
	}
}
map<string, double>& CompareDecorator::getRealIndexMap() {
	return m_realIndexMap;
}