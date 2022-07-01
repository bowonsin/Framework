#include "Bullet.h"
#include "CursorManager.h"

Bullet::Bullet() {}

Bullet::Bullet(Trasnform _info) :Object(_info) {}

Bullet::~Bullet() {}

void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"°¨";
	Buffer[1] = (char*)"£Ø";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, .0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
	TransInfo.Direction= Vector3(0.0f, 0.0f);

	Vector3 Target = Vector3(60.0f, 15.0f);
	// ≈∏∞Ÿ¿∏∑Œ ∫Œ≈Õ ≥ª ¡¬«•∏¶ ª©∏È µ 

	Vector3 Result = Target - TransInfo.Position;

	float Distance = sqrt((Result.x * Result.x) + (Result.y * Result.y));
	TransInfo.Direction /= Distance;
}

int  Bullet::Update()
{ 
	TransInfo.Position += TransInfo.Direction;
	//TransInfo.Position.x += 2;

	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - (TransInfo.Scale.x * 0.5f),
			TransInfo.Position.y - (TransInfo.Scale.x * 0.5f) + i,
			Buffer[i]);
	}


}

void Bullet::Release()
{
}