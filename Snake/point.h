#pragma once
#ifndef POINT_H
#define POINT_H

//point�����õ�Ķ���
class Point {
public:
	//�޲ι��캯��
	Point() {}

	//�вι��캯��
	Point(const int x, const int y) :x(x), y(y) {}

	//��������
	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }

	//�������
	void Print();
	//���Բ��
	void PrintCircular();
	//������
	void Clear();

	//�ı�����
	void ChangePosition(const int x, const int y);

	int GetX() { return this->x; }//���غ�����
	int GetY() { return this->y; }//����������

private:
	int x, y;//(x,y)��ʾ�������
};

#endif