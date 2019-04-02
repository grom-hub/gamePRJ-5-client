#pragma once

//#include <ncurses.h>
#include <vector>
//#include "connector.h" 



struct PrintObjectData
{
	char skin;
	int id;
	int x;
	int y;
};

struct PrintStatusData
{
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
	int getInput();
	void printScreen(int &myid);
	void exitNcScreen();




private:
	void setCam(int &myid);
	int row;
    int col;
    int centerX;
    int centerY;
	int camX;
	int camY;

};