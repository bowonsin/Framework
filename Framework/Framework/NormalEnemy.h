#pragma once
#include "EnemyBridge.h"
class NormalEnemy : public EnemyBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual void Survival_Check()override;

private:
	virtual void InputImage(OBJECT_STATE State)override;
	virtual void Image_Initialize()override;

	virtual void Shoot_Bullet()override;

	float m_iUpDown;
	bool m_bUpDown;

	

public:
	NormalEnemy();
	virtual ~NormalEnemy();
};