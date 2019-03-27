// #pragma once


#include "connector.h"
#include "ncScreen.h" // unitBox


struct crtData
{
    int id;
    char skin;
};


class PlayerController
{
public:
	int createPlayer(Connector &cn, char skin);
	void setCommand(int input, int myid, char *sendBuff, int &sSize);
	void recvBufHandler(char *recvBuff, int &rSize, std::vector<printData> &printObjects);




private:
	crtData createData;

};