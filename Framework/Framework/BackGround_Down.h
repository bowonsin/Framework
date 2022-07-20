#pragma once
#include "Object.h"
class BackGround_Down : public Object
{
public:
	virtual Object* Initialize(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new BackGround_Down(*this); }

	BackGround_Down();
	virtual ~BackGround_Down();
};
