#include "point.h"
#include "tools.h"
#include <iostream>

//输出正方形
void Point::Print() {
	SetCursorPosition(x, y);//设置光标位置
	std::cout << "■";//输出正方形
}

//输出圆形
void Point::PrintCircular() {
	SetCursorPosition(x, y);//设置光标位置
	std::cout << "●";//输出圆形
}

//清除输出
void Point::Clear() {
	SetCursorPosition(x, y);//设置光标位置
	std::cout << "  ";//在该位置上输出空格
}

//改变坐标
void Point::ChangePosition(const int x, const int y) {
	this->x = x;
	this->y = y;
}