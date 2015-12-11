#pragma once
#include"CompareDecorator.h"
#include<sstream>
#include<fstream>
#include<iostream>
#include <tchar.h>
using namespace std;

void CompareDecorator::run(std::string date) {
	Decorator::run(date);
	
	for (auto num : getRealIndexMap()) {
		cout << num.first;
	}
	//cout << getRealIndexMap().find("12/1/2014");
	cout << "hello world111" << endl;
}
map<string, double> CompareDecorator::getRealIndexMap() {
	map<string, double> realIndexMap;
	//ifstream file;
	stringstream strStream;
	char szSub[100];
	char TradeDate[26] = "";
	double AdjClose;

	//file.open("RealIndex.csv");
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
		//cout << buffer << endl;
		stringstream ss(buffer);
		string date;
		double index;
		ss >> date;
		ss >> index;
		realIndexMap[date] = index;
		//cout << date << ":" << index << endl;
	}

	for (auto i : realIndexMap) {
		cout << i.first << "    " << i.second << endl;
	}


	return realIndexMap;
}