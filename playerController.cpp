#include <cstring> // std::memcpy()

#include "playerController.h"




int PlayerController::createPlayer(Connector &cn, char skin)
{
    createData.skin = skin;

    int sSize = sizeof(crtData);

    char sendBuf[1024];
    char recvBuf[1024];

    sendBuf[0] = 2;
    std::memcpy(&sendBuf[2], &createData, sSize);

    cn.syncData(sendBuf, sSize, recvBuf);

    if(recvBuf[0] == 2)
    {    
        std::memcpy(&createData, &recvBuf[2], sizeof(crtData));
        return createData.id;
    }
}



void PlayerController::setCommand(int input, int myid, char *sendBuf, int &sSize)
{

        if(input == 0)
        {
            sendBuf[0] = 1;
            sSize = 1;
        }

        // отправлять на сервер id, комманду.
        if(input != 0)
        {
            sendBuf[0] = 3;
            sendBuf[1] = 4;
            sendBuf[2] = myid;
            sendBuf[3] = input;
            sSize = 4;
        }

}



void PlayerController::recvBufHandler(char *recvBuf, int &rSize, std::vector<unitBox> &units)
{

    if(recvBuf[0] == 4)
    {
        if(rSize != recvBuf[1])
        {
            rSize = recvBuf[1];
            units.resize(rSize);
        }

        std::memcpy(units.data(), &recvBuf[2], sizeof(unitBox) * rSize);
    }


}