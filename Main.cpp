#define _CRT_SECURE_NO_WARNINGS 1


#include "snake.h"		//�����Զ���ͷ�ļ�

int main()
{
	score_t score;

	srand(time(NULL));
	
	setinfo_if_visible(0);
	initSnake();
	initFood();
	initUI();
	initwall();

	score = playGame();
	initUI();
	
	//��ʾ����
	printf("��ķ�����%d\n", score);

	system("pause");

	return 0;
}





