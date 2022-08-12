#pragma once
#include "Headers.h"

class Bridge;
class Object
{
protected:
	Transform TransInfo;
	string strKey;
	int Hp;
	bool m_bCollision_Check;
	vector<char*> ch_Buffer;

	Bridge* pBridge;
public:
	virtual Object* Initialize(string _Key)PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual void LifeCheck()PURE;
	virtual Object* Clone()PURE;
	void Unit_Hp_Setting(int _Hp) { Hp = _Hp; };

	virtual void Power_Up() {};
public:
	string GetKey() const { return strKey; }
	int GetHp() const { return Hp; }

	Vector3 Getposition() const { return TransInfo.Position; }
	void Setposition(Vector3 _Position) { TransInfo.Position = _Position; }

	Vector3 GetScale() const { return TransInfo.Scale; }
	void SetScale(Vector3 _Scale) { TransInfo.Scale = _Scale; }
	void Clear_z(float _z) { TransInfo.Scale.z = _z; };
	int Clear_z()const {return TransInfo.Scale.z;}

	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }

	bool Collision_Check()const { return m_bCollision_Check; }
	
public:
	Object();
	Object(Transform _info);
	virtual ~Object();
};

