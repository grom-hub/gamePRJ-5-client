// #pragma once


#include "connector.h"
#include "ncScreen.h" // PrintData, StatusData





class PlayerController
{
public:
	void createPlayer(Connector &cn, char skin);
	void setCommand(int input, char *sendBuff, int &sendSize);
	void recvBufHandler(char *recvBuff, NcScreen &scr);




private:
	int recvPrintSize;
	int clientFrameNum;
	int myid;
};