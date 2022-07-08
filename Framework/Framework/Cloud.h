#pragma once
#include "Object.h"
class Cloud:public Object
{
private:
	vector<string> Texturevector;
public:
	virtual Object* Initialize(string _Key)override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Cloud(*this); }

	Cloud();
	Cloud(Trasnform _info);
	virtual ~Cloud();
};

