#pragma once


#include <map>
#include<string>
#include<sstream>
#include<iostream>
#include <tchar.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
using namespace std;


class Downloader {
public:
	void download();
	map<string, map<string, double>>& getStockPrice();
	void printMap();
private:
	stringstream strStream;
	string szWebSite;
	char TradeDate[26] = "";
	double AdjClose;
	char szSub[100];
	string InputDate;
	void downloadFile(string ws);
	
	map<string, map<string, double>> m_StocksPrice;
};