// tanchisheTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int main()
{
	system("title 打飞机");
	Wall wall;
	wall.initWall();
	Food food(wall);
	Snake snake(wall,food);
	snake.initSnake();
//	wall.setWall(5, 4, '=');
//	wall.setWall(5, 3, '=');
	food.setFood();

//	snake.move('s');
//	snake.move('s');
//	snake.move('s');
//	snake.move('s');

//	snake.delPoint();

	bool isDead = false;


	wall.drawWall();

	while (!isDead) {


		char key = _getch();
		if (key == '\0')
			continue;

		do {
			if (snake.move(key) == true) {
				system("cls");
				wall.drawWall();
				Sleep(200);
			}
			else {
				isDead = true;
				break;
			}
		} while (_kbhit());


	}

    std::cout << "Hello World!\n"; 

	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
