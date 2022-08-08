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

	virtual void LifeCheck()PURE;

	virtual Object* Clone()PURE;
public:
	string GetKey() const { return strKey; }
	int GetHp() const { return Hp; }

	Vector3 Getposition() const { return TransInfo.Position; }
	void Setposition(Vector3 _Position) { TransInfo.Position = _Position; }

	Vector3 GetScale() const { return TransInfo.Scale; }
	void SetScale(Vector3 _Scale) { TransInfo.Scale = _Scale; }

	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
	
public:
	Object();
	Object(Transform _info);
	virtual ~Object();
};

