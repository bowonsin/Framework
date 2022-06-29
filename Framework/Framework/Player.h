#pragma once
#include "Object.h"
class Player : public Object
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Player(*this); }

	Player();
	Player(Trasnform _info);
	virtual ~Player();
};