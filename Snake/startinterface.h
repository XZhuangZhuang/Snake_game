#pragma once
#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H

//该类用于实现开场动画
/*
第一部分实现首先是建立一个deque双端队列，用于存储点的对象，这些点就是组成蛇身的元素，
然后再用一个for循环将容器中的点依次打印出来，每打印一个点停顿一会，这样就达到了移动的效果。
全部打印完后就到了第二部分，这部分蛇的每次前进都是通过计算将要移动到的下一个点的坐标，
然后将这个点打印出来，与此同时将蛇尾，亦即queue中的首端点去掉，并擦除屏幕上该点颜色。
第三部分就直接依次从蛇尾擦除即可。
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

	void PrintFirst();//蛇从左边出现到完全出现的过程
	void PrintSecond();//蛇从左向右移动的过程
	void PrintThird();//蛇从接触右边到消失的过程
	void PrintText();//绘制更新位置后的文字
	void ClearText(); //将文字整体向右移动一格
	void Action();
private:
	std::deque<Point> startsnake;//开始动画中的蛇
	std::vector<Point> textsnake;//开始动画中的文字
	int speed;//动画的速度
};

#endif // !STARTINTERFACE_H
