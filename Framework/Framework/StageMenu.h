#pragma once
#include "Stage.h"
class StageMenu : public Stage
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:

	StageMenu();
	virtual ~StageMenu();
};

