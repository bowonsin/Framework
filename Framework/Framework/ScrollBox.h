#pragma once
#include "UserInterface.h"
class ScrollBox : public UserInterface
{
public:
	virtual void Initialize()override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;


	ScrollBox();
	ScrollBox(Transform _info);
	virtual ~ScrollBox();
};

