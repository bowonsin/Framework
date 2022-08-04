#pragma once
#include "EnemyBridge.h"
class NamedEnemy : public EnemyBridge
{
public :
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

private:
	virtual void InputImage(OBJECT_STATE State)override;
	virtual void Image_Initialize()override;

	MONSTER_MOVING m_eMoving;
	int m_iState_Time;
public:
	NamedEnemy();
	virtual ~NamedEnemy();
};

