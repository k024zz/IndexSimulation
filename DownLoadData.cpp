#include "DownLoadData.h"

//DownLoadData::DownLoadData(string ws, string date) {
//	szWebSite = ws;
//	AdjClose = 0.0;
//	InputDate = date;
//}

DownLoadData* DownLoadData::DLD_instance = NULL;
DownLoadData* DownLoadData::instance() {
	if (DLD_instance == NULL)
		DLD_instance = new DownLoadData();
	return DLD_instance;
}

double DownLoadData::obtainNumber(string date) {
	strStream.ignore(1024, '\n'); // ignore first line
	InputDate = date;
	while (strStream.good())
	{
		if (!strStream.getline(szSub, sizeof(szSub), ',')) break;

		strcpy_s(TradeDate, sizeof(TradeDate), szSub); //trade date
		strStream.getline(szSub, sizeof(szSub), ',');
		strStream.getline(szSub, sizeof(szSub), ',');
		strStream.getline(szSub, sizeof(szSub), ',');
		strStream.getline(szSub, sizeof(szSub), ',');
		strStream.getline(szSub, sizeof(szSub), ',');

		strStream.getline(szSub, sizeof(szSub));
		AdjClose = atof(szSub);					// Adjust Close
		string TD(TradeDate);

		if (TD == InputDate) return AdjClose;
		else continue;
	}
	return 0.0;
}

void DownLoadData::printData() {
	strStream.ignore(1024, '\n'); // ignore first line

	while (strStream.good())
	{
		if (!strStream.getline(szSub, sizeof(szSub), ','))
			break;

		strcpy_s(TradeDate, sizeof(TradeDate), szSub); //trade date
		strStream.getline(szSub, sizeof(szSub), ',');
		strStream.getline(szSub, sizeof(szSub), ',');
		strStream.getline(szSub, sizeof(szSub), ',');
		strStream.getline(szSub, sizeof(szSub), ',');
		strStream.getline(szSub, sizeof(szSub), ',');

		strStream.getline(szSub, sizeof(szSub));
		AdjClose = atof(szSub);					// Adjust Close
		string TD(TradeDate);

		cout << TD << "\t"
			<< AdjClose
			<< endl;
	}

}
void DownLoadData::downloadFile(string ws)
{
	szWebSite = ws;
	IStream* pStream = 0;
	URLOpenBlockingStream(0, szWebSite.c_str(), &pStream, 0, 0); // Open WebLink
	if (pStream == 0) return;  // failure 

	while (pStream != 0)
	{
		DWORD dwGot = 0;
		char szBuffer[200] = "";

		if (pStream->Read(szBuffer, sizeof(szBuffer) - 1, &dwGot) != S_OK)
			break;

		strStream << szBuffer;
	};

	if (pStream)	pStream->Release();
}