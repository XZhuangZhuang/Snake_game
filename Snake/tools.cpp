#include "tools.h"
#include <Windows.h>
#include <stdio.h>

//���ô��ڴ�С
void SetWindowSize(int cols, int lines) {
	system("title Snake");//���ô��ڱ���
	char cmd[30];
	//sprintf_sָ�����ַ�����ʽ�������Ҫ�����ǰѸ�ʽ��������д��ĳ���ַ����С�
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
	system(cmd); //system(mode con cols = 88 lines = 88)���ô��ڿ�Ⱥ͸߶�
}

//���ù��λ��
void SetCursorPosition(const int x, const int y) {
	COORD position;//COORD ��������һ����������������¼���꣬���Ͻ����꣨0��0��
	position.X = x * 2;
	position.Y = y;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����豸�ľ��
	SetConsoleCursorPosition(hOut, position);//���ÿ���̨���λ��
}

//�����ı���ɫ
void SetColor(int colorID)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����豸�ľ��
	SetConsoleTextAttribute(hOut, colorID);//�����ı���ɫ
}

//�����ı�����ɫ
void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}
