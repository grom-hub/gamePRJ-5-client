#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <vector>



class Connector
{
public:
	//Connector();
	//~Connector();
	void connectServer();
	void syncData(char *sendBuf, int sSize, char *recvBuf);
	void end();




private:
	int sock;
	struct sockaddr_in addr;
	//char buf[1024];



};