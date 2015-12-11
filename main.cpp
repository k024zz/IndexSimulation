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
	Downloader* DL = new Downloader();
	IndexAlgorithm* indexAlgorithm = IndexDJX::createIndexDJX(DL);
	IndexSimulator* ISimulator = new IndexSimulator(indexAlgorithm);
	
	CompareDecorator* pCompareDecorator = new CompareDecorator(ISimulator);
	Simulator* aSimulator = new CompareDecorator(pCompareDecorator);
	
	//while (1) 
	aSimulator->run();

	system("pause");
	return 0;
}