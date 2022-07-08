#pragma once
#include "Object.h"
class Enemy : public Object
{
private:
public:
	virtual Object* Initialize(string _Key)override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override	{	return new Enemy(*this);}


	Enemy();
	Enemy(Trasnform _info);
	virtual ~Enemy();
};

