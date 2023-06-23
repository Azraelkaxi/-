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

//蛇身体
struct body_t
{
	int X;		//表示蛇身体该格的X坐标
	int Y;		//表示蛇身体该格的Y坐标
};

//蛇对象
struct snake_t
{
	struct body_t body[WIDE * HIGH];
	int size;
};

//食物对象
struct food_t
{
	int X;
	int Y;
};

//分数
typedef int score_t;

//函数声明 
// 
//初始化蛇对象
void initSnake();

//初始化食物对象
void initFood();

//初始化交互界面
void initUI();

//开始游戏
int playGame();

void haha();

#endif // !__SNAKE_H__

