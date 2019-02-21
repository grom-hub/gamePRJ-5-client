//#pragma once


class Units
{
public:
	Units(char p1, int p2, int p3);
	~Units();
	void moveX(int p1);
	void moveY(int p1);
	int getX(int p1);
	int getY(int p1);
	void print();




private:
	char pSkin;
	int pX;
	int pY;
};