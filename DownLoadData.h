
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
	static DownLoadData* DLD_instance;
	stringstream strStream;
	string szWebSite;
	char TradeDate[26] = "";
	double AdjClose;
	char szSub[100];
	string InputDate;

public:
	static DownLoadData* instance();
	void downloadFile(string ws);
	void printData();
	double obtainNumber(string date);
};

