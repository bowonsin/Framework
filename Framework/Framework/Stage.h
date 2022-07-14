#pragma once
#include "Scene.h"
class Object;
class Stage : public Scene
{
private:
	Object* pPlayer;
public:
	virtual void Initialize()PURE; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	Stage();
	virtual ~Stage();
};

