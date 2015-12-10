#include <iostream>
#include <string>
#include "IndexSimulator.h"
#include "IndexDJX.h"
#include "IndexAlgorithm.h"
#include "Downloader.h"
#include "Logger.h"
#include "CompareDecorator.h"

#pragma comment(lib, "urlmon.lib")
using namespace std;

int main()
{
	
	string date;
	string IndexSelect = "";
	string APISelect = "";
	Downloader* DL = new Downloader();
	IndexAlgorithm* indexAlgorithm = IndexDJX::createIndexDJX(DL);
	IndexSimulator* ISimulator = new IndexSimulator(indexAlgorithm);
	Simulator* aSimulator = new CompareDecorator(ISimulator);
	
	ISimulator->init();

	cout << "**************************Welcome to Index Simulatior********************************" << endl;;
	
	do {
		cout << "Please select the index you want to simulate (1:DJAI    2:S&P 500): ";
		cin >> IndexSelect;
		if (IndexSelect == "1") {
			do{
				cout << "Please select the API you want to use (1.Yahoo Finance   2.Bloomberg):";
				cin >> APISelect;
				if (APISelect == "1") {
					while (date != "exit") {
						cout << "\nInput date(YYYY-MM-DD): ";
						cin >> date;
						aSimulator->run(date);
					}
				}
				else if (APISelect == "2") {
					cout << "NULL \n";
				}
				else {
					cout << "Error, please input again" << endl;
				}
			} while (APISelect != "1" && APISelect != "2");
		}
		else if (IndexSelect == "2") {
			do {
				cout << "Please select the API you want to use (1.Yahoo Finance    2.Bloomberg):";
				cin >> APISelect;
				if (APISelect == "1") {
					cout << "NULL\n";
				}
				else if (APISelect == "2") {
					cout << "NULL\n";
				}
				else {
					cout << "Error, please input again" << endl;
				}
			} while (APISelect != "1" && APISelect != "2");
		}
		else {
			cout << "Error, please input again" << endl;
		}
		date = "";
	} while (true);
	

	system("pause");
	return 0;
}