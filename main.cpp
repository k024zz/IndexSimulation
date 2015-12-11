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
	/*Downloader* DL = new Downloader;
	IndexAlgorithm* indexAlgorithm = IndexDJX::createIndexDJX(DL);
	IndexSimulator indexSimulator(indexAlgorithm);
	indexSimulator.run();*/
	string date;
	Downloader* DL = new Downloader();
	IndexAlgorithm* indexAlgorithm = IndexDJX::createIndexDJX(DL);
	IndexSimulator* ISimulator = new IndexSimulator(indexAlgorithm);
	Simulator* aSimulator = new CompareDecorator(ISimulator);
	
	ISimulator->init();

	while (date != "exit") {
		cout << "Input date(YYYY-MM-DD): ";
		cin >> date;
		aSimulator->run(date);
	}

	system("pause");
	return 0;
}