#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
#include "point.h"
#include "food.h"


class Food;
class Snake{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };//枚举方向

	Snake() {//构造函数，初始化蛇的位置和前进方向
		snake.emplace_back(14, 8);
		snake.emplace_back(15, 8);
		snake.emplace_back(16, 8);
		direction = Direction::DOWN;
	}
	void InitSnake();//绘制初始蛇身
	void Move();//蛇增长
	void NormalMove();//蛇普通移动
	bool NoOverEdge();//判断蛇身是否撞上边界
	bool NoHitItself();//判断蛇身是否撞上自身
	bool ChangeDirection();//改变蛇的前进方向
	bool GetFood(const Food&);//获取食物
	bool GetBigFood(Food&);//获取限时事物
private:
	std::deque<Point> snake;//蛇身
	Direction direction;//前进方向
	friend class Food;//将Food类置为友元，以便访问其私有元素
};
#endif // SNAKE_H
