#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	virtual Object* Initialize(string _Key)override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void LifeCheck()override;

	virtual Object* Clone()override	{ return new Enemy(*this);}

public:
	Enemy();
	Enemy(Transform _info);
	virtual ~Enemy();
};

