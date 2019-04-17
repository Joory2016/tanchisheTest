#pragma once
#include "wall.h"
#include <iostream>
using namespace std;

class Food {

public:
	Food(Wall &tempWall);
	void setFood();

private:
	int foodX;
	int foodY;
	Wall &wall;
};


