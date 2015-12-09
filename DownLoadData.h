
#include<string>
#include<sstream>
#include<iostream>
#include <tchar.h>
#include <urlmon.h>

//#include"downloadFile.h"
using namespace std;
#pragma comment(lib, "urlmon.lib")

class DownLoadData {
private:
	stringstream strStream;
	string szWebSite;
	char TradeDate[26] = "";
	double AdjClose;
	char szSub[100];
	string InputDate;

public:
	DownLoadData(string ws, string date);
	void downloadFile();
	void printData();
	double obtainNumber();
};

