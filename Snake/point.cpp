#include "point.h"
#include "tools.h"
#include <iostream>

//���������
void Point::Print() {
	SetCursorPosition(x, y);//���ù��λ��
	std::cout << "��";//���������
}

//���Բ��
void Point::PrintCircular() {
	SetCursorPosition(x, y);//���ù��λ��
	std::cout << "��";//���Բ��
}

//������
void Point::Clear() {
	SetCursorPosition(x, y);//���ù��λ��
	std::cout << "  ";//�ڸ�λ��������ո�
}

//�ı�����
void Point::ChangePosition(const int x, const int y) {
	this->x = x;
	this->y = y;
}