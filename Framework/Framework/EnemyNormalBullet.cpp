#include "EnemyNormalBullet.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "MathManager.h"

EnemyNormalBullet::EnemyNormalBullet() {}
EnemyNormalBullet::~EnemyNormalBullet() { Release(); }

void EnemyNormalBullet::Initialize()
{
	Speed = 1.2f;
	Color = 15;

	list<Object*>* pPlayer = ObjectManager::GetInstance()->GetObject_list("Player");
	Target_Direction = MathManager::GetDirection(pObject->Getposition(),pPlayer->front()->Getposition());
}

int EnemyNormalBullet::Update(Transform& Info)
{
	// ó�� ����� �÷��̾� ��ǥ�� �⿡ �߻��
	Info.Position += Target_Direction * Speed; 

	return BulletBridge::Console_OutSide_Check();
}

void EnemyNormalBullet::Render()
{
	Vector3 Position = pObject->Getposition();
	CursorManager::GetInstance()->WriteBuffer(
		Position.x,
		Position.y,
		(char*)"��", Color);
}

void EnemyNormalBullet::Release()
{

}