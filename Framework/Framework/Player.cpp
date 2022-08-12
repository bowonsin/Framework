#include "Player.h"
#include "Bullet.h"

#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ObjectPool.h"
#include "Prototype.h"

#include "NormalBullet.h"




Player::Player():Speed(0),m_lTimer(0) , m_iTime_Count_Check(0), m_iColor(15), m_lBullet_timer(0),m_iPowerUp(0), m_iLife_Check(0){}
Player::Player(Transform _info):Object(_info){}
Player::~Player() { Release(); }

Object* Player::Initialize(string _Key)
{
	strKey = _Key;
	Hp = 10;
	
	Speed = 1.0f; // 속도 조절
	m_iTime_Count_Check = 0; // 시간 카운트 체크
	m_iColor = 15; // Player 색
	m_bCollision_Check = true; // 충돌 온 오프 체크 
	m_iPowerUp = 0;

	m_iLife_Check = 0;
	TransInfo.Position = Vector3(20.0f, 15.0f);
	ch_Buffer.push_back((char*)"＼―≥ ");
	ch_Buffer.push_back((char*)"｜￣￣￣＼＞");
	ch_Buffer.push_back((char*)"／￣￣￣￣");

	
	TransInfo.Scale = Vector3((float)strlen(ch_Buffer[0]), ch_Buffer.size() - 0.5f);
	m_lTimer = GetTickCount64();
	m_lBullet_timer = GetTickCount64();
	return this;
}


int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_UP && limit_Move_y(true))
		TransInfo.Position.y -= 1 * Speed;
	if (dwKey & KEY_DOWN && limit_Move_y(false))
		TransInfo.Position.y += 1* Speed;
	if (dwKey & KEY_LEFT && limit_Move_x(true))
		TransInfo.Position.x -= 1* Speed;
	if (dwKey & KEY_RIGHT && limit_Move_x(false))
		TransInfo.Position.x += 1* Speed;

	//if (dwKey & KEY_RIGHT && dwKey & 
	//{
	//	TransInfo.Position.x += 1;
	//	TransInfo.Position.y += 1;
	//}
	if (m_lBullet_timer + ( 800  - m_iPowerUp * 100 )< GetTickCount64())
	{
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
			m_lBullet_timer = GetTickCount64();
			Bridge* pBridge = new NormalBullet;
			ObjectManager::GetInstance()->AddObject_Bullet("NormalBullet", pBridge, TransInfo.Position);
		}
	}

	if (!m_bCollision_Check)
	{
		if (m_lTimer + 500 < GetTickCount64())// -> 파워 업 하면 공격 주기가 점점 짧아지게 하도록.
		{
			m_lTimer = GetTickCount64();
			if (m_iTime_Count_Check >= 4)
			{
				m_bCollision_Check = true;
				m_iTime_Count_Check = 0;
				m_iColor = 15;
			}
			++m_iTime_Count_Check;
		}
		//ObjectManager::GetInstance()->AddBullet( pBridge, TransInfo.Position);
	}

	return m_iLife_Check;
}

void Player::Render()
{
	for (int i = 0; i < ch_Buffer.size(); ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			TransInfo.Position.x,
			TransInfo.Position.y + i,
			ch_Buffer[i], m_iColor);
	}
}
	//cout << "Player" << endl;
	//cout << "X : " << Horizontal << endl << "Y : " << Vertical << endl << endl;

void Player::Release()
{
}

void Player::LifeCheck()
{
	--Hp;
	m_bCollision_Check = false;
	m_iColor = 12;
	if (Hp == 0)
		m_iLife_Check = BUFFER_OVER;
}
void Player::Power_Up()
{
	if (m_iPowerUp <= 5)
	{
		Speed += 0.5f;
		++m_iPowerUp;
	}
}
bool Player::limit_Move_x(bool Check)
{
 	if (Check && TransInfo.Position.x <= Player_Limit_x_Min + 2)
		return false;
	else if (!Check && TransInfo.Position.x >= InGameConsole_WidthSize - 2)
		return false;

	return true;
}

bool Player::limit_Move_y(bool Check)
{
	if (Check && TransInfo.Position.y <= 7)
		return false;
	else if (!Check && TransInfo.Position.y >= ConsoleHeightSize - 7)
		return false;

	return true ;
}
