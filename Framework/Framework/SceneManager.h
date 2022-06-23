#pragma once
#include "Headers.h"
class SceneManager
{
private:
	SceneManager() {}
	static SceneManager* Instance;

public:

	void SetScene(int _SceneState); // set�� get �� �ζ������� ����µ� ���� �� �Լ��� �׷� �ʿ� ����.

	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;

		return Instance;
	}
	~SceneManager() {}
};

