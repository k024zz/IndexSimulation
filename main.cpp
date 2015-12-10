
#include <iostream>
#include <string>
#include "IndexSimulator.h"
#include "IndexDJX.h"
#include "IndexAlgorithm.h"
#include "Downloader.h"
#include "Logger.h"

#pragma comment(lib, "urlmon.lib")

using namespace std;

int main()
{
	Downloader* DL = new Downloader;
	IndexAlgorithm* indexAlgorithm = IndexDJX::createIndexDJX(DL);
	IndexSimulator indexSimulator(indexAlgorithm);
	indexSimulator.run();

	system("pause");
	return 0;

}