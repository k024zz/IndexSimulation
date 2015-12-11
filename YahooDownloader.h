#pragma once

#include<string>
#include<sstream>
#include<iostream>
#include <tchar.h>
#include <urlmon.h>
#include "Downloader.h"
#pragma comment(lib, "urlmon.lib")
using namespace std;


class YahooDownloader : public Downloader {
public:
	void download();
	map<string, map<string, double>>& getStockPrice();


private:
	stringstream strStream;
	string szWebSite;
	char TradeDate[26] = "";
	double AdjClose;
	char szSub[100];
	string InputDate;
	void downloadFile(string ws);
	void printMap();

};