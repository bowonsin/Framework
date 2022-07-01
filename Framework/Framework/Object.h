#pragma once
#include "Headers.h"

class Object
{
protected:
	Trasnform TransInfo;
	string strKey;

	char* Buffer[2];
public:
	virtual void Initialize()PURE; 
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;

	string GetKey() const { return strKey; }

	Vector3 Getposition() const { return TransInfo.Position; }
	void Setposition(float _x, float _y) { TransInfo.Position = Vector3(_x, _y); }
	void Setposition(Vector3 _Position) { TransInfo.Position = _Position; }

	Vector3 GetScale() const { return TransInfo.Scale; }
	void SetSacle(float _x, float _y) { TransInfo.Scale = Vector3(_x, _y); }


	Object();
	Object(Trasnform _info);
	virtual ~Object();
};

