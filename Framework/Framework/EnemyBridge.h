#pragma once
#include "Bridge.h"


class EnemyBridge : public Bridge
{
protected: 
	int m_iSpeed;
	int m_iColor;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual void InputImage()PURE;
public:

	EnemyBridge() : m_iSpeed (0), m_iColor(0){}
	virtual  ~EnemyBridge() {}
};