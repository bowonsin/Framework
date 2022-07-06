#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Bullet::Bullet() {}

Bullet::Bullet(Trasnform _info) :Object(_info) {}
Bullet::~Bullet() {}

void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, .0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction= Vector3(0.0f, 0.0f);

	// Ÿ������ ���� �� ��ǥ�� ���� ��
}

int  Bullet::Update()
{ 
	TransInfo.Direction = MathManager::GetDirection(
	TransInfo.Position, Vector3(120.0f, 15.0f));

	TransInfo.Position += TransInfo.Direction;

	float Distance = MathManager::GetDistance(
		TransInfo.Position, Vector3(60.0f, 15.0));

	
	float Sum = 4;

	if (Distance < Sum)
		return 2;

	return 0;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position, (char*)"ABCDEFG");

}

void Bullet::Release()
{
}