#include "Bullet.h"

#include "ObjectManager.h"
#include "CollisionManager.h"

#include "Bridge.h"

Bullet::Bullet() {}

Bullet::Bullet(Transform _info) :Object(_info) {}
Bullet::~Bullet() {}

Object* Bullet::Initialize(string _Key)
{
	strKey = _Key;

	Hp = 1;
	ch_Buffer.push_back((char*)"＼");
	ch_Buffer.push_back((char*)"／");

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, .0f);
	TransInfo.Scale = Vector3(0.5f,0.5f);

	TransInfo.Direction = Vector3(0.0f, 0.0f);

	// 타겟으로 부터 내 좌표를 빼면 됨


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

	//가장 가까이 좌표에 있는 적을 향해서 출동
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
		return pBridge->Update(TransInfo);
	
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

void Bullet::LifeCheck()
{
	if (pBridge)
		pBridge->Survival_Check(0);
}
