#pragma once
#include "Headers.h"
class SceneManager
{
private:
	SceneManager() {}
	static SceneManager* Instance;

public:

	void SetScene(int _SceneState); // set나 get 은 인라인으로 만드는데 현지 이 함수는 그럴 필요 없다.

	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;

		return Instance;
	}
	~SceneManager() {}
};

