#pragma once
#include "Object.h"
class Item :public Object
{
public:
	virtual Object* Initialize(string _Key)override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
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

