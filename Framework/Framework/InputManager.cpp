#include "InputManager.h"
InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : Key(0){}
InputManager::~InputManager(){}

void InputManager::InputKey()
{
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

}
