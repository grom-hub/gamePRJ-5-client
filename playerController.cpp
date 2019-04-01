//#include <iostream>
#include <cstring> // std::memcpy()
#include "playerController.h"




void PlayerController::createPlayer(Connector &cn, char skin)
{ 
    cn.sendBuff[0] = 2;
    cn.sendBuff[1] = skin;
    cn.sendSize = 2;

    cn.syncData();

    if(cn.recvBuff[0] == 2)
    {    
        myid = cn.recvBuff[1];
    }
}



void PlayerController::setCommand(int input, char *sendBuff, int &sendSize)
{
    
    sendBuff[0] = 3;
    sendBuff[1] = myid;
    sendBuff[2] = input;
    sendBuff[3] = clientFrameNum;
    sendSize = 4;
        
}



void PlayerController::recvBufHandler(char *recvBuff, NcScreen &scr)
{


    if(recvBuff[0] == 4)
    {

        if(recvPrintSize != recvBuff[1])
        {
            recvPrintSize = recvBuff[1];
            scr.printObjects.resize(recvPrintSize);
        }

        std::memcpy(scr.printObjects.data(), &recvBuff[3], sizeof(PrintObjectData) * recvPrintSize);

        std::memcpy(&scr.printStatus, &recvBuff[sizeof(PrintObjectData) * recvPrintSize + 3], sizeof(PrintStatusData));

        clientFrameNum = recvBuff[2];
        scr.updScreen = true;
    }


}