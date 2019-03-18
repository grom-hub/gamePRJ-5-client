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


void NcScreen::printScreen(std::vector<sData> &playerData)
{
    clear();
    for (int i = 0; i < 5; ++i)
    {
        mvaddch(playerData[i].uX, playerData[i].uY, playerData[i].uSkin);
    }
    refresh();
}


void NcScreen::exitNcScreen()
{
	endwin();
}