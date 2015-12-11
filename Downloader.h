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
	virtual void download() = 0;
	virtual map<string, map<string, double>>& getStockPrice() = 0;
protected:
	map<string, map<string, double>> m_StocksPrice;
};