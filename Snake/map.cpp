#include "map.h"
#include <Windows.h>

//ªÊ÷∆≥ı ºµÿÕº
void Map::PrintInitmap() {
	for (auto& a : initmap) {
		a.Print();
		Sleep(10);
	}
}