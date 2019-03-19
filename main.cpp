//#include <ncurses.h>
#include <unistd.h> // usleep()
//#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>
#include <iostream> // cout
#include <vector>

#include "connector.h"
#include "ncScreen.h"


int main(int args, char *argv[])
{
    int input;
    std::vector<sData> playerData(5);

    if(args < 3)
    {
        std::cout << "No args" << std::endl;
        return 1;
    }

    NcScreen scr;
    Connector cn;



    cn.initPlayer(atoi(argv[1]), *argv[2]);

    cn.connectServer();

    scr.initNcScreen();


    while(input != 'q')
    {
    	usleep(10000);


        input = scr.getInput();

        cn.setCommand(input);

        cn.syncData();

        cn.getData(playerData);

        scr.printScreen(playerData);

    }


    cn.end();
    scr.exitNcScreen();
	return 0;
}

