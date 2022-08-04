#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

#include "ObjectManager.h"
#include "CollisionManager.h"

Stage::Stage():pPlayer(nullptr){}
Stage::~Stage() { }

void Stage::Stage_Collision_Check()
{
	Object* Player = ObjectManager::GetInstance()->GetObject_list("Player")->front();
	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObject_list("NormalBullet");
	list<Object*>* pBossEnemy = ObjectManager::GetInstance()->GetObject_list("BossEnemy");
	list<Object*>* pNamedEnemyList = ObjectManager::GetInstance()->GetObject_list("NamedEnemy");
	list<Object*>* pNormalEnemyList = ObjectManager::GetInstance()->GetObject_list("NormalEnemy");
	list<Object*>* pEnemyNormalBulletList = ObjectManager::GetInstance()->GetObject_list("EnemyNormalBullet");
	list<Object*>* pEnemyHomimgBulletList = ObjectManager::GetInstance()->GetObject_list("EnemyHomimgBullet");

	// Bullet �ൿ �ݰ� �Ѿ�� �� Disable�� �̵�
	/* // ���� �ٸ� Bullet�� BulletBridge���� �̹� ���� �ϰ� ObjectPool ���� �̹� ������ �����ϰ� ����.
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
	*/

	if (Player != nullptr)
	{
		if (pBossEnemy != nullptr)
			Player_Enemy_Collision_Check(Player, pBossEnemy);

		if (pNamedEnemyList != nullptr)
			Player_Enemy_Collision_Check(Player, pNamedEnemyList);

		if (pNormalEnemyList != nullptr)
			Player_Enemy_Collision_Check(Player, pNormalEnemyList);

		if (pEnemyNormalBulletList != nullptr)
			Player_EnemyBullet_Collision_Check(Player, pEnemyNormalBulletList);

		if (pBulletList != nullptr)
			PlayerBullet_Enemy_Collision_Check(pBulletList, pNamedEnemyList);
	}

	// ��ü���� �浹 ���� . 
	/*
	if (Player != nullptr)
	{
		if (pBossEnemy != nullptr)
		{
			for (list<Object*>::iterator pEnemyIter = pBossEnemy->begin();
				pEnemyIter != pBossEnemy->end();)
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
				// �÷��̾�� enemy�� �浹 �Ǵ� �� ������ �����°�
				if (CollisionManager::CircleCollision(Player, *pEnemyIter))
				{
					pEnemyIter = ObjectManager::GetInstance()->ThrowObject(pEnemyIter, (*pEnemyIter));
				}
				else if ((*pEnemyIter)->Getposition().x >= ConsoleWidthSize || (*pEnemyIter)->Getposition().x <= 0 ||
					(*pEnemyIter)->Getposition().y >= ConsoleHeightSize || (*pEnemyIter)->Getposition().y <= 0)	

					pEnemyIter = ObjectManager::GetInstance()->ThrowObject(pEnemyIter, (*pEnemyIter));
				else
					++pEnemyIter;
			}
		}
	}
	*/
}

void Stage::Player_Enemy_Collision_Check(Object* Player, list<Object*>* EnemyList)
{
	for (list<Object*>::iterator Enemy = EnemyList->begin();
		Enemy != EnemyList->end();)
	{
		if (CollisionManager::Collision(Player, (*Enemy)))
			Enemy = ObjectManager::GetInstance()->ThrowObject(Enemy, (*Enemy));
		else
			++Enemy;
	}
}

void Stage::Player_EnemyBullet_Collision_Check(Object* Player, list<Object*>* EnemyBullet)
{
	for (list<Object*>::iterator Bullet = EnemyBullet->begin();
		Bullet != EnemyBullet->end();)
	{
		if (CollisionManager::Collision(Player, (*Bullet)))
		{
			Bullet = ObjectManager::GetInstance()->ThrowObject(Bullet, (*Bullet));
			// Player �� �� Bullet�� �浹 ������ Player���� �浹 �������� ���� ������ �� ����
		}
		else
			++Bullet;
	}
}

void Stage::PlayerBullet_Enemy_Collision_Check(list<Object*>* Player_Bullet, list<Object*>* EnemyList)
{
	bool EnemyCheck = false;
	for (list<Object*>::iterator Enemy = EnemyList->begin();
		Enemy != EnemyList->end();)
	{
		for (list<Object*>::iterator Bullet = Player_Bullet->begin();
			Bullet != Player_Bullet->end();)
		{
			if (CollisionManager::Collision((*Enemy), (*Bullet)))
			{
				Bullet = ObjectManager::GetInstance()->ThrowObject(Bullet, (*Bullet));
				EnemyCheck = true;
			}
			else 
				++Bullet;
		}

		if (!EnemyCheck)
			++Enemy;
		else
			EnemyCheck = false;
	}
}


void Stage::Obejct_Disable()
{
	list<Object*>* Dis_Object = ObjectManager::GetInstance()->GetObject_list("BossEnemy");
	if (Dis_Object)
		ObjectManager::GetInstance()->ThrowObject(Dis_Object->begin(), Dis_Object->front());

	Dis_Object = ObjectManager::GetInstance()->GetObject_list("NamedEnemy");
	if (Dis_Object)
		ObjectManager::GetInstance()->ThrowObject(Dis_Object->begin(), Dis_Object->front());

	Dis_Object = ObjectManager::GetInstance()->GetObject_list("NormalEnemy");
	if (Dis_Object)
		for (auto Enemyiter = Dis_Object->begin(); Enemyiter != Dis_Object->end(); ++Enemyiter)
			ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));

	Dis_Object = ObjectManager::GetInstance()->GetObject_list("NormalItemEnemy");
	if (Dis_Object)
		for (auto Enemyiter = Dis_Object->begin(); Enemyiter != Dis_Object->end(); ++Enemyiter)
			ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));

	Dis_Object = ObjectManager::GetInstance()->GetObject_list("NormalBullet");
	if (Dis_Object)
		for (auto Enemyiter = Dis_Object->begin(); Enemyiter != Dis_Object->end(); ++Enemyiter)
			ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));

	Dis_Object = ObjectManager::GetInstance()->GetObject_list("EnemyNormalBullet");
	if (Dis_Object)
		for (auto Enemyiter = Dis_Object->begin(); Enemyiter != Dis_Object->end(); ++Enemyiter)
			ObjectManager::GetInstance()->ThrowObject(Enemyiter, (*Enemyiter));

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