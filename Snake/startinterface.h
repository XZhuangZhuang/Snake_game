#pragma once
#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H

//��������ʵ�ֿ�������
/*
��һ����ʵ�������ǽ���һ��deque˫�˶��У����ڴ洢��Ķ�����Щ�������������Ԫ�أ�
Ȼ������һ��forѭ���������еĵ����δ�ӡ������ÿ��ӡһ����ͣ��һ�ᣬ�����ʹﵽ���ƶ���Ч����
ȫ����ӡ���͵��˵ڶ����֣��ⲿ���ߵ�ÿ��ǰ������ͨ�����㽫Ҫ�ƶ�������һ��������꣬
Ȼ��������ӡ���������ͬʱ����β���༴queue�е��׶˵�ȥ������������Ļ�ϸõ���ɫ��
�������־�ֱ�����δ���β�������ɡ�
*/
#include <deque>
#include <vector>
#include "point.h"

class StartInterface {
public:
	StartInterface() :speed(35) {
		startsnake.emplace_back(Point(0, 14));
		startsnake.emplace_back(Point(1, 14));
		startsnake.emplace_back(Point(2, 15));
		startsnake.emplace_back(Point(3, 16));
		startsnake.emplace_back(Point(4, 17));
		startsnake.emplace_back(Point(5, 18));
		startsnake.emplace_back(Point(6, 17));
		startsnake.emplace_back(Point(7, 16));
		startsnake.emplace_back(Point(8, 15));
		startsnake.emplace_back(Point(9, 14));

		textsnake.emplace_back(Point(-26, 14));//S
		textsnake.emplace_back(Point(-25, 14));
		textsnake.emplace_back(Point(-27, 15));
		textsnake.emplace_back(Point(-26, 16));
		textsnake.emplace_back(Point(-25, 17));
		textsnake.emplace_back(Point(-27, 18));
		textsnake.emplace_back(Point(-26, 18));

		textsnake.emplace_back(Point(-23, 14));//N
		textsnake.emplace_back(Point(-23, 15));
		textsnake.emplace_back(Point(-23, 16));
		textsnake.emplace_back(Point(-23, 17));
		textsnake.emplace_back(Point(-23, 18));
		textsnake.emplace_back(Point(-22, 15));
		textsnake.emplace_back(Point(-21, 16));
		textsnake.emplace_back(Point(-20, 17));
		textsnake.emplace_back(Point(-19, 14));
		textsnake.emplace_back(Point(-19, 15));
		textsnake.emplace_back(Point(-19, 16));
		textsnake.emplace_back(Point(-19, 17));
		textsnake.emplace_back(Point(-19, 18));

		textsnake.emplace_back(Point(-17, 18));//A
		textsnake.emplace_back(Point(-16, 17));
		textsnake.emplace_back(Point(-15, 16));
		textsnake.emplace_back(Point(-14, 15));
		textsnake.emplace_back(Point(-14, 16));
		textsnake.emplace_back(Point(-13, 14));
		textsnake.emplace_back(Point(-13, 16));
		textsnake.emplace_back(Point(-12, 15));
		textsnake.emplace_back(Point(-12, 16));
		textsnake.emplace_back(Point(-11, 16));
		textsnake.emplace_back(Point(-10, 17));
		textsnake.emplace_back(Point(-9, 18));

		textsnake.emplace_back(Point(-7, 14));//K
		textsnake.emplace_back(Point(-7, 15));
		textsnake.emplace_back(Point(-7, 16));
		textsnake.emplace_back(Point(-7, 17));
		textsnake.emplace_back(Point(-7, 18));
		textsnake.emplace_back(Point(-6, 16));
		textsnake.emplace_back(Point(-5, 15));
		textsnake.emplace_back(Point(-5, 17));
		textsnake.emplace_back(Point(-4, 14));
		textsnake.emplace_back(Point(-4, 18));

		textsnake.emplace_back(Point(-2, 14));//E
		textsnake.emplace_back(Point(-2, 15));
		textsnake.emplace_back(Point(-2, 16));
		textsnake.emplace_back(Point(-2, 17));
		textsnake.emplace_back(Point(-2, 18));
		textsnake.emplace_back(Point(-1, 14));
		textsnake.emplace_back(Point(-1, 16));
		textsnake.emplace_back(Point(-1, 18));
		textsnake.emplace_back(Point(0, 14));
		textsnake.emplace_back(Point(0, 16));
		textsnake.emplace_back(Point(0, 18));
	}

	void PrintFirst();//�ߴ���߳��ֵ���ȫ���ֵĹ���
	void PrintSecond();//�ߴ��������ƶ��Ĺ���
	void PrintThird();//�ߴӽӴ��ұߵ���ʧ�Ĺ���
	void PrintText();//���Ƹ���λ�ú������
	void ClearText(); //���������������ƶ�һ��
	void Action();
private:
	std::deque<Point> startsnake;//��ʼ�����е���
	std::vector<Point> textsnake;//��ʼ�����е�����
	int speed;//�������ٶ�
};

#endif // !STARTINTERFACE_H
