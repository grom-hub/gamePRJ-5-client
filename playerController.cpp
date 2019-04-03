//#include <iostream>
#include <cstring> // std::memcpy()
#include "playerController.h"




void PlayerController::createPlayer(Connector &connect, int &myid, char skin)
{ 
    connect.sendBuff[0] = 2;
    connect.sendBuff[1] = skin;
    connect.sendSize = 2;

    connect.syncData();

    if(connect.recvBuff[0] == 2)
    {    
        myid = connect.recvBuff[1];
    }
}



void PlayerController::setCommand(int input, int &myid, char *sendBuff, int &sendSize)
{
    
    sendBuff[0] = 3;
    sendBuff[1] = myid;
    sendBuff[2] = input;
    sendBuff[3] = clientFrameNum;
    sendSize = 4;
        
}



void PlayerController::recvBuffHandler(char *recvBuff, NcScreen &screen)
{

    if(recvBuff[0] == 4)
    {
        int copyBuffCounter;

        if(recvPrintSize != recvBuff[1])
        {
            recvPrintSize = recvBuff[1];
            screen.printObjects.resize(recvPrintSize);
        }


        copyBuffCounter = sizeof(PrintObjectData) * recvPrintSize;
        std::memcpy(screen.printObjects.data(), &recvBuff[3], copyBuffCounter);

        std::memcpy(&screen.printStatus, &recvBuff[copyBuffCounter + 3], sizeof(PrintStatusData));

        clientFrameNum = recvBuff[2];
        screen.updScreen = true;
    }


}