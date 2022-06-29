#include "Player.h"
#include "Bullet.h"

#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"


Player::Player(){}
Player::Player(Trasnform _info):Object(_info){}
Player::~Player(){}

void Player::Initialize()
{
	strKey = "AA";

	TransInfo.Position = Vector3(10.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 5.0f);
	TransInfo.Sacle = Vector3(2.0f, 2.0f);

	Buffer[0] = (char*)'오';
	Buffer[1] = (char*)'ㅅ';
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_UP)// 키 입력을 받는 함수 VK(VirtualKey_  방향)
		TransInfo.Position.y -=1;
	if (dwKey & KEY_DOWN)
		TransInfo.Position.y +=1;
	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x +=1;

	if (dwKey & KEY_SPACE)
	{
		Object* pBullet = new Bullet;
		pBullet->Initialize();
		pBullet->Setposition(TransInfo.Position);

		ObjectManager::GetInstance()->AddObject(pBullet);
	}
	return 0;
}

void Player::Render()
{

	for (int i = 0; i < 2; ++i)
	{
		CursorManager::Draw(
			TransInfo.Position.x - (TransInfo.Sacle.x * 0.5f),
			TransInfo.Position.y - (TransInfo.Sacle.y * 0.5f),
			Buffer[i]);
	}


	//cout << "Player" << endl;
	//cout << "X : " << Horizontal << endl << "Y : " << Vertical << endl << endl;
}

void Player::Release()
{
}

