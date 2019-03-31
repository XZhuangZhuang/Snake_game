#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
public:
	Controller() : speed(200), key(1), score(0) {}//���캯��

	void Game();//��Ϸ��һ��ѭ��
	int PlayGame();//��Ϸ�Ķ���ѭ��

	void Start();//��ʼ����
	void Select();//�Ѷ�ѡ�����
	void DrawGame();//������Ϸ����
	int GameOver();//������Ϸ��������

	void UpdateScore(const int&);//���·���
	void RewriteScore();//�ػ����
	int Menu();//����ѡ��˵�
private:
	int speed;//�ٶ�
	int score;//����
	int key;//�Ѷ�
};


#endif