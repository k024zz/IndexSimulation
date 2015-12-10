//============================================================================
// Name :   YahooApiSample1.cpp
// Author : bill
// Version :
// Description : download historical chart from yahoo and display 
//============================================================================

#include <iostream>
#include <string>
#include "Downloader.h"
#include "Logger.h"

#pragma comment(lib, "urlmon.lib")

using namespace std;

int main()
{
	Downloader DL;

	DL.download();
	DL.printMap();

	
	system("pause");
	return 0;

}


