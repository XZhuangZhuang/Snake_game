#include "map.h"
#include <Windows.h>

//���Ƴ�ʼ��ͼ
void Map::PrintInitmap() {
	for (auto& a : initmap) {
		a.Print();
		Sleep(10);
	}
}