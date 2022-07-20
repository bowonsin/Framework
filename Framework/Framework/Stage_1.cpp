#include "Stage_1.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#include "Prototype.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"

Stage_1::Stage_1() {}
Stage_1::~Stage_1() {}

void Stage_1::Initialize()
{
	pPlayer = Prototype::GetInstance()->ProtoTypeObject("Player")->Clone();

	
	for (int i = 0; i < STAGE_MONSTER_COUNT::STAGE_1_NORMAL_MONSTER; ++i)
	{
	}
}

void Stage_1::Update()
{
	
}

void Stage_1::Render()
{
}

void Stage_1::Release()
{
}