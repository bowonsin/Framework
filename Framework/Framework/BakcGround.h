#pragma once
#include "Object.h"
class BakcGround :public Object
{
public:
	virtual Object* Initialize(string _Key)override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override	{	return new BakcGround(*this);}
private: //Background 는 map 에 포함된 List로 관리 하는데 BackGround매니저를 만들어서 관리하는것이 좋아보인다.
	vector<char*> GroundOne;
	Transform GroundOne_Info;

	vector<char*> GroundTwo;
	Transform GroundTwo_Info;

public:
	BakcGround();
	BakcGround(Transform _info);
	virtual ~BakcGround();
};

