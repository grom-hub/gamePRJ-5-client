#include <cstring> // std::memcpy()

#include "playerController.h"




int PlayerController::createPlayer(Connector &cn)
{
    createData.skin = 'A';

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