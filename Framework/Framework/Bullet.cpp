#include "Bullet.h"
#include "CursorManager.h"

Bullet::Bullet() {}

Bullet::Bullet(Trasnform _info) :Object(_info) {}

Bullet::~Bullet() {}

void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"＼";
	Buffer[1] = (char*)"／";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, .0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction= Vector3(0.0f, 0.0f);

	Vector3 Target = Vector3(60.0f, 15.0f);
	// 타겟으로 부터 내 좌표를 빼면 됨

	Vector3 Result = Target - TransInfo.Position;

	float Distance = sqrt((Result.x * Result.x) + (Result.y * Result.y));
	TransInfo.Direction /= Distance;
}

int  Bullet::Update()
{ 
	Vector3 Target = Vector3(60.0f, 15.0f);
	Vector3 TargetVector = Target - TransInfo.Position; // 이 부분이 Initialize에 있으면 안됌
	float Distance = sqrt((TargetVector.x * TargetVector.x) + (TargetVector.y * TargetVector.y));

	TransInfo.Direction.x = TargetVector.x / Distance;
	TransInfo.Direction.y = TargetVector.y / Distance;

	TransInfo.Position += TransInfo.Direction;

	float Average = sqrt(
		(TransInfo.Direction.x * TransInfo.Direction.x) +
		(TransInfo.Direction.y * TransInfo.Direction.y));

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