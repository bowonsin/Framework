#pragma once
#include "Bridge.h"
#include "Object.h"


class EnemyBridge : public Bridge
{
protected: 
	float m_iSpeed;
	int m_iColor;
	int m_iState_Time; // 그림 형태 
	int m_iShoting_Time;

	OBJECT_STATE m_eState;
	vector<Image_State> m_vecImageList;
	MONSTER_MOVING m_eMoving;

	ULONGLONG m_lTimer; // 시간 타이머

	virtual void InputImage(OBJECT_STATE State)PURE;
	virtual void Image_Initialize()PURE;
	
	virtual void Survival_Check(int Hp)PURE;

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release() { m_vecImageList.clear(); };
public:

	EnemyBridge() : m_iShoting_Time(0),m_iSpeed (0), m_iColor(0), m_eState(OBJECT_STATE::STATE_NORMAL),m_lTimer(0),m_iState_Time(0), m_eMoving(MONSTER_MOVING::MOVE_STOP) {}
	virtual  ~EnemyBridge() {}
};