#include "MainUpdate.h"

MainUpdate::MainUpdate(){}

MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	SceneState = LOGO;
	SceneManager::GetInstance()->SetScene(SceneState);
}

void MainUpdate::Update()
{

	++Count;
	if (Count <= 100)
	{
		Count = 0;
	}

}

void MainUpdate::Render()
{
}

void MainUpdate::Release()
{
}

