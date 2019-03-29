#pragma once

//#include <ncurses.h>
#include <vector>
#include "connector.h" // sData



struct PrintData
{
	char skin;
	int x;
	int y;
};


class NcScreen
{
public:
	void initNcScreen();
	void printScreen(const std::vector<PrintData> &printObjects);
	int getInput();
	void exitNcScreen();




private:


};