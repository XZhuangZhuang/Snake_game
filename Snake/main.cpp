#include "controller.h"
#include <Windows.h>
#include <stdio.h>
int main()//�������
{
	//���ع��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬

	Controller c;//����һ��Controller��
	c.Game();//������Ϸѭ��
	return 0;
}
