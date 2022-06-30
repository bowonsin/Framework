#pragma once
#include "Scene.h"
class Object;
class Stage : public Scene
{
private:
	list<Object*>* pEnemyList;
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	Stage();
	virtual ~Stage();
};
