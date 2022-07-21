#pragma once
#include "Bridge.h"
#include "Object.h"


class EnemyBridge : public Bridge
{
protected: 
	float m_iSpeed;
	int m_iColor;

	ENEMY_STATE m_eState;

	
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual void InputImage()PURE;

	virtual void MoveImage()PURE;
	virtual void DieImage()PURE;
	
	
public:

	EnemyBridge() : m_iSpeed (0), m_iColor(0), m_eState(ENEMY_STATE::STATE_NORMAL){}
	virtual  ~EnemyBridge() {}
};