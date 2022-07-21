#pragma once
#include "BackGroundBridge.h"
class BackGround_Bridge_Up : public BackGroundBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void InputImage()override;
public:
	BackGround_Bridge_Up();
	virtual ~BackGround_Bridge_Up();
};

