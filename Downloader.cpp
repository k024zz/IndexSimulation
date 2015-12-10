#include "Downloader.h"

void Downloader::download() {
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
	string TempWS = "http://ichart.yahoo.com/table.csv?s=";
	


	for (int i = 0; i < 1; i++) {
		downloadFile(TempWS + szWebSite[i]);
		map<string, double> stock;
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
			stock[TD] = AdjClose;
		}
		strStream.clear();
		m_StocksPrice[szWebSite[i]] = stock;
	}
}

map<string, map<string, double>>& Downloader::getStockPrice() {
	return m_StocksPrice;
}

void Downloader::printMap() {
	//m_StocksPrice.find("GOOG");

	for (auto stock : m_StocksPrice) {
		cout << stock.first << endl;
		for (auto price : stock.second) {
			cout << price.first << ":" << price.second << endl;
		}
	}
}
void Downloader::downloadFile(string ws)
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