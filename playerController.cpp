//#include <iostream>
//#include <algorithm> // std::reverse()
#include <cstring> // std::memcpy()
#include "playerController.h"




PlayerController::PlayerController()
{
    unitsFrameNum = 0;
    pwrPointsFrameNum = 0;
    starsFrameNum = 0;
}


void PlayerController::createPlayer(Connector &connect, int &myid, CreateData &createData)
{ 
    //std::reverse(createData.planet.begin(), createData.planet.end());

    connect.sendBuff[0] = 2;

    connect.sendBuff[1] = sizeof(char) * createData.planet.size();

    connect.sendBuff[2] = createData.skin;    

    std::memcpy(&connect.sendBuff[3], createData.planet.data(), sizeof(char) * createData.planet.size());
    connect.sendSize = sizeof(char) * createData.planet.size() + 3;

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
    sendBuff[3] = unitsFrameNum;
    sendBuff[4] = pwrPointsFrameNum;
    sendBuff[5] = starsFrameNum;

    sendSize = 6;
        
}



void PlayerController::recvBuffHandler(char *recvBuff, NcScreen &screen)
{

    
    if(recvBuff[0] == 4)
    {
        screen.updScreen = true;

        int buffCarriage = 0;

        unitsFrameNum = recvBuff[1];
        pwrPointsFrameNum = recvBuff[2];
        starsFrameNum = recvBuff[3];



        std::memcpy(&vectorSize, &recvBuff[4], sizeof(int) * 3);
        buffCarriage = sizeof(int) * 3 + 4;

        if(vectorSize[0] != 0)
        {
            screen.printUnits.resize(vectorSize[0]);

            std::memcpy(screen.printUnits.data(), &recvBuff[buffCarriage], sizeof(PrintData) * vectorSize[0]);
            buffCarriage += sizeof(PrintData) * vectorSize[0];
        }

        
        if(vectorSize[1] != 0)
        {
            screen.printPwrPoints.resize(vectorSize[1]);

            std::memcpy(screen.printPwrPoints.data(), &recvBuff[buffCarriage], sizeof(PrintData) * vectorSize[1]);
            buffCarriage += sizeof(PrintData) * vectorSize[1];

            std::memcpy(&screen.printStatus, &recvBuff[buffCarriage], sizeof(PrintStatusData));
            buffCarriage += sizeof(PrintStatusData);
        }


        if(vectorSize[2] != 0)
        {
            screen.printStars.resize(vectorSize[2]);

            std::memcpy(screen.printStars.data(), &recvBuff[buffCarriage], sizeof(PrintData) * vectorSize[2]);
            buffCarriage += sizeof(PrintData) * vectorSize[2];
        }
    }
}

















// if(recvBuff[0] == 4)
//     {
//         int copyBuffCounter;

//         if(recvPrintSize != recvBuff[1])
//         {
//             recvPrintSize = recvBuff[1];
//             screen.printObjects.resize(recvPrintSize);
//         }


//         copyBuffCounter = sizeof(PrintObjectData) * recvPrintSize;
//         std::memcpy(screen.printObjects.data(), &recvBuff[3], copyBuffCounter);

//         std::memcpy(&screen.printStatus, &recvBuff[copyBuffCounter + 3], sizeof(PrintStatusData));

//         clientFrameNum = recvBuff[2];

//         // unitsFrameNum = recvBuff[2];
//         // pwrPointsFrameNum = recvBuff[3];
//         // starsFrameNum = recvBuff[4];

//         screen.updScreen = true;
//     }