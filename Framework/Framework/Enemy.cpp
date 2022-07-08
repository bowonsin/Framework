#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy(){}

Enemy::Enemy(Trasnform _info):Object(_info){}

Enemy::~Enemy(){}

Object* Enemy::Initialize(string _Key)
{
	strKey = "Enemy";

	Hp = 3;

	Buffer[0] = (char*)"호";
	Buffer[1] = (char*)"ㅅ";


	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen(Buffer[0]), (float)MAX_SIZE);

	Color = 12;

	return this;
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
	for (int i = 0; i < 2; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			Buffer[i], Color);

}

void Enemy::Release()
{
}