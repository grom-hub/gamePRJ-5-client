#pragma once

//#include <ncurses.h>
#include <vector>
#include "connector.h" // sData



// struct unitBox
// {
//     int id;
//     char skin;
//     int x;
//     int y;
// };

struct printData
{
	char skin;
	int x;
	int y;
};


class NcScreen
{
public:
	void initNcScreen();
	void printScreen(const std::vector<printData> &printObjects);
	int getInput();
	void exitNcScreen();




private:


};