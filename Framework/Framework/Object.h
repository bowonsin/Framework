#pragma once
#include "Headers.h"

class Object
{
protected:
	Trasnform TransInfo;
	string strKey;
public:
	virtual void Initialize()PURE; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Object* Clone()PURE;

	string GetKey() const { return strKey; }

	Object();
	Object(Trasnform _info);
	virtual ~Object();
};

