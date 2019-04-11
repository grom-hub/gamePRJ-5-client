#pragma once

//#include <string>
//#include <vector>

#include "connector.h"
#include "ncScreen.h" // PrintData, StatusData



class PlayerController
{
public:
	int createPlayer(Connector &connect, int &myid, CreateData &createData);
	void setCommand(int input, int &myid, char *sendBuff, int &sendSize);
	void recvBuffHandler(char *recvBuff, NcScreen &screen);




private:
    int unitsFrameNum;
    int pwrPointsFrameNum;
    int starsFrameNum;

	int vectorSize[3];

};