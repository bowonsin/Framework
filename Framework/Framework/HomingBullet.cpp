#include "HomingBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "MathManager.h"

HomingBullet::HomingBullet(): m_bSurvival_check(true), m_lTimer (0){}
HomingBullet::~HomingBullet() {}

void HomingBullet::Initialize()
{
	Speed = 1.2f;
	Color = 15;

	m_bSurvival_check = true;

	m_lTimer = GetTickCount64();
	
}

int HomingBullet::Update(Transform& Info)
{
	
	if (m_lTimer + 100 < GetTickCount64())
	{
		if (!m_bSurvival_check)
			return BUFFER_OVER;

		list<Object*>* pPlayer = ObjectManager::GetInstance()->GetObject_list("Player");
		Target_Direction = MathManager::GetDirection(pObject->Getposition(), pPlayer->front()->Getposition());

		Info.Position += Target_Direction;
		m_bSurvival_check = true;
	}
    return 0;
}

void HomingBullet::Render()
{
	Vector3 Position = pObject->Getposition();
	CursorManager::GetInstance()->WriteBuffer(
		Position.x,
		Position.y,
		(char*)"£ª", Color);
}

void HomingBullet::Release()
{
}

void HomingBullet::Survival_Check(int Hp)
{
	m_bSurvival_check = false;
}


