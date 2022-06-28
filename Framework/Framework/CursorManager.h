#pragma once
#include "Headers.h"
class CursorManager
{
public:
	static void SetCursorPosition(float _x, float _y)
	{// 커서의 위치를 바꿔주는 함수 
		COORD pos = { (SHORT)_x,(SHORT)_y };
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),pos);
	}

	static void Draw(float _x, float _y,string _str)
	{// 커서의 위치를 바꿔주는 함수 
		SetCursorPosition(_x, _y);
		cout << _str;
	}
};

