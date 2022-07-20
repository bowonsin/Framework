#pragma once
#include "Object.h"
class BackGround_Up : public Object
{
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new BackGround_Up(*this); }

	BackGround_Up();
	BackGround_Up(Transform _Info);
	virtual ~BackGround_Up();
};