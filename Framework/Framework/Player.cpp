#include "Player.h"
#include "Bullet.h"

#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ObjectPool.h"
#include "Prototype.h"

#include "NormalBullet.h"


Player::Player(){}
Player::Player(Transform _info):Object(_info){}
Player::~Player() { Release(); }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;
	Hp = 10;
	
	Speed = 3.0f;

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);

	ch_Buffer.push_back((char*)"＼―≥ ");
	ch_Buffer.push_back((char*)"｜￣￣￣＼＞");
	ch_Buffer.push_back((char*)"／￣￣￣￣");

	TransInfo.Scale = Vector3((float)strlen(ch_Buffer[0]), ch_Buffer.size() - 0.5f );
	m_lTimer = GetTickCount64();

	return this;
}


int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_UP)
		TransInfo.Position.y -= 1 * Speed;
	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += 1* Speed;
	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 1* Speed;
	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += 1* Speed;

	//if (dwKey & KEY_RIGHT && dwKey & 
	//{
	//	TransInfo.Position.x += 1;
	//	TransInfo.Position.y += 1;
	//}

	if (dwKey & KEY_SPACE)
	{
		/*
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
		*/
		if (m_lTimer + 600 < GetTickCount64())// -> 파워 업 하면 공격 주기가 점점 짧아지게 하도록.
		{
			m_lTimer = GetTickCount64();
			Bridge* pBridge = new NormalBullet;
			ObjectManager::GetInstance()->AddObject_Bullet("NormalBullet", pBridge, TransInfo.Position);
			//ObjectManager::GetInstance()->AddBullet( pBridge, TransInfo.Position);
		}
	}

	return 0;
}

void Player::Render()
{
	for (int i = 0; i < ch_Buffer.size(); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			ch_Buffer[i], 15);
	}
}
	//cout << "Player" << endl;
	//cout << "X : " << Horizontal << endl << "Y : " << Vertical << endl << endl;

void Player::Release()
{
}


