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


    // if (key == KEY_DOWN)
    // {   
    //     return 1;
    // }
    // if (key == KEY_UP)
    // {   
    //     return 2;   
    // }
    // if (key == KEY_RIGHT)
    // {   
    //     return 3;
    // }
    // if (key == KEY_LEFT)
    // {   
    //     return 4;
    // }
    // if (key == 'q')
    // {
    //     return 'q';
    // }
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