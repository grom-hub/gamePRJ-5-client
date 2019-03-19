#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <iostream>
#include <cstring> // std::memcpy()
//#include <cstdlib>
//#include <cstdio>
#include <vector>

#include "connector.h"


// Connector::Connector()
// {
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		int connectorData[i].id = 0;
// 	    int connectorData[i].uX = 0;
// 	    int connectorData[i].uY = 0;
// 	    char connectorData[i].uSkin = 'X';
// 	}
// }



void Connector::initPlayer(int p1, char p2)
{
	connectorData.id = p1;
	connectorData.uSkin = p2;
}


void Connector::connectServer()
{
	
	sock = socket(AF_INET, SOCK_STREAM, 0); // Префикс AF означает "address family" - "семейство адресов".
	                                        // SOCK_STREAM - (TCP) способ передачи данных по сети.
	if(sock < 0)
	{
	    perror("socket");
	    exit(1);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // INADDR_LOOPBACK - петля типа 127.0.0.1 (127.0.0.0/8).

	if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
	    perror("connect");
	    exit(2);
	}
}


void Connector::setCommand(int p1)
{
	connectorData.command = p1;
}


void Connector::syncData()
{

	if(connectorData.command == 0)
	{
		buf[0] = 1;

		send(sock, buf, 1, 0);
	}
	else
	{
		buf[0] = 2;

		std::memcpy(&buf[1], &connectorData, sizeof(sData)); 

		send(sock, buf, sizeof(sData) + 1, 0);

	}


	//connectorData.command = 0;
	

	recv(sock, buf, 1024, 0); 

	if (buf[0] == 2)
	{
	    std::memcpy(&serverData, &buf[1], sizeof(sData) * 5); 
	}
  
}

void Connector::getData(std::vector<sData> &playerData)
{
	for (int i = 0; i < 5; ++i)
	{
		playerData[i].uX = serverData[i].uX;
		playerData[i].uY = serverData[i].uY;
		playerData[i].uSkin = serverData[i].uSkin;	
	}
}

void Connector::end()
{
	if(close(sock) == 0)
	    std::cout << "Close - OK" << std::endl;
}


//primer 

// mData dt;
// dt.x = 1;
// dt.y = 2;

// buf[0] = 1;
// std::memcpy(&buf[1], &dt, sizeof(mData)); 
// send(sock, buf, sizeof(mData) + 1, 0);



// recv(sock, buf, 1024, 0);  

// if (buf[0] == 1)
// {
//     std::memcpy(&dt, &buf[1], sizeof(mData)); 
// }