#pragma once
#include "Stage.h"
class Stage_2 :public Stage
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	virtual void Time_to_RegenMonster()override;

public:
	Stage_2();
	virtual ~Stage_2();
};