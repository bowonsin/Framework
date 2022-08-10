#pragma once
#include "Object.h"
class BackGround :public Object
{
public:
	virtual Object* Initialize(string _Key)override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void LifeCheck()override;
	virtual Object* Clone()override	{	return new BackGround(*this);}
private: //Background 는 map 에 포함된 List로 관리 하는데 BackGround매니저를 만들어서 관리하는것이 좋아보인다.

public:
	BackGround();
	BackGround(Transform _info);
	virtual ~BackGround();
};