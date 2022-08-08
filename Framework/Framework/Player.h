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

private:
	
	float Speed;
	ULONGLONG m_lTimer;

	bool limit_Move_x(bool Check);

public:
	Player();
	Player(Transform _info);
	virtual ~Player();
};


