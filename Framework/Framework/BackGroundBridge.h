#pragma once
#include "Bridge.h"
class BackGroundBridge: public Bridge
{
protected:
	int m_iColor;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual void InputImage()PURE;
public:
	BackGroundBridge() :m_iColor(0){}
	virtual ~BackGroundBridge() {}
};

