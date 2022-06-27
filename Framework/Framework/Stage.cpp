#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "ObjectManager.h"

Stage::Stage(): pPlayer(nullptr){}
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	// ** 1. 반환 형태가 Object* && list<Object*>
	// ** list<Object*> 불러오는 것으로 함
	// ** 2.Key 가 전달되어야 함.

	//pPlayer = ObjectManager::GetInstance()->GetPlayerObject("Player");
	list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObject_list("Player");
	if (pPlayerList != nullptr)
		pPlayer = pPlayerList->front()->Clone();
}

void Stage::Update()
{
	if (pPlayer)
		pPlayer->Update();
}

void Stage::Render()
{
	if (pPlayer)
		pPlayer->Render();

	ObjectManager::GetInstance()->Redner();
}

void Stage::Release()
{
	//::Safe_Delete(pPlayer);
}