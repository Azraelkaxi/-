#define _CRT_SECURE_NO_WARNINGS 1


#include "snake.h"		//引入自定义头文件

int main()
{
	score_t score;

	srand(time(NULL));
	
	initSnake();
	initFood();
	initUI();
	//haha();

	score = playGame();
	initUI();
	
	//显示分数
	printf("你的分数是%d\n", score);

	system("pause");

	return 0;
}





