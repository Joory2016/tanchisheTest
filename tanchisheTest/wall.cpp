#include "pch.h"
#include "wall.h"
#include <iostream>
using namespace std;

void Wall::initWall() {
	for(int i=0;i<ROW;i++)
		for (int j = 0; j < COL; j++) {
			if (j == 0 || i == 0 || j == COL - 1 || i == ROW - 1)
				gameArray[i][j] = '*';
			else
				gameArray[i][j] = ' ';
		}


}

void Wall::drawWall() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << gameArray[i][j] << " ";
		}

		if (i == 6)
			cout << "   " << "create by Rui";
		if (i == 8)
			cout << "   " << "up: w";
		if (i == 10)
			cout << "   " << "down: s";
		if (i == 12)
			cout << "   " << "right: d";
		if (i == 14)
			cout << "   " << "left: a";

		cout << endl;
	}

}


void Wall::setWall(int x, int y, char c) {
	gameArray[x][y] = c;

}

char Wall::getWall(int x, int y) {
	return gameArray[x][y];
}