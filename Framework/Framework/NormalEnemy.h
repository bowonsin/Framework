#pragma once
#include "EnemyBridge.h"
class NormalEnemy : public EnemyBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void InputImage()override;

	virtual void MoveImage()override;
	virtual void DieImage()override;
public:
	NormalEnemy();
	virtual ~NormalEnemy();
};