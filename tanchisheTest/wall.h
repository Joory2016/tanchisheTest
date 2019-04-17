#pragma once
#include <iostream>

using namespace std;

class Wall {

public:
	enum {
	ROW = 25,
	COL = 25
	}; 

	void initWall();
	void drawWall();
	void setWall(int x, int y, char c);
	char getWall(int x, int y);


private:
	char gameArray[ROW][COL];

};




