#pragma once
#include "Object.h"
class BackGround :public Object
{
public:
	virtual Object* Initialize(string _Key)override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void LifeCheck()override;
	virtual Object* Clone()override	{	return new BackGround(*this);}
private: //Background �� map �� ���Ե� List�� ���� �ϴµ� BackGround�Ŵ����� ���� �����ϴ°��� ���ƺ��δ�.

public:
	BackGround();
	BackGround(Transform _info);
	virtual ~BackGround();
};