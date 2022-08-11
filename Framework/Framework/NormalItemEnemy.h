#pragma once
#include "EnemyBridge.h"
class NormalItemEnemy : public EnemyBridge
{
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual void Survival_Check(int Hp)override;

private:
	virtual void InputImage(OBJECT_STATE State)override;
	virtual void Image_Initialize()override;
	virtual void Shoot_Bullet()override;

public:

	NormalItemEnemy();
	virtual ~NormalItemEnemy();
};