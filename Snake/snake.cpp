#include "snake.h"
#include <conio.h>//conio.h库文件定义了通过控制台进行数据输入和数据输出的函数，主要是一些用户通过按键盘产生的对应操作
#include "tools.h"
#include <iostream>


//绘制初始蛇身
void Snake::InitSnake() {
	for (auto& point : snake) {
		point.PrintCircular();//蛇身由圆形组成，绘制蛇身
	}
}

//蛇增长
void Snake::Move() {
	switch (direction)
	{
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	default:
		break;
	}
	SetColor(14);//设置蛇身颜色
	snake.back().PrintCircular();//绘制新的蛇头
}

//蛇普通移动
void Snake::NormalMove() {
	Move();
	snake.front().Clear();//清除蛇尾
	snake.pop_front();
}

bool Snake::NoOverEdge()//判断没有超出边界
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}

bool Snake::NoHitItself()//判断没有撞到自身
{
	std::deque<Point>::size_type cnt = 1;
	Point *head = new Point(snake.back().GetX(), snake.back().GetY());//获得头部坐标
	for (auto& point : snake) //如果整条蛇中与蛇头不相同的坐标不等于蛇长-1，则意味着蛇头碰撞到自身
	{
		if (!(point == *head))
			++cnt;
		else
			break;
	}
	delete head;
	if (cnt == snake.size())
		return true;
	else
		return false;
}
//改变蛇的前进方向
bool Snake::ChangeDirection()//改变方向
{
	/*
	char ch;
	//kbhit 是非阻塞函数，检测到用户按下某键时就会返回，若有则返回一个非0值，否则返回0
	if (_kbhit())//kbhit函数返回值为两个，需注意
	{
		//从控制台读取一个字符，但不显示在屏幕上
		//用ch=getch();会等待你按下任意键之后，把该键字符所对应的ASCII码赋给ch,再执行下面的语句。
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72://向上
				if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效
					direction = Direction::UP;
				break;
			case 80://向下
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75://向左
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77://向右
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;

		case 27://ESC---用于暂停
			return false;

		default:
			return true;

		}
	}
	return true;
	*/
	char ch;
	bool sign = true;
	//kbhit 是非阻塞函数，检测到用户按下某键时就会返回，若有则返回一个非0值，否则返回0
	while (_kbhit())//kbhit函数返回值为两个，需注意
	{
		//从控制台读取一个字符，但不显示在屏幕上
		//用ch=getch();会等待你按下任意键之后，把该键字符所对应的ASCII码赋给ch,再执行下面的语句。
		ch = _getch();
		switch (ch) {
		case 72://向上
			if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效
				direction = Direction::UP;
			break;
		case 80://向下
			if (direction != Direction::UP)
				direction = Direction::DOWN;
			break;
		case 75://向左
			if (direction != Direction::RIGHT)
				direction = Direction::LEFT;
			break;
		case 77://向右
			if (direction != Direction::LEFT)
				direction = Direction::RIGHT;
			break;
		case 27://ESC---用于暂停
			sign = false;
			break;
		default:
			break;
		}
	}
	return sign;
}
//获取食物
bool Snake::GetFood(const Food& cfood)//返回true表示获取到食物
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
		return true;
	else
		return false;
}

//获取限时食物
bool Snake::GetBigFood(Food& cfood)//返回true表示获取到限时食物
{
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		SetCursorPosition(1, 0);
		std::cout << "                                                            ";
		return true;
	}
	else
		return false;
}