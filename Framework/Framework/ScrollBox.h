#pragma once
#include "UserInterface.h"
class ScrollBox : public UserInterface
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;


	ScrollBox();
	ScrollBox(Transform _info);
	virtual ~ScrollBox();
};

