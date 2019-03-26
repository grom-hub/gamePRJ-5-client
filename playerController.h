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
	void setCommand(int input, int myid, char *sendBuf, int &sSize);
	void recvBufHandler(char *recvBuf, int &rSize, std::vector<unitBox> &units);




private:
	crtData createData;

};