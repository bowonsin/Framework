#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy(){}

Enemy::Enemy(Trasnform _info):Object(_info){}

Enemy::~Enemy(){}

void Enemy::Initialize()
{
	strKey = "BB";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 5.0f);
	TransInfo.Sacle = Vector3(2.0f, 2.0f);

	Buffer[0] = (char*)"È£";
	Buffer[1] = (char*)"¤µ";
}

int Enemy::Update()
{
	//TransInfo.Position.x -= 2;

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0;
}

void Enemy::Render()
{
	CursorManager::Draw(
		TransInfo.Position.x- (TransInfo.Sacle.x*0.5f), 
		TransInfo.Position.y, 
		strKey);


}

void Enemy::Release()
{
}