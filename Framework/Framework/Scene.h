#pragma once
#include "Headers.h"
class UserInterface;
class Scene
{
public:
	virtual void Initialize()PURE; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

protected:
	UserInterface* Clear_Ui;
	UserInterface* OutSide_UI;
	UserInterface* UI;


public:
	Scene();
	virtual ~Scene();
};