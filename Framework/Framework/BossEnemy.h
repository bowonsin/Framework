#pragma once
#include "EnemyBridge.h"
class BossEnemy : public EnemyBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

private:
	virtual void InputImage(OBJECT_STATE State)override;

	virtual void Image_Initialize()override;

public:
	BossEnemy();
	virtual ~BossEnemy();
};