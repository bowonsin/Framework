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

Stage_1::Stage_1() {}
Stage_1::~Stage_1() {}

void Stage_1::Initialize()
{
	pPlayer = Prototype::GetInstance()->ProtoTypeObject("Player")->Clone();

	Bridge* Kind_of_Enemy = new BossEnemy;
	ObjectManager::GetInstance()->AddObject("BossEnemy",Kind_of_Enemy);

	/*
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
}

void Stage_1::Update()
{
	
	Stage::Stage_Collision_Check(); // 충돌판정
}

void Stage_1::Render()
{
}

void Stage_1::Release()
{
}