#include "Bullet.h"

void Bullet::Initialize()
{
	m_Number = 10;
}

void Bullet::Output()
{
	cout << m_Number << endl;
}

void Bullet::Update()
{
	m_Number += 100;
}
