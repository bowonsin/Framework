#pragma once
#include "Headers.h"
class CursorManager
{
public:
	static void SetCursorPosition(float _x, float _y)
	{// Ŀ���� ��ġ�� �ٲ��ִ� �Լ� 
		COORD pos = { (SHORT)_x,(SHORT)_y };
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),pos);
	}

	static void Draw(float _x, float _y,string _str)
	{// Ŀ���� ��ġ�� �ٲ��ִ� �Լ� 
		SetCursorPosition(_x, _y);
		cout << _str;
	}
};

