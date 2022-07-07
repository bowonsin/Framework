#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectManager.h"
#include "CollisionManager.h"

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
	TransInfo.Scale = Vector3((float)strlen(Buffer[0]),(float)MAX_SIZE);
	TransInfo.Direction= Vector3(0.0f, 0.0f);

	// Ÿ������ ���� �� ��ǥ�� ���� ��

	Color = 13;

}

int  Bullet::Update()
{ 
	
	list<Object*>* Enemy = ObjectManager::GetInstance()->GetObject_list("Enemy");

	//���� ������ ��ǥ�� �ִ� ���� ���ؼ� �⵿
	//Vector3 Enemy_Position  = Enemy->front()->Getposition();
	float Check = 1000.0f;
	Vector3 Temp;
	for (auto iter = Enemy->begin(); iter != Enemy->end(); ++iter)
	{
		float Test = MathManager::GetDistance(TransInfo.Position, (*iter)->Getposition());
		if (Test < Check)
		{
			Check = Test;
			Temp = (*iter)->Getposition();
		}
	}

	TransInfo.Direction = MathManager::GetDirection(
	TransInfo.Position, Temp);

	TransInfo.Position += TransInfo.Direction;


	return 0;
}

void Bullet::Render()
{
	for (int i = 0; i < 2; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			Buffer[i], Color);

}

void Bullet::Release()
{
}