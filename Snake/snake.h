#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
#include "point.h"
#include "food.h"


class Food;
class Snake{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };//ö�ٷ���

	Snake() {//���캯������ʼ���ߵ�λ�ú�ǰ������
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8);
		snake.emplace_back(16, 8);
		direction = Direction::DOWN;
	}
	void InitSnake();//���Ƴ�ʼ����
	void Move();//������
	void NormalMove();//����ͨ�ƶ�
	bool NoOverEdge();//�ж������Ƿ�ײ�ϱ߽�
	bool NoHitItself();//�ж������Ƿ�ײ������
	bool ChangeDirection();//�ı��ߵ�ǰ������
	bool GetFood(const Food&);//��ȡʳ��
	bool GetBigFood(Food&);//��ȡ��ʱ����
private:
	std::deque<Point> snake;//����
	Direction direction;//ǰ������
	friend class Food;//��Food����Ϊ��Ԫ���Ա������˽��Ԫ��
};
#endif // SNAKE_H
