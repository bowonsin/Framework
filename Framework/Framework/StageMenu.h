#pragma once
#include "Stage.h"
class StageMenu : public Stage
{
public:
	virtual void Initialize()override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:

	StageMenu();
	virtual ~StageMenu();
};

