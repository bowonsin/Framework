#pragma once
#include "Stage.h"
class Stage_1 :public Stage
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	virtual void Regen_Enemy(string EnemyName, Vector3 _Position,int Monster_Hp)override;

	virtual void Time_to_RegenMonster()override;

public:
	Stage_1();
	virtual ~Stage_1();
};

