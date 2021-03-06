#pragma once
#include "BulletBridge.h"
class HomingBullet :public BulletBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void InputImage(OBJECT_STATE State)override;
public:

	HomingBullet();
	virtual ~HomingBullet();
};