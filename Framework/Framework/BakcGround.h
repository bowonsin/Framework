#pragma once
#include "Object.h"
class BakcGround :public Object
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override	{	return new BakcGround(*this);}

	BakcGround();
	BakcGround(Trasnform _info);
	virtual ~BakcGround();
};

