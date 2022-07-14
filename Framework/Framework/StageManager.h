#pragma once
#include "Headers.h"
class Stage;
class StageManager
{
private:
	static StageManager* Instance;

public:
	static StageManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new StageManager;

		return Instance;
	}
private:
	Stage* Stage_Id;

public:
	void GetStage();

	void Update();
	void Render();
	void Release();

public:
	StageManager();
	~StageManager();
};

