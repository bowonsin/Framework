#include "InputManager.h"
InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : Key(0){}
InputManager::~InputManager(){}

void InputManager::InputKey()
{
	Key = 0;
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))// 키 입력을 받는 함수 VK(VirtualKey_  방향)
		Key |= KEY_UP;
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
		Key |= KEY_DOWN;
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
		Key |= KEY_LEFT;
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
		Key |= KEY_RIGHT;
	if (GetAsyncKeyState(VK_SPACE))
		Key |= KEY_SPACE;
	if (GetAsyncKeyState(VK_RETURN))
		Key |= KEY_ENETER;
	if (GetAsyncKeyState(VK_CONTROL))
		Key |= KEY_CTRL;
	if (GetAsyncKeyState(VK_MENU))
		Key |= KEY_ALT;
	if (GetAsyncKeyState(VK_TAB))
		Key |= KEY_TAB;
	if (GetAsyncKeyState(VK_ESCAPE))
		Key |= KEY_ESCAPE;

}
/*
	if (GetAsyncKeyState(VK_UP))// 키 입력을 받는 함수 VK(VirtualKey_  방향)
		cout << "KEY_UP" << endl;
	if (GetAsyncKeyState(VK_DOWN))
		cout << "KEY_DOWN " << endl;
	if (GetAsyncKeyState(VK_LEFT) )
		cout << "KEY_LEFT " << endl;
	if (GetAsyncKeyState(VK_RIGHT))
		cout << "KEY_RIGHT " << endl;
	if (GetAsyncKeyState(VK_SPACE))
		cout << "KEY_SPACE " << endl;
	if (GetAsyncKeyState(VK_RETURN))
		cout << "KEY_ENETER " << endl;
	if (GetAsyncKeyState(VK_CONTROL))
		cout << "KEY_CTRL " << endl;
	if (GetAsyncKeyState(VK_MENU))
		cout << "KEY_ALT " << endl;
*/
