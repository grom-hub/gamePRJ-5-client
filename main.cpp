#include <ncurses.h>
#include <unistd.h> // usleep()
#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>
//#include <vector>

#include "units.h"
#include "connector.h"



int main()
{
	int key;

    int uX;
    int uY;

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


    Connector cr;

    // соединение с сервером.


    Units unit('A', 3, 3);
	// сообщить серверу о создании персонжа.

    while(key != 'q')
    {
    	usleep(10000);

/////////////////// Вывод на экран.
    	clear();
    	//unit.print();
        mvaddch(uX, uY, 'A');
    	refresh();
///////////////////

/////////////////// Проверка нажатых клавиш.
		key = getch(); 

		if (key == KEY_DOWN)
        {   
			cr.sendCommand(1);
        }
		if (key == KEY_UP)
        {   
			cr.sendCommand(2);
        }
		if (key == KEY_RIGHT)
        {   
			cr.sendCommand(3);
        }
		if (key == KEY_LEFT)
        {   
			cr.sendCommand(4);
        }
///////////////////

		// Получить координаты персонажа от сервера.
        uX = cr.getX();
        uY = cr.getY();

    }



    endwin();
	return 0;
}