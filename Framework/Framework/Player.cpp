#include "Player.h"
#include "InputManager.h"

Player::Player()
	:Horizontal(0),Vertical(0){}
Player::~Player(){}

void Player::Initialize()
{
	Horizontal = 0;
	Vertical = 0;
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_UP)// Ű �Է��� �޴� �Լ� VK(VirtualKey_  ����)
		++Vertical;
	if (dwKey & KEY_DOWN)
		--Vertical;
	if (dwKey & KEY_LEFT)
		--Horizontal;
	if (dwKey & KEY_RIGHT)
		++Horizontal;
}

void Player::Render()
{
	cout << "X : " << Horizontal << endl << "Y : " << Vertical << endl;
}

void Player::Release()
{
}

