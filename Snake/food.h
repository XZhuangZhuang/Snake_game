#pragma once
#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

class Snake;
class Food {
public:
	//���캯��
	Food() :cnt(0), x(0), y(0), big_x(0), big_y(0), flash_flag(false), big_flag(false), progress_bar(0) {}

	//������ͨʳ��
	void DrawFood(Snake&);

	//������ʱʳ��
	void DrawBigFood(Snake&);//���ƽ�������

	//��˸��ʱʳ��
	void FlashBigFood();

	int GetCnt() { return cnt; }
	bool GetBigFlag() { return big_flag; }
	int GetProgressBar() { return progress_bar; }

private:
	int cnt;//����������ÿ����ͻ����һ����ʱʳ��
	int x, y;//��ͨʳ�������
	int big_x, big_y;//��ʱʳ�������
	bool flash_flag;//��˸���
	bool big_flag;//�Ƿ�����ʱʳ����
	int progress_bar;//��ʱʳ��Ľ�����
	friend class Snake;
};


#endif