// #pragma once


#include "connector.h"
#include "ncScreen.h" // PrintData, StatusData


struct CrtData
{
    int id;
    char skin;
};



class PlayerController
{
public:
	int createPlayer(Connector &cn, char skin);
	void setCommand(int input, int myid, char *sendBuff, int &sSize);
	void recvBufHandler(char *recvBuff, int &recvPrintSize, std::vector<PrintData> &printObjects, StatusData &playerStatus, bool &updScreen);




private:
	CrtData createData;
	int oldFrameNum;
};