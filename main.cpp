//#include <ncurses.h>
#include <unistd.h> // usleep()
//#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>
#include <cstring> // std::memcpy()
#include <iostream> // cout
#include <vector>

#include "connector.h"
#include "ncScreen.h"
#include "playerController.h"


// Типы буферов: 1 - пустой, 2 - создать персонажа, 3 - комманда персонажу от клиента, 4 - пакет персонажей от сервера



int main(int args, char *argv[])
{
    int myid;
    int input;
    char sendBuf[1024];
    char recvBuf[1024];
    std::vector<toScreen> printObject(5);
    int sSize;
    int rSize;
    std::vector<unitBox> units;


    // if(args < 3)
    // {
    //     std::cout << "No args" << std::endl;
    //     return 1;
    // }

    NcScreen scr;
    Connector cn;
    PlayerController ctrl;


    cn.connectServer();

    myid = ctrl.createPlayer(cn);

    scr.initNcScreen();


    while (input != 'q')
    {
    	usleep(10000);


        input = scr.getInput();

        // отправлять на сервер id, комманду.

        if(input == 0)
        {
            sendBuf[0] = 1;
            sSize = 1;
        }

        if(input != 0)
        {
            sendBuf[0] = 3;
            sendBuf[1] = 4;
            sendBuf[2] = myid;
            sendBuf[3] = input;
            sSize = 4;
        }

        cn.syncData(sendBuf, sSize, recvBuf);

        if(recvBuf[0] == 4)
        {
            if(rSize != recvBuf[1])
            {
                rSize = recvBuf[1];
                units.resize(rSize);
            }

            std::memcpy(units.data(), &recvBuf[2], sizeof(unitBox) * rSize);
        }


        scr.printScreen(units);

    }


    cn.end();
    scr.exitNcScreen();
	return 0;
}

