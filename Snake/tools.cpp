#include "tools.h"
#include <Windows.h>
#include <stdio.h>

//设置窗口大小
void SetWindowSize(int cols, int lines) {
	system("title Snake");//设置窗口标题
	char cmd[30];
	//sprintf_s指的是字符串格式化命令，主要功能是把格式化的数据写入某个字符串中。
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
	system(cmd); //system(mode con cols = 88 lines = 88)设置窗口宽度和高度
}

//设置光标位置
void SetCursorPosition(const int x, const int y) {
	COORD position;//COORD 可以理解成一个链表，可以用来记录坐标，左上角坐标（0，0）
	position.X = x * 2;
	position.Y = y;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取输出设备的句柄
	SetConsoleCursorPosition(hOut, position);//设置控制台光标位置
}

//设置文本颜色
void SetColor(int colorID)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取输出设备的句柄
	SetConsoleTextAttribute(hOut, colorID);//设置文本颜色
}

//设置文本背景色
void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}
