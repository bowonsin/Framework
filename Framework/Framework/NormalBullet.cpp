#include "NormalBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectManager.h"

#include "Object.h"

NormalBullet::NormalBullet() {}
NormalBullet::~NormalBullet() { Release(); }

void NormalBullet::Initialize()
{
	// ** Bullet�� ������ �ʱ�ȭ

	Speed = 0.5f;
	Color = 12;
}

int NormalBullet::Update(Transform& Info)
{

	list<Object*>* Enemy = ObjectManager::GetInstance()->GetObject_list("Enemy");

	if (Enemy->size() == 0)
		return 2;

	//���� ������ ��ǥ�� �ִ� ���� ���ؼ� �⵿
	//Vector3 Enemy_Position  = Enemy->front()->Getposition();
	// ����ź �Լ�
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


	Info.Direction.x = 1;
	Info.Position += Info.Direction;
	
	//Info.Direction = MathManager::GetDirection(
	//	Info.Position, Vector3(60.0f, 15.0f));
	//
	//Info.Position += Info.Direction * Speed;
	

    return 0;
}

void NormalBullet::Render()
{
	for (int i = 0; i < 2; ++i)
		CursorManager::GetInstance()->WriteBuffer(
			pObject->Getposition().x,
			pObject->Getposition().y + i,
			(char*)"Bullet", Color);

//			���ۿ� �÷� �˾Ƽ� �޾ƿ���
}

void NormalBullet::Release()
{
}