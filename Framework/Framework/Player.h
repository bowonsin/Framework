#pragma once
#include "Object.h"
class Player : public Object
{
public:
	virtual Object* Initialize(string _Key)override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void LifeCheck()override;
	virtual Object* Clone()override { return new Player(*this); }

	virtual void Power_Up();

private:
	
	int m_iLife_Check;

	float Speed;
	ULONGLONG m_lTimer;
	ULONGLONG m_lBullet_timer;

	int m_iPowerUp;
	int m_iTime_Count_Check;
	int m_iColor;
	bool limit_Move_x(bool Check);
	bool limit_Move_y(bool Check);

public:
	Player();
	Player(Transform _info);
	virtual ~Player();
};


