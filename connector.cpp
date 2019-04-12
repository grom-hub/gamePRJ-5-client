#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> // inet_addr()

#include <unistd.h>
#include <iostream>
#include <cstring> // std::memcpy()
//#include <cstdlib>
//#include <cstdio>
#include <vector>

#include "connector.h"





int Connector::connectServer(int gameMode)
{
	
	sock = socket(AF_INET, SOCK_STREAM, 0); // Префикс AF означает "address family" - "семейство адресов".
	                                        // SOCK_STREAM - (TCP) способ передачи данных по сети.
	if(sock < 0)
	{
	    // perror("socket");
	    // exit(1);
	    return 1;
	}

	addr.sin_family = AF_INET;
	//addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // INADDR_LOOPBACK - петля типа 127.0.0.1 (127.0.0.0/8).
	if(gameMode == 1)
	{
		addr.sin_addr.s_addr = inet_addr("192.168.0.78");
		addr.sin_port = htons(3425);
	}

	if(gameMode == 2)
	{
		return 1;
	}


	if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
	    // perror("connect");
	    // exit(2);
	    return 1;
	}
	return 0;
}


int Connector::syncData()
{

	send(sock, sendBuff, sendSize, 0);	

	bytesRead = recv(sock, recvBuff, 102400, 0);

	if(bytesRead <= 0) // Выход при потере соединения
		return 1;
	if(bytesRead > 100000) // Защита от переполнения буфера
		return 1;


 	return 0;
}


void Connector::end()
{
	if(close(sock) == 0)
	    std::cout << "Disconnect. Socket close - ok." << std::endl;
}





//------
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
//------



//------
// if(connectorData.command == 0)
// 	{
// 		buf[0] = 1;

// 		send(sock, buf, 1, 0);
// 	}
// 	else
// 	{
// 		buf[0] = 2;

// 		std::memcpy(&buf[1], &connectorData, sizeof(sData)); 

// 		send(sock, buf, sizeof(sData) + 1, 0);

// 	}


// 	//connectorData.command = 0;
	

// 	recv(sock, buf, 1024, 0); 

// 	if (buf[0] == 2)
// 	{
// 	    std::memcpy(&serverData, &buf[1], sizeof(sData) * 5); 
// 	}
//-------