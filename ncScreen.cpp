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
            return 9;
            break;
        default:
            return 0;
    }

}



void NcScreen::printScreen(int &myid)
{

    if(updScreen)
    {
        updScreen = false;
        // refreshCount ++;

        setCam(myid);

        clear();
        for (int i = 0; i < printObjects.size(); ++i)
        {
            mvaddch(printObjects[i].x + camX, printObjects[i].y + camY, printObjects[i].skin);
        }

        mvprintw(0, 1, "PWR = %d", printStatus.pwr);
        // mvprintw(1, 1, "Refresh count = %d", refreshCount);
        //refresh();
    }

}



void NcScreen::setCam(int &myid)
{
    getmaxyx(stdscr, row, col);
    centerY = col / 2;
    centerX = row / 2;

    for(int i = 0; i < printObjects.size(); ++i)
    {
        if(printObjects[i].id == myid)
        {
            camX = centerX - printObjects[i].x;
            camY = centerY - printObjects[i].y;
            break;
        }
    }
}



void NcScreen::exitNcScreen()
{
	endwin();
}