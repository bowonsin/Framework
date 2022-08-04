#include "Enemy.h"
#include "CursorManager.h"

#include "Bridge.h"

Enemy::Enemy(){}
Enemy::Enemy(Transform _info):Object(_info){}
Enemy::~Enemy(){}

Object* Enemy::Initialize(string _Key)
{
	strKey = _Key;

	Hp = 3;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);

	if (pBridge)
		pBridge->Initialize();
	return this;
}

int Enemy::Update()
{
	//TransInfo.Position.x -= 2;
	// 일정 시간마다 플레이어 방향으로 총알이 쏘도록

	if (TransInfo.Position.x <= 0 )
		return BUFFER_OVER;

	if (pBridge)
		return pBridge->Update(TransInfo);
}

void Enemy::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Enemy::Release()
{
	::Safe_Delete(pBridge);
}