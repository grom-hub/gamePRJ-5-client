// #pragma once


#include "connector.h"


struct crtData
{
    int id;
    char skin;
};


class PlayerController
{
public:
	int createPlayer(Connector &cn);




private:
	crtData createData;

};