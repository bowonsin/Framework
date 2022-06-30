#include "Bullet.h"
#include "CursorManager.h"

Bullet::Bullet() {}

Bullet::Bullet(Trasnform _info) :Object(_info) {}

Bullet::~Bullet() {}

void Bullet::Initialize()
{
	strKey = "Bullet";

	Buffer[0] = (char*)"¡¬";
	Buffer[1] = (char*)"£¯";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 5.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);
}

int  Bullet::Update()
{
	TransInfo.Position.x += 2;

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