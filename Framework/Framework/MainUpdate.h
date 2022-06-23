#pragma once
#include "SceneManager.h"

class MainUpdate
{
private:
	int Count;
	
	int SceneState;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();

	MainUpdate();
	~MainUpdate();
};

