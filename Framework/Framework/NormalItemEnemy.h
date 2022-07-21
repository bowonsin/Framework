#pragma once
#include "EnemyBridge.h"
class NormalItemEnemy : public EnemyBridge
{
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void InputImage()override;

	virtual void MoveImage()override;
	virtual void DieImage()override;
public:

	NormalItemEnemy();
	virtual ~NormalItemEnemy();
};