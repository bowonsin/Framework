#pragma once
#include "Bridge.h"
#include "Object.h"


class EnemyBridge : public Bridge
{
protected: 
	float m_iSpeed;
	int m_iColor;
	OBJECT_STATE m_eState;
	vector<Image_State> m_vecImageList;

	virtual void InputImage(OBJECT_STATE State)PURE;
	virtual void Image_Initialize()PURE;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:

	EnemyBridge() : m_iSpeed (0), m_iColor(0), m_eState(OBJECT_STATE::STATE_NORMAL){}
	virtual  ~EnemyBridge() {}
};