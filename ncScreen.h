//#pragma once

#include <vector>
#include "connector.h" // sData



struct toScreen
{
	char skin;
	int x;
	int y;
};



class NcScreen
{
public:
	void initNcScreen();
	void printScreen(std::vector<toScreen> &printObject);
	int getInput();
	void exitNcScreen();




private:


};