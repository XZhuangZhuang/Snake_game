#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
public:
	Controller() : speed(200), key(1), score(0) {}//构造函数

	void Game();//游戏的一级循环
	int PlayGame();//游戏的二级循环

	void Start();//开始界面
	void Select();//难度选择界面
	void DrawGame();//绘制游戏界面
	int GameOver();//绘制游戏结束界面

	void UpdateScore(const int&);//更新分数
	void RewriteScore();//重绘分数
	int Menu();//绘制选择菜单
private:
	int speed;//速度
	int score;//分数
	int key;//难度
};


#endif