#include "snake.h"

#define _CRT_SECURE_NO_WARNINGS 1

snake_t snake;
food_t food;
score_t score = 0;


//��ʼ���߶���
void initSnake()
{
	COORD pos_snake;

	snake.size = 2;						//��ʼ���߳���

	snake.body[0].X = WIDE / 2;			//��ʼ����ͷ
	snake.body[0].Y = HIGH / 2;

	snake.body[1].X = WIDE / 2 - 1;		//��ʼ��������
	snake.body[1].Y = HIGH / 2;

	
}

//��ʼ��ʳ�����
void initFood()
{
	COORD pos_food;

	food.X = rand() % WIDE + 1;	//1-70
	food.Y = rand() % HIGH + 1;	//1-25

}

//��ʼ����������
void initUI()
{
	COORD pos_snake, pos_food, pos;
	int i;

	//����

	for (i = 0; i < snake.size; i++)
	{
		pos_snake.X = snake.body[i].X;
		pos_snake.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos_snake);
		if (i == 0)
			printf("@");
		else
			printf("o");
	}

	//��ʳ��
	pos_food.X = food.X;
	pos_food.Y = food.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos_food);
	printf("#");

	//��ǽ��
	pos.X = 0;
	pos.Y = 0;
	for (size_t i = 0; i <= WIDE; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf("N");
		pos.X++;
	}
	pos.X = 0;
	pos.Y = HIGH + 1;
	for (size_t i = 0; i <= WIDE; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf("N");
		pos.X++;
	}
	pos.X = 0;
	pos.Y = 0;
	for (size_t i = 0; i <= HIGH + 1; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf("N");
		pos.Y++;
	}
	pos.X = WIDE + 1;
	pos.Y = 0;
	for (size_t i = 0; i <= HIGH + 1; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf("N");
		pos.Y++;
	}

	//���ص����0
	pos_food.X = 0;
	pos_food.Y = HIGH + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos_food);

}

//��ʼ��Ϸ
int playGame()
{
	char key = 'd';
	char pkey = 'd';
	int kx = 0, ky = 0;

	//�ж���ײǽ
	while (snake.body[0].X > 0 && snake.body[0].X <= WIDE && snake.body[0].Y > 0 && snake.body[0].Y <= HIGH)
	{
		//��������
		initUI();

		//���ռ�������
		if (_kbhit())
		{
			key = _getch();
		}

		//�������밴��
		switch (key)
		{
		case 'w':
			if (pkey == 's')
				break;
			kx = 0;
			ky = -1;
			pkey = key;
			break;

		case 'a':
			if (pkey == 'd')
				break;
			kx = -1;
			ky = 0;
			pkey = key;
			break;

		case 's':
			if (pkey == 'w')
				break;
			kx = 0;
			ky = 1;
			pkey = key;
			break;

		case 'd':
			if (pkey == 'a')
				break;
			kx = 1;
			ky = 0;
			pkey = key;
			break;
		}

		//ײ����
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
				return score;
		}

		//��ͷײʳ��
		if (snake.body[0].X == food.X && snake.body[0].Y == food.Y)
		{
			initFood();		//ʳ����ʧ
			snake.size++;	//��������
			score += 10;	//�ӷ�

			//����
		}

		//�ߵ��ƶ�
		//�����ƶ�
		for (size_t i = snake.size - 1; i > 0; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;
		}
		//��ͷ�ƶ�
		snake.body[0].X += kx;
		snake.body[0].Y += ky;

		//�޸�һλ�������ַ�
		Sleep(100);

		system("cls");
	}

	
	return score;
}

void haha()
{
	char str[] = "I love you!";
	char* token, * context = NULL;
	for (token = strtok_s(str, " ", &context); token != NULL; token = strtok_s(NULL, " ", &context))
	{
		printf("%s\n", token);
	}
}

