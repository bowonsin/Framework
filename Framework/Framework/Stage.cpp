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

	// Bullet �ൿ �ݰ� �Ѿ�� �� Disable�� �̵�
	if (pBulletList != nullptr)
	{
		for (list<Object*>::iterator pBullet = pBulletList->begin(); pBullet != pBulletList->end();)
		{
			// x�� ��ǥ�� ���� �ִ�ġ ���� �Ѿ�°�, x�� ��ǥ�� 0 ���� ������
			if ((*pBullet)->Getposition().x >= ConsoleWidthSize || (*pBullet)->Getposition().x <= 0 ||
				// y�� ��ǥ�� ���� �ִ�ġ ���� �Ѿ�°�, y�� ��ǥ�� 0���� ������
				(*pBullet)->Getposition().y >= ConsoleHeightSize || (*pBullet)->Getposition().y <= 0)
			{
				pBullet = ObjectManager::GetInstance()->ThrowObject(pBullet, (*pBullet));
			}
			else
				++pBullet;
		}
	}

	// ��ü���� �浹 ���� . 
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
						// Enemy �� Bullet�� �浹 Ȯ��
						if (CollisionManager::Collision(*pBulletIter, *pEnemyIter))
						{
							pBulletIter = ObjectManager::GetInstance()->ThrowObject(pBulletIter, (*pBulletIter));
						}
						else
							++pBulletIter;
					}
				}
				// �÷��̾�� enemy�� �浹 
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
		�� ������������ ���� �Ҵ� �ϴ°ɷ�
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
	// ** 1. ��ȯ ���°� Object* && list<Object*>
	// ** list<Object*> �ҷ����� ������ ��
	// ** 2.Key �� ���޵Ǿ�� ��.

	//pPlayer = ObjectManager::GetInstance()->GetPlayerObject("Player");
	//list<Object*>* pPlayerList = ObjectManager::GetInstance()->GetObject_list("Player");
	//if (pPlayerList != nullptr)
	//	pPlayer = pPlayerList->front();
	*/