#pragma once
#include "Stage.h"
class Stage_1 :public Stage
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;


public:
	Stage_1();
	virtual ~Stage_1();
};

