#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy(){}

Enemy::Enemy(Trasnform _info):Object(_info){}

Enemy::~Enemy(){}

void Enemy::Initialize()
{
	strKey = "Enemy";

	Buffer[0] = (char*)"호";
	Buffer[1] = (char*)"ㅅ";


	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
}

int Enemy::Update()
{
	//TransInfo.Position.x -= 2;
	// 일정 시간마다 플레이어 방향으로 총알이 쏘도록

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0;
}

void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position,(char*)"Enemy"
	);

}

void Enemy::Release()
{
}