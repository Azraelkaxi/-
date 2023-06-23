#pragma once

#ifndef __SNAKE_H__

#define __SNAKE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define WIDE 70
#define HIGH 25

//������
struct body_t
{
	int X;		//��ʾ������ø��X����
	int Y;		//��ʾ������ø��Y����
};

//�߶���
struct snake_t
{
	struct body_t body[WIDE * HIGH];
	int size;
};

//ʳ�����
struct food_t
{
	int X;
	int Y;
};

//����
typedef int score_t;

//�������� 
// 
//��ʼ���߶���
void initSnake();

//��ʼ��ʳ�����
void initFood();

//��ʼ����������
void initUI();

//��ʼ��Ϸ
int playGame();

void haha();

#endif // !__SNAKE_H__

