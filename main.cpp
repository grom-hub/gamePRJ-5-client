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
    int myid;

    // int fakeInput = 0;
    // int fakeInputCounter = 0;


    if(args < 2)
    {
        std::cout << "No args" << std::endl;
        return 1;
    }


    NcScreen screen;
    Connector connect;
    PlayerController controller;

    screen.refreshCount = 0;

    connect.connectServer();

    controller.createPlayer(connect, myid, *argv[1]);

    screen.initNcScreen();


    while (input != 9)
    {
    	usleep(10000);


        input = screen.getInput();

        controller.setCommand(input, myid, connect.sendBuff, connect.sendSize);

        connect.syncData();

        controller.recvBuffHandler(connect.recvBuff, screen);

        screen.printScreen(myid);

    }


    connect.end();
    screen.exitNcScreen();
	return 0;
}







//fakeInput = setFakeInput(*argv[2], fakeInputCounter, input);

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
