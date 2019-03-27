#include <ncurses.h>
#include <cstdlib> // rand(), srand(), exit()
#include <vector>

#include "ncScreen.h"




void NcScreen::initNcScreen()
{
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

}


int NcScreen::getInput()
{
    int key = getch();

    switch(key)
    {
        case KEY_DOWN:
            return 1;
            break;
        case KEY_UP:
            return 2;
            break;
        case KEY_RIGHT:
            return 3;
            break;
        case KEY_LEFT:
            return 4;
            break;
        case 'q':
            return 'q';
            break;
        default:
            return 0;
    }

}


void NcScreen::printScreen(const std::vector<printData> &printObjects)
{
    clear();
    for (int i = 0; i < printObjects.size(); ++i)
    {
        mvaddch(printObjects[i].x, printObjects[i].y, printObjects[i].skin);
    }
    mvaddstr(0, 1, "PWR = ");
    mvaddstr(1, 1, "Status_2 = ");
    //refresh();

}


void NcScreen::exitNcScreen()
{
	endwin();
}