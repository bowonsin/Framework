#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

#include "SceneManager.h"
#include "ObjectManager.h"

//#include "CursorManager.h"

Stage::Stage(): pPlayer(nullptr){}
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Object* pEnemyProto= new Enemy;
	pEnemyProto->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		srand((DWORD)GetTickCount64() * (i + 1));

		Object* pEnemy = pEnemyProto->Clone();
		pEnemy->Setposition(118.0f, rand()% 30);

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

	list<Object*>* pBulletList = ObjectManager::GetInstance()->GetObject_list("��");
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
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Redner();
}

void Stage::Release()
{
	::Safe_Delete(pPlayer);
}