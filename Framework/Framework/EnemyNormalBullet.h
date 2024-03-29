#pragma once
#include "BulletBridge.h"
class EnemyNormalBullet: public BulletBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:

	EnemyNormalBullet();
	virtual ~EnemyNormalBullet();
};

