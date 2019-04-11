#pragma once

//#include <ncurses.h>
#include <vector>
#include <string>
//#include "connector.h" 
//#include "playerController.h" // CreateData


struct CreateData
{
	char skin;
	std::string planet;
};

struct PrintData
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
	std::vector<PrintData> printUnits;
	std::vector<PrintData> printPwrPoints;
	std::vector<PrintData> printStars;
    PrintStatusData printStatus;
    
    bool updScreen;
	int refreshCount;

	void initNcScreen();
	int mainMenu(CreateData &createData);
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