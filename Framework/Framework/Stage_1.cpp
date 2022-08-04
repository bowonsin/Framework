#include "Stage_1.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BossEnemy.h"
#include "NamedEnemy.h"
#include "NormalEnemy.h"
#include "NormalItemEnemy.h"

#include "Prototype.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectPool.h"

#include "ScoreInterface.h"

Stage_1::Stage_1() {}
Stage_1::~Stage_1() {}

void Stage_1::Initialize()
{
	OutSide_UI = new ScoreInterface;
	OutSide_UI->Initialize();

	ObjectManager::GetInstance()->AddObject("Player");

	Bridge* Kind_of_Enemy = new NamedEnemy;
	ObjectManager::GetInstance()->AddObject("NamedEnemy", Kind_of_Enemy);

	/*
	Bridge* Kind_of_Enemy = new BossEnemy;
	ObjectManager::GetInstance()->AddObject("BossEnemy",Kind_of_Enemy);

	Kind_of_Enemy = new NamedEnemy;
	ObjectManager::GetInstance()->AddObject("NamedEnemy", Kind_of_Enemy);

	for (int i = 0; i < 3; ++i)
	{
		Kind_of_Enemy = new NormalEnemy;
		ObjectManager::GetInstance()->AddObject("NamedEnemy", Kind_of_Enemy);
	}
	
	for (int i = 0 ; i < 2 ; ++i)
	{
		Kind_of_Enemy = new NormalItemEnemy;
		ObjectManager::GetInstance()->AddObject("NamedEnemy", Kind_of_Enemy);
	}
	*/
	Stage::Obejct_Disable();

	Regen_Enemy(0);
}

void Stage_1::Update()
{
	if (OutSide_UI)
		OutSide_UI->Update();

	ObjectManager::GetInstance()->Update();
	Stage::Stage_Collision_Check(); // 충돌판정
}

void Stage_1::Render()
{
	ObjectManager::GetInstance()->Redner();
	
	if (OutSide_UI)
		OutSide_UI->Render();
}

void Stage_1::Release()
{
	::Safe_Delete(pPlayer);
	::Safe_Delete(OutSide_UI);
}

void Stage_1::Regen_Enemy(int Time)
{
	ObjectManager::GetInstance()->AddObject("NamedEnemy");
	ObjectManager::GetInstance()->GetObject_list("NamedEnemy")->front()->Setposition(InGameConsole_WidthSize, Boss_Y_Position);
}
