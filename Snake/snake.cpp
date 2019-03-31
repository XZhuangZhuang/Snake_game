#include "snake.h"
#include <conio.h>//conio.h���ļ�������ͨ������̨���������������������ĺ�������Ҫ��һЩ�û�ͨ�������̲����Ķ�Ӧ����
#include "tools.h"
#include <iostream>


//���Ƴ�ʼ����
void Snake::InitSnake() {
	for (auto& point : snake) {
		point.PrintCircular();//������Բ����ɣ���������
	}
}

//������
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
	SetColor(14);//����������ɫ
	snake.back().PrintCircular();//�����µ���ͷ
}

//����ͨ�ƶ�
void Snake::NormalMove() {
	Move();
	snake.front().Clear();//�����β
	snake.pop_front();
}

bool Snake::NoOverEdge()//�ж�û�г����߽�
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}

bool Snake::NoHitItself()//�ж�û��ײ������
{
	std::deque<Point>::size_type cnt = 1;
	Point *head = new Point(snake.back().GetX(), snake.back().GetY());//���ͷ������
	for (auto& point : snake) //���������������ͷ����ͬ�����겻�����߳�-1������ζ����ͷ��ײ������
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
//�ı��ߵ�ǰ������
bool Snake::ChangeDirection()//�ı䷽��
{
	/*
	char ch;
	//kbhit �Ƿ�������������⵽�û�����ĳ��ʱ�ͻ᷵�أ������򷵻�һ����0ֵ�����򷵻�0
	if (_kbhit())//kbhit��������ֵΪ��������ע��
	{
		//�ӿ���̨��ȡһ���ַ���������ʾ����Ļ��
		//��ch=getch();��ȴ��㰴�������֮�󣬰Ѹü��ַ�����Ӧ��ASCII�븳��ch,��ִ���������䡣
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72://����
				if (direction != Direction::DOWN)//��������뵱ǰ�˶������෴����Ч
					direction = Direction::UP;
				break;
			case 80://����
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75://����
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77://����
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;

		case 27://ESC---������ͣ
			return false;

		default:
			return true;

		}
	}
	return true;
	*/
	char ch;
	bool sign = true;
	//kbhit �Ƿ�������������⵽�û�����ĳ��ʱ�ͻ᷵�أ������򷵻�һ����0ֵ�����򷵻�0
	while (_kbhit())//kbhit��������ֵΪ��������ע��
	{
		//�ӿ���̨��ȡһ���ַ���������ʾ����Ļ��
		//��ch=getch();��ȴ��㰴�������֮�󣬰Ѹü��ַ�����Ӧ��ASCII�븳��ch,��ִ���������䡣
		ch = _getch();
		switch (ch) {
		case 72://����
			if (direction != Direction::DOWN)//��������뵱ǰ�˶������෴����Ч
				direction = Direction::UP;
			break;
		case 80://����
			if (direction != Direction::UP)
				direction = Direction::DOWN;
			break;
		case 75://����
			if (direction != Direction::RIGHT)
				direction = Direction::LEFT;
			break;
		case 77://����
			if (direction != Direction::LEFT)
				direction = Direction::RIGHT;
			break;
		case 27://ESC---������ͣ
			sign = false;
			break;
		default:
			break;
		}
	}
	return sign;
}
//��ȡʳ��
bool Snake::GetFood(const Food& cfood)//����true��ʾ��ȡ��ʳ��
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
		return true;
	else
		return false;
}

//��ȡ��ʱʳ��
bool Snake::GetBigFood(Food& cfood)//����true��ʾ��ȡ����ʱʳ��
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