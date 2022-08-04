#pragma once
#include "BulletBridge.h"
class EnemyHomginBullet :public BulletBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
public:

	EnemyHomginBullet();
	virtual ~EnemyHomginBullet();
};