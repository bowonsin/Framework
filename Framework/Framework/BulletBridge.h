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

	int Console_OutSide_Check() 
	{
		if (pObject->Getposition().x  >= InGameConsole_WidthSize)
			return BUFFER_OVER;
		else if (pObject->Getposition().x <= 0)
			return BUFFER_OVER;
		if (pObject->Getposition().y >= (float)ConsoleHeightSize)
			return BUFFER_OVER;
		else if (pObject->Getposition().y <= 0)
			return BUFFER_OVER;

		return 0;
	}


public:
	BulletBridge() : Speed(0),Color(0) {}
	virtual ~BulletBridge() {}
};