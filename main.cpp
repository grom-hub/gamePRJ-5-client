#include <ncurses.h>
#include <unistd.h> // usleep()
#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>
#include <vector>

#include "connector.h"



int main(int args, char *argv[])
{
	int key;


	if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    clear();
    refresh();

    Connector cn;
    std::vector<sData> playerData(5);


    cn.initPlayer(atoi(argv[1]), 'A');

    cn.connectServer();

    while(key != 'q')
    {
    	usleep(10000);


/////////////////// Проверка нажатых клавиш.
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
///////////////////


        cn.syncData();
        cn.getData(playerData);


/////////////////// Вывод на экран.
        clear();
        for (int i = 0; i < 5; ++i)
        {
            mvaddch(playerData[i].uX, playerData[i].uY, playerData[i].uSkin);
        }
        refresh();
///////////////////
    }


    cn.end();
    endwin();
	return 0;
}

