#pragma once

#include <vector>
#include "connector.h" // sData



struct unitBox
{
    int id;
    char skin;
    int x;
    int y;
};


class NcScreen
{
public:
	void initNcScreen();
	void printScreen(const std::vector<unitBox> &units);
	int getInput();
	void exitNcScreen();




private:


};