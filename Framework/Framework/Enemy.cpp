#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy(){}

Enemy::Enemy(Transform _info):Object(_info){}

Enemy::~Enemy(){}

Object* Enemy::Initialize(string _Key)
{
	strKey = "Enemy";

	Hp = 3;
	ch_Buffer.push_back((char*)"ȣ");
	ch_Buffer.push_back((char*)"��");

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen(ch_Buffer[0]), (float)MAX_SIZE);


	return this;
}

int Enemy::Update()
{
	//TransInfo.Position.x -= 2;
	// ���� �ð����� �÷��̾� �������� �Ѿ��� ���

	if (TransInfo.Position.x <= 0)
		return BUFFER_OVER;

	return 0;
}

void Enemy::Render()
{
	for (int i = 0; i < ch_Buffer.size(); ++i)
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			ch_Buffer[i], 12);

}

void Enemy::Release()
{
}