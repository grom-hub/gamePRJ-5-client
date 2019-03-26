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
    int sSize;
    int rSize;
    std::vector<unitBox> units;


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

        ctrl.setCommand(input, myid, sendBuf, sSize);

        cn.syncData(sendBuf, sSize, recvBuf);

        ctrl.recvBufHandler(recvBuf, rSize, units);

        scr.printScreen(units);

    }


    cn.end();
    scr.exitNcScreen();
	return 0;
}

