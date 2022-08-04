#include "EnemyNormalBullet.h"
#include "CursorManager.h"

EnemyNormalBullet::EnemyNormalBullet() {}
EnemyNormalBullet::~EnemyNormalBullet() { Release(); }

void EnemyNormalBullet::Initialize()
{
	Speed = 0.5f;
	Color = 15;
}

int EnemyNormalBullet::Update(Transform& Info)
{
	Info.Direction.x = -1;
	Info.Position.x += Info.Direction.x;

	return BulletBridge::Console_OutSide_Check();
}

void EnemyNormalBullet::Render()
{
	Vector3 Position = pObject->Getposition();
	CursorManager::GetInstance()->WriteBuffer(
		Position.x,
		Position.y,
		(char*)"£ª", Color);
}

void EnemyNormalBullet::Release()
{

}