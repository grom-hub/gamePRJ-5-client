#include <ncurses.h>
#include <unistd.h> // usleep()
#include <cstdlib> // rand(), srand(), exit()
//#include <ctime> // time()
//#include <string>
//#include <vector>

#include "units.h"



int main()
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

    // соединение с сервером.


    Units unit('A', 3, 3);
	// сообщить серверу о создании персонжа.

    while(key != 'q')
    {
    	usleep(10000);

/////////////////// Вывод на экран.
    	clear();
    	unit.print();
    	refresh();
///////////////////

/////////////////// Проверка нажатых клавиш.
		key = getch(); 

		if (key == KEY_DOWN)
			//команда на сервер
		if (key == KEY_UP)
			//команда на сервер
		if (key == KEY_RIGHT)
			//команда на сервер
		if (key == KEY_LEFT)
			//команда на сервер
///////////////////

		// Получить координаты персонажа от сервера.


    }



    endwin();
	return 0;
}