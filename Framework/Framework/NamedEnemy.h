#pragma once
#include "EnemyBridge.h"
class NamedEnemy : public EnemyBridge
{
public :
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void InputImage()override;
public:
	NamedEnemy();
	virtual ~NamedEnemy();
};

