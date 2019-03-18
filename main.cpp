#include <ncurses.h>
#include <unistd.h> // usleep()
#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>
#include <iostream> // cout
#include <vector>

#include "connector.h"
#include "ncScreen.h"


int main(int args, char *argv[])
{
	int key;
    std::vector<sData> playerData(5);

    if(args < 2)
    {
        std::cout << "No args" << std::endl;
        return 1;
    }

    NcScreen scr;
    Connector cn;



    cn.initPlayer(atoi(argv[1]), 'A');

    cn.connectServer();

    scr.initNcScreen();


    while(key != 'q')
    {
    	usleep(10000);

		key = getch(); 


		if (key == KEY_DOWN)
        {   
			cn.setCommand(1);
        }
		if (key == KEY_UP)
        {   
            cn.setCommand(2);	
        }
		if (key == KEY_RIGHT)
        {   
			cn.setCommand(3);
        }
		if (key == KEY_LEFT)
        {   
			cn.setCommand(4);
        }


        cn.syncData();
        cn.getData(playerData);


        scr.printScreen(playerData);

    }


    cn.end();
    scr.exitNcScreen();
	return 0;
}

