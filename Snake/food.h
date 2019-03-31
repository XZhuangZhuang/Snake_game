#pragma once
#ifndef FOOD_H
#define FOOD_H

#include "snake.h"

class Snake;
class Food {
public:
	//构造函数
	Food() :cnt(0), x(0), y(0), big_x(0), big_y(0), flash_flag(false), big_flag(false), progress_bar(0) {}

	//绘制普通食物
	void DrawFood(Snake&);

	//绘制限时食物
	void DrawBigFood(Snake&);//绘制奖励事物

	//闪烁限时食物
	void FlashBigFood();

	int GetCnt() { return cnt; }
	bool GetBigFlag() { return big_flag; }
	int GetProgressBar() { return progress_bar; }

private:
	int cnt;//用来计数，每五个就会出现一次限时食物
	int x, y;//普通食物的坐标
	int big_x, big_y;//限时食物的坐标
	bool flash_flag;//闪烁标记
	bool big_flag;//是否有限时食物标记
	int progress_bar;//限时食物的进度条
	friend class Snake;
};


#endif