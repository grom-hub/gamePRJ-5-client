#pragma once

//#include <ncurses.h>
#include <vector>
//#include "connector.h" 



struct PrintObjectData
{
	char skin;
	int x;
	int y;
};

struct PrintStatusData
{
	int frameNum;
	int pwr;

};


class NcScreen
{
public:
	std::vector<PrintObjectData> printObjects;
    PrintStatusData printStatus;
    bool updScreen;
	int refreshCount;

	void initNcScreen();
	void printScreen();
	int getInput();
	void exitNcScreen();




private:

};