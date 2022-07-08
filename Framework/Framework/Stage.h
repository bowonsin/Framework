#pragma once
#include "Scene.h"
class Object;
class UserInterface;
class Stage : public Scene
{
private:
	UserInterface* pUI;
	Object* pPlayer;
	int Check;
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	void Enable_UI();

	Stage();
	virtual ~Stage();
};

