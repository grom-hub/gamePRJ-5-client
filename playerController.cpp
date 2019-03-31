//#include <iostream>
#include <cstring> // std::memcpy()
#include "playerController.h"




int PlayerController::createPlayer(Connector &cn, char skin)
{
    createData.skin = skin;

    int sSize = sizeof(CrtData);

    char sendBuff[1024];
    char recvBuff[1024];

    sendBuff[0] = 2;
    std::memcpy(&sendBuff[2], &createData, sSize);

    cn.syncData(sendBuff, sSize, recvBuff);

    if(recvBuff[0] == 2)
    {    
        std::memcpy(&createData, &recvBuff[2], sizeof(CrtData));
        return createData.id;
    }
}



void PlayerController::setCommand(int input, int myid, char *sendBuff, int &sSize)
{

        if(input == 0)
        {
            sendBuff[0] = 1;
            sendBuff[2] = myid;
            sSize = 3;
        }

        // отправлять на сервер id, комманду.
        if(input != 0)
        {
            sendBuff[0] = 3; // тип
            sendBuff[1] = 4; // размер
            sendBuff[2] = myid;
            sendBuff[3] = input;
            sSize = 4;
        }

}



void PlayerController::recvBufHandler(char *recvBuff, int &recvPrintSize, std::vector<PrintData> &printObjects, StatusData &playerStatus, bool &updScreen)
{


    if(recvBuff[0] == 4)
    {

        if(recvPrintSize != recvBuff[1])
        {
            recvPrintSize = recvBuff[1];
            printObjects.resize(recvPrintSize);
        }

        std::memcpy(printObjects.data(), &recvBuff[2], sizeof(PrintData) * recvPrintSize);

        std::memcpy(&playerStatus, &recvBuff[sizeof(PrintData) * recvPrintSize + 2], sizeof(StatusData));   

        if(playerStatus.frameNum == oldFrameNum)
            updScreen = false;
        else
        {
            updScreen = true;
            oldFrameNum = playerStatus.frameNum;             
        }
    }


}