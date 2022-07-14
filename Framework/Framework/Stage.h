#pragma once
#include "Scene.h"
class Object;
class Stage : public Scene
{
private:
	Object* pPlayer;
public:
	virtual void Initialize()PURE; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	Stage();
	virtual ~Stage();
};

