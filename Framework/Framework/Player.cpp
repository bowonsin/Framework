#include "Player.h"
#include "Bullet.h"

#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ObjectPool.h"
#include "Prototype.h"


Player::Player(){}
Player::Player(Trasnform _info):Object(_info){}
Player::~Player(){}

Object* Player::Initialize(string _Key)
{
	strKey = "Player";
	Hp = 10;

	Buffer[0] = (char*)"¿À";
	Buffer[1] = (char*)"¤µ";

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);

	Speed = 1.0f;
	
	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_UP)
		TransInfo.Position.y -= Speed;
	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += Speed;
	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= Speed;
	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += Speed;

	if (dwKey & KEY_SPACE)
	{
		Object* BulletRe;
		if (ObjectPool::GetInstance()->Getlist("Bullet")->size() <= 2)
		{
			BulletRe = Prototype::GetInstance()->ProtoTypeObject("Bullet")->Clone();
			BulletRe->Setposition(TransInfo.Position);
			ObjectManager::GetInstance()->AddObject(BulletRe);
		}
		else
		{
			BulletRe =  ObjectPool::GetInstance()->Recycle("Bullet");
			BulletRe->Setposition(TransInfo.Position);
			ObjectManager::GetInstance()->AddObject(BulletRe);
		}

	}

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position, (char*)"Player");

}
	//cout << "Player" << endl;
	//cout << "X : " << Horizontal << endl << "Y : " << Vertical << endl << endl;

void Player::Release()
{
}

