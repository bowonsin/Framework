#pragma once
#include "Headers.h"
class InputManager
{
private:
	static InputManager* Instance;

public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;

		return Instance;
	}


private:
	DWORD Key;
public:
	void InputKey();
	DWORD GetKey() const { return Key; }

private:
	InputManager();
public:
	~InputManager();

};