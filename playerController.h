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
	void createPlayer(Connector &cn, char skin);
	void setCommand(int input, char *sendBuff, int &sendSize);
	void recvBufHandler(char *recvBuff, NcScreen &scr);




private:
	CrtData createData;
	int recvPrintSize;
	int clientFrameNum;
	int myid;
};