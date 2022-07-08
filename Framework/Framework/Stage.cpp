#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ScrollBox.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "InputManager.h"

#include "ObjectPool.h"
#include "Prototype.h"

//#include "CursorManager.h"

Stage::Stage():pUI(nullptr),Check (0){}
Stage::~Stage() { Release(); }

void Stage::Initialize()
{

	Check = 0;
	
	pUI = new ScrollBox;
	pUI->Initialize();
	ObjectManager::GetInstance()->AddObject(Prototype::GetInstance()->ProtoTypeObject("Player"));
	pPlayer = ObjectManager::GetInstance()->GetObject_list("Player")->front();
	

	for (int i = 0; i < 5; i++)
	{
		srand((DWORD)GetTickCount64() * (i + 1));
		Object* pEnemy = Prototype::GetInstance()->ProtoTypeObject("Enemy");
		pEnemy->Setposition(float(rand() % 118), rand() % 30);
		ObjectManager::GetInstance()->AddObject(pEnemy->Clone());
	}

	/*
	for (int i = 0; i < 5; ++i)
	{
		srand((DWORD)GetTickCount64() * (i + 1));

		Object* pEnemy = pEnemyProto->Clone();
		//pEnemy->Setposition(118.0f, rand()% 30);
		pEnemy->Setposition(float(rand()% 118), rand() % 30);


		ObjectManager::GetInstance()->AddObject(pEnemy);

	}
	// ** 1. 반환 형태가 Object* && list<Object*>
	// ** list<Object*> 불러오는 것으로 함
	// ** 2.Key 가 전달되어야 함.

	//pPlayer = ObjectManager::GetInstance()->GetPlayerObject("Player");
	//list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObject_list("Player");
	//if (pPlayerList != nullptr)
	//	pPlayer = pPlayerList->front();
	*/
}

void Stage::Update()
{


	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObject_list("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObject_list("Enemy");

	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_TAB)// 
	{
		Enable_UI();
	}

	if (dwKey & KEY_ESCAPE)
	{
		if (pBulletList->size())
		{
			ObjectPool::GetInstance()->CatchObject(pBulletList->back());
			pBulletList->pop_back();
		}
	}

	ObjectManager::GetInstance()->Update();

		if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator iter = pBulletList->begin(); iter != pBulletList->end();)
		{
			if ((*iter)->Getposition().x >= 120.0f)
			{
				iter = pBulletList->erase(iter);
			}
			else
				++iter;
		}
	}
	if (pPlayer != nullptr)
	{
 		if (pEnemyList != nullptr)
		{
			for (list<Object*>::iterator pEnemyIter = pEnemyList->begin();
				pEnemyIter != pEnemyList->end(); ++pEnemyIter)
			{
				if (CollisionManager::CircleCollision(pPlayer, *pEnemyIter))
				{ 
					pEnemyIter = ObjectManager::GetInstance()->ThrowObject(pEnemyIter, (*pEnemyIter));
				}
				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator pBulletIter = pBulletList->begin();
						pBulletIter != pBulletList->end();)
					{
						if (CollisionManager::Collision(*pBulletIter, *pEnemyIter))
						{
							pBulletIter = ObjectManager::GetInstance()->ThrowObject(pBulletIter, (*pBulletIter));
							
						}
						else
							++pBulletIter;
					}
				}
			}
		}
	}
	//if (pUI)
	//	pUI->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Redner();

	//if (Check)
	//	pUI->Render();
}

void Stage::Release()
{

}

void Stage::Enable_UI()
{
	Check = !Check;
	
}
