#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectManager.h"

#include "Object.h"

NormalBullet::NormalBullet() {}
NormalBullet::~NormalBullet() { Release(); }

void NormalBullet::Initialize()
{
	// ** Bullet의 데이터 초기화

	Speed = 0.5f;
	Color = 12;
}

int NormalBullet::Update(Transform& Info)
{

	list<Object*>* Enemy = ObjectManager::GetInstance()->GetObject_list("Enemy");

	if (Enemy->size() == 0) // 적이 하나도 없으면 바로 delete 인거 같다.
		return 2;

	/*
	//가장 가까이 좌표에 있는 적을 향해서 출동
	// 유도탄 함수
	//Vector3 Enemy_Position  = Enemy->front()->Getposition();
	//float Check = 1000.0f;
	//Vector3 Temp;
	//for (auto iter = Enemy->begin(); iter != Enemy->end(); ++iter)
	//{
	//	float Test = MathManager::GetDistance(Info.Position, (*iter)->Getposition());
	//	if (Test < Check)
	//	{
	//		Check = Test;
	//		Temp = (*iter)->Getposition();
	//	}
	//}
	//Info.Direction = MathManager::GetDirection(
	//	Info.Position, Temp);
	*/

	Info.Direction.x = 1;
	Info.Position += Info.Direction;
	
	//Info.Direction = MathManager::GetDirection(Info.Position, Vector3(60.0f, 15.0f));
	//Info.Position += Info.Direction * Speed;
	
    return BulletBridge::Console_OutSide_Check();
}

void NormalBullet::Render()
{
	for (int i = 0; i < 2; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			pObject->Getposition().x,
			pObject->Getposition().y + i,
			(char*)"Bullet", Color);

//			버퍼와 컬러 알아서 받아오기
}

void NormalBullet::Release()
{
}