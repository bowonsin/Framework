#pragma once
#include "Bridge.h"
#include "Object.h"

class BulletBridge : public Bridge
{
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
protected:
	// ** Bullet의 데이터만 남음
	float Speed;
	int Color;
	Vector3 Target_Direction;

	virtual void Survival_Check()override {};


public:
	BulletBridge() : Speed(0),Color(0) {}
	virtual ~BulletBridge() {}
};