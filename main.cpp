//#include <ncurses.h>
//#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>

#include <unistd.h> // usleep()
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
    char sendBuff[1024];
    char recvBuff[1024];
    int sSize;
    int rSize;
    std::vector<printData> printObjects;


    if(args < 2)
    {
        std::cout << "No args" << std::endl;
        return 1;
    }

    NcScreen scr;
    Connector cn;
    PlayerController ctrl;


    cn.connectServer();

    myid = ctrl.createPlayer(cn, *argv[1]);

    scr.initNcScreen();


    while (input != 'q')
    {
    	usleep(10000);


        input = scr.getInput();

        ctrl.setCommand(input, myid, sendBuff, sSize);

        cn.syncData(sendBuff, sSize, recvBuff);

        ctrl.recvBufHandler(recvBuff, rSize, printObjects);

        scr.printScreen(printObjects);

    }


    cn.end();
    scr.exitNcScreen();
	return 0;
}

