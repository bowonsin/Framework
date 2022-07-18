#pragma once
#include "BulletBiridge.h"
class HomingBullet :public BulletBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

public:

	HomingBullet();
	virtual ~HomingBullet();
};