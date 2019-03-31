#pragma once
#ifndef POINT_H
#define POINT_H

//point类设置点的对象
class Point {
public:
	//无参构造函数
	Point() {}

	//有参构造函数
	Point(const int x, const int y) :x(x), y(y) {}

	//相等运算符
	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }

	//输出方块
	void Print();
	//输出圆形
	void PrintCircular();
	//清除输出
	void Clear();

	//改变坐标
	void ChangePosition(const int x, const int y);

	int GetX() { return this->x; }//返回横坐标
	int GetY() { return this->y; }//返回纵坐标

private:
	int x, y;//(x,y)表示点的坐标
};

#endif