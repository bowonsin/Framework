#pragma once
#include "Object.h"
class BakcGround :public Object
{
public:
	virtual Object* Initialize(string _Key)override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override	{	return new BakcGround(*this);}

	BakcGround();
	BakcGround(Transform _info);
	virtual ~BakcGround();
};

