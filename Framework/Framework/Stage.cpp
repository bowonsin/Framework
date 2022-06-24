#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"

Stage::Stage(): pPlayer(nullptr){}
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	pPlayer = new Player;
	pPlayer->Initialize();
}

void Stage::Update()
{
	pPlayer->Update();
}

void Stage::Render()
{
	pPlayer->Render();
}

void Stage::Release()
{
	::Safe_Delete(pPlayer);
}


