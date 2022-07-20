#pragma once
#include "Headers.h"

class Bridge;
class Object
{
protected:
	Transform TransInfo;
	string strKey;
	int Hp;
	vector<char*> ch_Buffer;

	Bridge* pBridge;
public:
	virtual Object* Initialize(string _Key)PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual Object* Clone()PURE;
public:
	string GetKey() const { return strKey; }
	int GetHp() const { return Hp; }

	Vector3 Getposition() const { return TransInfo.Position; }
	void Setposition(float _x, float _y) { TransInfo.Position = Vector3(_x, _y); }
	void Setposition(Vector3 _Position) { TransInfo.Position = _Position; }

	Vector3 GetScale() const { return TransInfo.Scale; }
	void SetSacle(float _x, float _y) { TransInfo.Scale = Vector3(_x, _y); }

	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
public:
	Object();
	Object(Transform _info);
	virtual ~Object();
};

