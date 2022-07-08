#pragma once
#include "Object.h"
class Enemy : public Object
{
private:
public:
	virtual Object* Initialize(string _Key)override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override	{	return new Enemy(*this);}


	Enemy();
	Enemy(Trasnform _info);
	virtual ~Enemy();
};

