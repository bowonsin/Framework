#pragma once
#include "Stage.h"
class Stage_1 :public Stage
{
public:
	virtual void Initialize()override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	void Regen_Enemy(string EnemyName);

	void Time_to_RegenMonster();

	virtual void Monster_Regein()override;

public:
	Stage_1();
	virtual ~Stage_1();
};

