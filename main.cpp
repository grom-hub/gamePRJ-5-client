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


// Типы буферов: 1 - пустой, 2 - создать персонажа, 3 - комманда персонажу от клиента, 4 - пакет персонажей от сервера


struct sData
{
    int id;
    int x;
    int y;
    char skin;
    int command;
};

struct crtData
{
    int id;
    char skin;
};





int main(int args, char *argv[])
{
    int myid;
    int input;
    char sendBuf[1024];
    char recvBuf[1024];
    std::vector<toScreen> printObject(5);
    std::vector<sData> serverData(5);
    crtData createData;
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




    cn.connectServer();

    // Создать персонажа 
    // (отправить на сервер команду создания персонажа и скин. Получить id.)

    createData.skin = 'A';

    sSize = sizeof(crtData);
    sendBuf[0] = 2;
    std::memcpy(&sendBuf[2], &createData, sSize);


    cn.syncData(sendBuf, sSize, recvBuf);


    if(recvBuf[0] == 4)
    {
        rSize = recvBuf[1];
        units.resize(rSize);
        std::memcpy(units.data(), &recvBuf[2], sizeof(unitBox) * rSize);
        myid = units[rSize].id;
    }

    //return 0;

    scr.initNcScreen();


    while(input != 'q')
    {
    	usleep(100000);


        input = scr.getInput();

        // отправлять на сервер id, комманду.

        sendBuf[0] = 1;
        sSize = 1;

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

