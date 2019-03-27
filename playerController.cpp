#include <cstring> // std::memcpy()

#include "playerController.h"




int PlayerController::createPlayer(Connector &cn, char skin)
{
    createData.skin = skin;

    int sSize = sizeof(crtData);

    char sendBuff[1024];
    char recvBuff[1024];

    sendBuff[0] = 2;
    std::memcpy(&sendBuff[2], &createData, sSize);

    cn.syncData(sendBuff, sSize, recvBuff);

    if(recvBuff[0] == 2)
    {    
        std::memcpy(&createData, &recvBuff[2], sizeof(crtData));
        return createData.id;
    }
}



void PlayerController::setCommand(int input, int myid, char *sendBuff, int &sSize)
{

        if(input == 0)
        {
            sendBuff[0] = 1;
            sSize = 1;
        }

        // отправлять на сервер id, комманду.
        if(input != 0)
        {
            sendBuff[0] = 3;
            sendBuff[1] = 4;
            sendBuff[2] = myid;
            sendBuff[3] = input;
            sSize = 4;
        }

}



void PlayerController::recvBufHandler(char *recvBuff, int &rSize, std::vector<printData> &printObjects)
{

    if(recvBuff[0] == 4)
    {
        if(rSize != recvBuff[1])
        {
            rSize = recvBuff[1];
            printObjects.resize(rSize);
        }

        std::memcpy(printObjects.data(), &recvBuff[2], sizeof(printData) * rSize);
    }


}