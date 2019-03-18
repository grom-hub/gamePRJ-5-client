#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <vector>


struct sData
{
	int id;
    int uX;
    int uY;
    char uSkin;
    int command;
};

class Connector
{
public:
	//Connector();
	//~Connector();
	void initPlayer(int p1, char p2);
	void connectServer();
	void setCommand(int p1);
	void syncData();
	void getData(std::vector<sData> &playerData);
	void end();




private:
	sData connectorData;
	sData serverData[5];
	int myid;
	int pSkin;
	int command;

	int sock;
	struct sockaddr_in addr;
	char buf[1024];



};