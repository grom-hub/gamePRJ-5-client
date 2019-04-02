// #pragma once


#include "connector.h"
#include "ncScreen.h" // PrintData, StatusData





class PlayerController
{
public:
	void createPlayer(Connector &connect, int &myid, char skin);
	void setCommand(int input, int &myid, char *sendBuff, int &sendSize);
	void recvBuffHandler(char *recvBuff, NcScreen &screen);




private:
	int recvPrintSize;
	int clientFrameNum;
};