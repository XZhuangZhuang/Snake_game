#pragma once
#ifndef TOOLS_H
#define TOOLS_H

//Tools工具类主要是用于设置光标的位置以及输出文字的颜色
void SetWindowSize(int cols, int lines);//设置窗口大小
void SetCursorPosition(const int x, const int y);//设置光标位置
void SetColor(int colorId);//设置文本颜色
void SetBackColor();//设置文本背景颜色
#endif // !TOOLS_H
