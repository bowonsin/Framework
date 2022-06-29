#pragma once
#include "Headers.h"

class Object
{
protected:
	Trasnform TransInfo;
	string strKey;

	char* Buffer[2];
public:
	virtual void Initialize()PURE; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;

	string GetKey() const { return strKey; }

	Vector3 Getposition() const { return TransInfo.Position; }
	void Setposition(float _x, float _y) { TransInfo.Position = Vector3(_x, _y); }
	void Setposition(Vector3 _Position) { TransInfo.Position = _Position; }

	Vector3 GetScale() const { return TransInfo.Sacle; }
	void SetSacle(float _x, float _y) { TransInfo.Sacle= Vector3(_x, _y); }


	Object();
	Object(Trasnform _info);
	virtual ~Object();
};

