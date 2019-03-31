//#include <iostream>
#include <cstring> // std::memcpy()
#include "playerController.h"




void PlayerController::createPlayer(Connector &cn, char skin)
{
    createData.skin = skin;

    cn.sendSize = sizeof(CrtData);

    cn.sendBuff[0] = 2;
    std::memcpy(&cn.sendBuff[2], &createData, sizeof(CrtData));

    cn.syncData();

    if(cn.recvBuff[0] == 2)
    {    
        std::memcpy(&createData, &cn.recvBuff[2], sizeof(CrtData));
        myid = createData.id;
    }
}



void PlayerController::setCommand(int input, char *sendBuff, int &sendSize)
{
    
    sendBuff[0] = 3; // тип
    sendBuff[1] = myid;
    sendBuff[2] = input;
    sendBuff[3] = clientFrameNum;
    sendSize = 4 - 2;
        
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