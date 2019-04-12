//#include <ncurses.h>
//#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>
//#include <cstring> // std::memcpy()

#include <iostream> // cout
#include <unistd.h> // usleep()
#include <vector>
#include <string>

#include "connector.h"
#include "ncScreen.h"
#include "playerController.h"




int main(int args, char *argv[])
{

    // char initSkin = 'A';
    // std::string initPlanetSkin("<YO>");
    //initPlanetSkin = *argv[2];
    int command = 0;
    int myid;
    int gameMode = 1;

    CreateData createData;
    createData.skin = 'A';
    createData.planet = "<YO>";
    // int fakeInput = 0;
    // int fakeInputCounter = 0;


    // if(args < 2)
    // {
    //     std::cout << "No args" << std::endl;
    //     return 1;
    // }


    NcScreen screen;
    Connector connect;
    PlayerController controller;

    //screen.refreshCount = 0;


    screen.initNcScreen();

    command = screen.mainMenu(createData, gameMode);

    if(connect.connectServer(gameMode) == 1)
        command = 9;

    if(command != 9)
        controller.createPlayer(connect, myid, createData);

    while (command != 9)
    {
    	usleep(10000);

        command = screen.getInput();

        controller.setCommand(command, myid, connect.sendBuff, connect.sendSize);

        if(connect.syncData() == 1)
            break;

        controller.recvBuffHandler(connect.recvBuff, screen);

        screen.printScreen(myid);

    }


    screen.exitNcScreen();
    connect.end();
    //std::cout << initPlanetSkin << std::endl;
	return 0;
}







//fakeInput = setFakeInput(*argv[2], fakeInputCounter, command);

// int setFakeInput(char mode, int &counter, int trueInput)
// {
//     if(mode == '1')
//     {
//         counter ++;

//         if(counter == 100)
//             counter = 0;

//         if(counter < 50)
//             return 3;

//         if(counter > 50)
//             return 4;
//     }
//     else
//         return trueInput;
// }
