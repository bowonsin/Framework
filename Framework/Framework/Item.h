#pragma once
#include "Object.h"
class Item :public Object
{
public:
	virtual Object* Initialize(string _Key)override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void LifeCheck()override;
	virtual Object* Clone()override { return new Item(*this); }

private:
	void Input_Image();
	int Console_Out_Check();
public:
	Item();
	Item(Transform _Info);
	virtual ~Item();
};

