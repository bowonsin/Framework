#include "Bullet.h"

#include "ObjectManager.h"
#include "CollisionManager.h"

#include "Bridge.h"

Bullet::Bullet() {}

Bullet::Bullet(Transform _info) :Object(_info) {}
Bullet::~Bullet() {}

Object* Bullet::Initialize(string _Key)
{
	strKey = "Bullet";

	Hp = 1;

	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, .0f);
	TransInfo.Scale = Vector3((float)strlen(Buffer[0]),(float)MAX_SIZE);

	TransInfo.Direction= Vector3(0.0f, 0.0f);

	// Ÿ������ ���� �� ��ǥ�� ���� ��


	if (pBridge)
		pBridge->Initialize();

	return this;
}

int  Bullet::Update()
{ 
	
	/*
		list<Object*>* Enemy = ObjectManager::GetInstance()->GetObject_list("Enemy");

	if (Enemy->size() == 0)
		return 2;

	//���� ������ ��ǥ�� �ִ� ���� ���ؼ� �⵿
	//Vector3 Enemy_Position  = Enemy->front()->Getposition();
	float Check = 1000.0f;
	Vector3 Temp;
	for (auto iter = Enemy->begin(); iter != Enemy->end(); ++iter)
	{
		float Test = MathManager::GetDistance(Info.Position, (*iter)->Getposition());
		if (Test < Check)
		{
			Check = Test;
			Temp = (*iter)->Getposition();
		}
	}


	Info.Direction = MathManager::GetDirection(
		Info.Position, Temp);

	Info.Position += Info.Direction;

	*/
	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Bullet::Render() 
{

	if (pBridge)
		pBridge->Render();
	

}

void Bullet::Release()
{
	::Safe_Delete(pBridge);
}