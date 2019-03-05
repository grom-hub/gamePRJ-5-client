//#pragma once


struct uData
	{
	    int x;
	    int y;
	};


class Connector
{
public:
	Connector();
	void sendCommand(int command);
	int getX();
	int getY();




private:
	uData a;

};