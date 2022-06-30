#pragma once
#include "Object.h"
class BakcGround :public Object
{
public:
	virtual void Initialize()override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override	{	return new BakcGround(*this);}

	BakcGround();
	BakcGround(Trasnform _info);
	virtual ~BakcGround();
};

