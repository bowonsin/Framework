#include "Stage_1.h"

#include "Player.h"


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

	m_LTimer = GetTickCount64();
	m_iTime_Setting = 0;

	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObject_list("Player")->front();

	Stage::Monster_Setting(); // 시작전 몬스터 초기화
}

void Stage_1::Regen_Enemy(string EnemyName, Vector3 _Position)
{
	ObjectManager::GetInstance()->Active_Unit(EnemyName, _Position);
}

void Stage_1::Time_to_RegenMonster()
{
	if (m_iTime_Setting == 10)
	{
		Regen_Enemy("NormalEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position));// 3마리 소환

		auto iter = ObjectManager::GetInstance()->GetObject_list("NormalEnemy");
		float size = iter->front()->GetScale().y;
		Regen_Enemy("NormalEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position - size * 1.5f));
	}
}


void Stage_1::Update()
{
	if (m_LTimer + 250 < GetTickCount64())
	{
		++m_iTime_Setting;
		Time_to_RegenMonster();
	}

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

