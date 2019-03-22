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


struct sData
{
    int id;
    int x;
    int y;
    char skin;
    int command;
};


int main(int args, char *argv[])
{
    int input;
    char sendBuf[1024];
    char recvBuf[1024];
    std::vector<toScreen> printObject(5);
    std::vector<sData> serverData(5);


    if(args < 3)
    {
        std::cout << "No args" << std::endl;
        return 1;
    }

    NcScreen scr;
    Connector cn;




    cn.connectServer();

    scr.initNcScreen();


    while(input != 'q')
    {
    	usleep(10000);


        input = scr.getInput();


        sendBuf[0] = 1;


        cn.syncData(sendBuf, recvBuf);


        std::memcpy(serverData.data(), &recvBuf[2], serverData.size()*sizeof(sData));

        // break;

        for (int i = 0; i < 5; ++i)
        {
            printObject[i].skin = serverData[i].skin;
            printObject[i].x = serverData[i].x;
            printObject[i].y = serverData[i].y;
        }


        scr.printScreen(printObject);

    }


    cn.end();
    scr.exitNcScreen();
	return 0;
}

