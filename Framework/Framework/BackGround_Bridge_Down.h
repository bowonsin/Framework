#pragma once
#include "BackGroundBridge.h"
class BackGround_Bridge_Down : public BackGroundBridge
{
public:
	virtual void Initialize()override;
	virtual int Update(Transform& Info)override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void InputImage()override;
public:
	BackGround_Bridge_Down();
	virtual ~BackGround_Bridge_Down();
};

