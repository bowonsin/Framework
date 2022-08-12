#pragma once
#include "Stage.h"
class Stage_3 : public Stage
{
public:
	virtual void Initialize()override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	virtual void Time_to_RegenMonster()override;
public:
	Stage_3();
	virtual ~Stage_3();

};

