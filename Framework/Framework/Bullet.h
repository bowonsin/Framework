#pragma once
#include "Object.h"
class Bullet: public Object
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Bullet(*this); }

	Bullet();
	Bullet(Trasnform _info);
	virtual ~Bullet();
};
