#pragma once
#include "Headers.h"
class InputManager
{
private:
	InputManager();
	static InputManager* Instance;

public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;

		return Instance;
	}
	~InputManager();

private:
	DWORD Key;
public:
	void InputKey();
};