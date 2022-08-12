#pragma once
#include "BulletBridge.h"
class HomingBullet :public BulletBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void Survival_Check(int Hp)override;

private:

	bool m_bSurvival_check;
	ULONGLONG m_lTimer;
public:

	HomingBullet();
	virtual ~HomingBullet();
};