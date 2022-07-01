#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ScrollBox.h"

#include "SceneManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "InputManager.h"

#include "ObjectFActory.h"

//#include "CursorManager.h"

Stage::Stage():pUI(nullptr),Check (0){}
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;
	
	Object* pEnemyProto = ObjectFactory<Enemy>::CreateObject();
	pUI = new ScrollBox;
	pUI->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand((DWORD)GetTickCount64() * (i + 1));

		Object* pEnemy = pEnemyProto->Clone();
		//pEnemy->Setposition(118.0f, rand()% 30);
		pEnemy->Setposition(float(rand()% 118), rand() % 30);


		ObjectManager::GetInstance()->AddObject(pEnemy);

	}
	/*
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
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_TAB)// 
	{
		Enable_UI();
	}

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
				if (CollisionManager::Collision(pPlayer, *pEnemyIter))
					CursorManager::Draw(50.0f, 1.0f, "충돌입니다.");

				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator pBulletIter = pBulletList->begin();
						pBulletIter != pBulletList->end(); ++pBulletIter)
					{

						{
							if (CollisionManager::Collision(*pBulletIter, *pEnemyIter))
								CursorManager::Draw(50.0f, 1.0f, "충돌입니다.");
						}

					}
				}
			}
		}
	}
	pUI->Update();
}

void Stage::Render()
{
	if (Check)
		pUI->Render();
	ObjectManager::GetInstance()->Redner();
}

void Stage::Release()
{

}

void Stage::Enable_UI()
{
	Check = !Check;
	
}
