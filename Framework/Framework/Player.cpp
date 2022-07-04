#include "Player.h"
#include "Bullet.h"

#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFActory.h"


Player::Player(){}
Player::Player(Trasnform _info):Object(_info){}
Player::~Player(){}

void Player::Initialize()
{
	strKey = "Player";

	Buffer[0] = (char*)"��";
	Buffer[1] = (char*)"��";

	TransInfo.Position = Vector3(20.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 2.0f);
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_UP)
		TransInfo.Position.y -=1;
	if (dwKey & KEY_DOWN)
		TransInfo.Position.y +=1;
	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 1;

	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x +=1;

	if (dwKey & KEY_SPACE)
		ObjectManager::GetInstance()->AddObject(ObjectFactory<Bullet>::CreateObject(TransInfo.Position));

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position, (char*)"ABCDEFG");

}
	//cout << "Player" << endl;
	//cout << "X : " << Horizontal << endl << "Y : " << Vertical << endl << endl;

void Player::Release()
{
}

