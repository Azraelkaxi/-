#define _CRT_SECURE_NO_WARNINGS 1


#include "snake.h"		//�����Զ���ͷ�ļ�

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
	
	//��ʾ����
	printf("��ķ�����%d\n", score);

	system("pause");

	return 0;
}





