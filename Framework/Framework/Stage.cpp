#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "CursorManager.h"

//#include "CursorManager.h"

Stage::Stage(){}
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Object* pEnemyProto= new Enemy;
	pEnemyProto->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand((DWORD)GetTickCount64() * (i + 1));

		Object* pEnemy = pEnemyProto->Clone();
		//pEnemy->Setposition(118.0f, rand()% 30);
		pEnemy->Setposition(float(rand()% 118), rand() % 30);


		ObjectManager::GetInstance()->AddObject(pEnemy);

	}
	/*
	// ** 1. ��ȯ ���°� Object* && list<Object*>
	// ** list<Object*> �ҷ����� ������ ��
	// ** 2.Key �� ���޵Ǿ�� ��.

	//pPlayer = ObjectManager::GetInstance()->GetPlayerObject("Player");
	//list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObject_list("Player");
	//if (pPlayerList != nullptr)
	//	pPlayer = pPlayerList->front();
	*/
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();

	Object* pPlayer = ObjectManager::GetInstance()->GetObject_list("Player")->front();
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObject_list("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObject_list("Enemy");

	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin(); iter != pBulletList->end();)
		{
			if ((*iter)->Getposition().x >= 120.0f)
			{
				iter = pBulletList->erase(iter);
				//delete (*iter); ���ó� ��������.
				//(*iter) = nullptr;
			}
			else
				++iter;
		}
	}

	if (pEnemyList !=nullptr && pBulletList != nullptr)
	{
		for (list<Object*>::iterator pBulletIter = pBulletList->begin(); 
			pBulletIter != pBulletList->end(); ++pBulletIter)
		{
			for (list<Object*>::iterator pEnemyIter = pEnemyList->begin();
				pEnemyIter != pEnemyList->end(); ++pEnemyIter)
			{
				if (CollisionManager::Collision(*pBulletIter, *pEnemyIter))
					CursorManager::Draw(50.0f, 1.0f, "�浹�Դϴ�.");
			}

		}
	}
	if (pEnemyList != nullptr && pPlayer != nullptr)
	{
		for (list<Object*>::iterator pEnemyIter = pEnemyList->begin();
			pEnemyIter != pEnemyList->end(); ++pEnemyIter)
		{
			if (CollisionManager::Collision(pPlayer, *pEnemyIter))
				CursorManager::Draw(50.0f, 1.0f, "�浹�Դϴ�.");
		}
	}
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Redner();
}

void Stage::Release()
{

}