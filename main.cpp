//#include <ncurses.h>
//#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>
//#include <cstring> // std::memcpy()

#include <iostream> // cout
#include <unistd.h> // usleep()
#include <vector>

#include "connector.h"
#include "ncScreen.h"
#include "playerController.h"





int main(int args, char *argv[])
{
    int input = 0;


    if(args < 2)
    {
        std::cout << "No args" << std::endl;
        return 1;
    }


    NcScreen scr;
    Connector cn;
    PlayerController ctrl;

    scr.refreshCount = 0;

    cn.connectServer();

    ctrl.createPlayer(cn, *argv[1]);

    scr.initNcScreen();


    while (input != 'q')
    {
    	usleep(10000);


        input = scr.getInput();

        ctrl.setCommand(input, cn.sendBuff, cn.sendSize);

        cn.syncData();

        ctrl.recvBufHandler(cn.recvBuff, scr);

        scr.printScreen();

    }


    cn.end();
    scr.exitNcScreen();
    //std::cout << ctrl.myid << std::endl;
	return 0;
}

