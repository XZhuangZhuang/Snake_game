#include "controller.h"
#include <Windows.h>
#include <stdio.h>
int main()//程序入口
{
	//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

	Controller c;//声明一个Controller类
	c.Game();//整个游戏循环
	return 0;
}
