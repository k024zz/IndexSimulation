//============================================================================
// Name :   YahooApiSample1.cpp
// Author : bill
// Version :
// Description : download historical chart from yahoo and display 
//============================================================================

#include <iostream>
#include <string>
#include "DownLoadData.h"

#pragma comment(lib, "urlmon.lib")

using namespace std;

int main()
{

	stringstream strStream;
	string stock;
	double StockResult[30] = { 0 };
	double finalResult = 0;
	string TempWS = "http://ichart.yahoo.com/table.csv?s=";
	string date, month, year;

	string szWebSite[30];
	szWebSite[0] = "MMM";
	szWebSite[1] = "AXP";
	szWebSite[2] = "AAPL";
	szWebSite[3] = "BA";
	szWebSite[4] = "CAT";
	szWebSite[5] = "CVX";
	szWebSite[6] = "CSCO";
	szWebSite[7] = "KO";
	szWebSite[8] = "DD";
	szWebSite[9] = "XOM";
	szWebSite[10] = "GE";
	szWebSite[11] = "GS";
	szWebSite[12] = "HD";
	szWebSite[13] = "INTC";
	szWebSite[14] = "IBM";
	szWebSite[15] = "JNJ";
	szWebSite[16] = "JPM";
	szWebSite[17] = "MCD";
	szWebSite[18] = "MRK";
	szWebSite[19] = "MSFT";
	szWebSite[20] = "NKE";
	szWebSite[21] = "PFE";
	szWebSite[22] = "PG";
	szWebSite[23] = "TRV";
	szWebSite[24] = "UNH";
	szWebSite[25] = "UTX";
	szWebSite[26] = "VZ";
	szWebSite[27] = "V";
	szWebSite[28] = "WMT";
	szWebSite[29] = "DIS";

	while (1) {
		cout << "Date(DD): ";
		cin >> date;
		cout << "Month(MM): ";
		cin >> month;
		cout << "Year(YYYY): ";
		cin >> year;
		date = year + "-" + month + "-" + date;

		for (int i = 0; i < 30; i++) {
			DownLoadData Test(TempWS + szWebSite[i], date);
			Test.downloadFile();
			StockResult[i] = Test.obtainNumber();
			cout << StockResult[i] << endl;
		}

		for (int i = 0; i < 30; i++) {
			finalResult += StockResult[i];
		}

		cout << "******************************************************************" << endl;
		cout << finalResult / 0.14985889030177 << endl;

	}
	system("pause");
	return 0;

}


