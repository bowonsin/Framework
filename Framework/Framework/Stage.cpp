#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

#include "ObjectManager.h"
#include "CollisionManager.h"

Stage::Stage():pPlayer(nullptr){}
Stage::~Stage() { }

void Stage::Stage_Collision_Check()
{
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObject_list("Bullet");
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObject_list("Enemy");

	// Bullet 행동 반경 넘어섯을 떄 Disable로 이동
	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator pBullet = pBulletList->begin(); pBullet != pBulletList->end();)
		{
			// x의 좌표가 맵의 최대치 보다 넘어가는것, x의 좌표가 0 보다 낮은것
			if ((*pBullet)->Getposition().x >= ConsoleWidthSize || (*pBullet)->Getposition().x <= 0 ||
				// y의 좌표가 맵의 최대치 보다 넘어가는것, y의 좌표가 0보다 낮은거
				(*pBullet)->Getposition().y >= ConsoleHeightSize || (*pBullet)->Getposition().y <= 0)
			{
				pBullet = ObjectManager::GetInstance()->ThrowObject(pBullet, (*pBullet));
			}
			else
				++pBullet;
		}
	}

	// 전체적인 충돌 판정 . 
	if (pPlayer != nullptr)
	{
		if (pEnemyList != nullptr)
		{
			for (list<Object*>::iterator pEnemyIter = pEnemyList->begin();
				pEnemyIter != pEnemyList->end();)
			{
				if (pBulletList != nullptr)
				{
					for (list<Object*>::iterator pBulletIter = pBulletList->begin();
						pBulletIter != pBulletList->end();)
					{
						// Enemy 와 Bullet의 충돌 확인
						if (CollisionManager::Collision(*pBulletIter, *pEnemyIter))
						{
							pBulletIter = ObjectManager::GetInstance()->ThrowObject(pBulletIter, (*pBulletIter));
						}
						else
							++pBulletIter;
					}
				}
				// 플레이어와 enemy의 충돌 
				if (CollisionManager::CircleCollision(pPlayer, *pEnemyIter))
				{
					pEnemyIter = ObjectManager::GetInstance()->ThrowObject(pEnemyIter, (*pEnemyIter));
				}
				else
					++pEnemyIter;
			}
		}
	}
}

/*
		각 스테이지에서 따로 할당 하는걸로
	ObjectManager::GetInstance()->AddObject("Player");
	pPlayer = ObjectManager::GetInstance()->GetObject_list("Player")->front();


	for(int i = 0 ; i < 5; i++)
		ObjectManager::GetInstance()->AddObject("Enemy");

	list<Object*>* Elist = ObjectManager::GetInstance()->GetObject_list("Enemy");
	int i = 0;
	for (auto iter = Elist->begin(); iter != Elist->end(); ++iter)
	{
		srand((DWORD)GetTickCount64() * (i + 1));
		(*iter)->Setposition(float(rand() % 118), rand() % 30);
		++i;
	}
	*/

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