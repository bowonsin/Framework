#pragma once
#include "Headers.h"

class Object
{
protected:
	Trasnform TransInfo;
	string strKey;
public:
	virtual void Initialize()PURE; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE;

	string GetKey() const { return strKey; }

	Object();
	Object(Trasnform _info);
	virtual ~Object();
};

