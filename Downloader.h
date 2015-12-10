#pragma once

#include <iostream>
#include <map>
using namespace std;

class Downloader {
public:
	void download();
	map<string, map<string, double>>& getStockPrice();

private:
	map<string, map<string, double>> m_StocksPrice;
};