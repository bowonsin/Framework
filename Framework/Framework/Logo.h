#pragma once
#include "Scene.h"

class UserInterface;
class Logo :public Scene
{
public:
	virtual void Initialize()override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:

	
public:
	Logo();
	virtual ~Logo();
};

