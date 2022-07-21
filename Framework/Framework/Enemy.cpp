#include "Enemy.h"
#include "CursorManager.h"

#include "Bridge.h"

Enemy::Enemy(){}
Enemy::Enemy(Transform _info):Object(_info){}
Enemy::~Enemy(){}

Object* Enemy::Initialize(string _Key)
{
	strKey = _Key;

	Hp = 3;
	ch_Buffer.push_back((char*)"ȣ");
	ch_Buffer.push_back((char*)"��");

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen(ch_Buffer[0]), (float)MAX_SIZE);


	if (pBridge)
		pBridge->Initialize();
	return this;
}

int Enemy::Update()
{
	//TransInfo.Position.x -= 2;
	// ���� �ð����� �÷��̾� �������� �Ѿ��� ���

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	if (pBridge)
		pBridge->Update(TransInfo);

	return 0;
}

void Enemy::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Enemy::Release()
{
}