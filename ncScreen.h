#pragma once

//#include <ncurses.h>
#include <vector>
//#include "connector.h" 



struct PrintData
{
	char skin;
	int x;
	int y;
};

struct StatusData
{
	int frameNum;
	int pwr;

};


class NcScreen
{
public:
	void initNcScreen();
	void printScreen(const std::vector<PrintData> &printObjects, StatusData &playerStatus, bool updScreen);
	int getInput();
	void exitNcScreen();




private:


};