#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <vector>



class Connector
{
public:
	char sendBuff[1024];
    char recvBuff[1024];
    int sendSize;

	//Connector();
	//~Connector();
	void connectServer();
	void syncData();
	void end();




private:
	int sock;
	struct sockaddr_in addr;
	//char buf[1024];



};