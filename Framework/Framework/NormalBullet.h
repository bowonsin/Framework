#pragma once

#include "BulletBridge.h"
class NormalBullet :public BulletBridge
{
protected:
	// ** Bullet�� �����͸� ����
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

public:

	NormalBullet();
	virtual ~NormalBullet();
};