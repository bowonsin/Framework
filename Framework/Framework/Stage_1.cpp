#include "Stage_1.h"

#include "Player.h"


#include "Prototype.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "ObjectPool.h"

#include "ScoreInterface.h"
#include "ClearCheckInterface.h"

Stage_1::Stage_1() : OverTime (0){}
Stage_1::~Stage_1() {}

void Stage_1::Initialize()
{
	Clear_Ui = new ClearCheckInterface;
	Clear_Ui->Initialize();

	OutSide_UI = new ScoreInterface;
	OutSide_UI->Initialize();

	OverTime = 0;
	m_LTimer = GetTickCount64();
	m_iTime_Setting = 0;
	m_bBoss_Check = true;
	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObject_list("Player")->front();

	Stage::Monster_Setting(); // 시작전 몬스터 초기화
}

void Stage_1::Time_to_RegenMonster()
{
	if (m_iTime_Setting == 75)
	{
		
		Stage::Regen_Enemy("NormalEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position),1);// 3마리 소환
		
		auto iter = ObjectManager::GetInstance()->GetObject_list("NormalEnemy");
		float size = iter->front()->GetScale().y;
		Stage::Regen_Enemy("NormalEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position - size * 1.5f),1);
	}
	else if (m_iTime_Setting == 150)
	{
		Stage::Regen_Enemy("NormalItemEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position), 1);// 3마리 소환

		auto iter = ObjectManager::GetInstance()->GetObject_list("NormalEnemy");
		float size = iter->front()->GetScale().y;
		Stage::Regen_Enemy("NormalItemEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position - size * 1.5f), 1);
		Stage::Regen_Enemy("NormalItemEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position - size * 2.2f), 1);
		Stage::Regen_Enemy("NormalItemEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position + size ), 1);
	}
	else if (m_iTime_Setting == 250)
	{
		Stage::Regen_Enemy("NamedEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position ), 10);
	}
	else if (m_iTime_Setting == 260)
	{

		Stage::Regen_Enemy("NormalEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position), 1);// 3마리 소환

		auto iter = ObjectManager::GetInstance()->GetObject_list("NormalEnemy");
		float size = iter->front()->GetScale().y;
		Stage::Regen_Enemy("NormalEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position + size ), 1);
		Stage::Regen_Enemy("NormalEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position - size * 2.5f), 1);
		Stage::Regen_Enemy("NormalEnemy", Vector3(InGameConsole_WidthSize, Boss_Y_Position - size * 1.5f), 1);

	}
	else if (m_iTime_Setting == 300)
	{
		Stage::Regen_Enemy("BossEnemy", Vector3(InGameConsole_WidthSize - 20, Boss_Y_Position), 30);
		m_bBoss_Check = true;
	}
	

}


void Stage_1::Update()
{

	ObjectManager::GetInstance()->Update();

	if (OutSide_UI)
		OutSide_UI->Update();

	if (pPlayer != nullptr && pPlayer->GetHp() > 0)
	{
		if (m_bBoss_Check)
		{
			if (m_LTimer + 250 < GetTickCount64())
			{
				auto iter = ObjectManager::GetInstance()->GetObject_list("NamedEnemy");
				if ((*iter).begin() == (*iter).end())
				{
					++m_iTime_Setting;
					Time_to_RegenMonster();
				}

			}
		}
		else
		{
			if (m_LTimer + 500 < GetTickCount64())
			{
				m_LTimer = GetTickCount64();
				Clear_Ui->OverCheck(false);
				if (OverTime > 8)
					SceneManager::GetInstance()->SetScene(SCENEID::STAGE_MENU);
				++OverTime;

			}

		}
	}
	else
	{
		if (m_LTimer + 500 < GetTickCount64())
		{
			m_LTimer = GetTickCount64();
			Clear_Ui->OverCheck(true);
			if (OverTime > 8)
				SceneManager::GetInstance()->SetScene(SCENEID::STAGE_MENU);
			++OverTime;

			m_bBoss_Check = false;
		}
	}
	if (m_bBoss_Check)
		Stage::Stage_Collision_Check(); // 충돌판정
}

void Stage_1::Render()
{

	ObjectManager::GetInstance()->Redner();
	
	if (OutSide_UI)
		OutSide_UI->Render();
	if (Clear_Ui)
		Clear_Ui->Render();
}

void Stage_1::Release()
{
	::Safe_Delete(OutSide_UI);
	::Safe_Delete(Clear_Ui);
	Stage::Obejct_Disable();
	auto iter = ObjectManager::GetInstance()->GetObject_list("Player")->begin();
	ObjectManager::GetInstance()->ThrowObject(iter,*iter);
}

