#pragma once
#include "Scene.h"
class StageMenu :public Scene
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	int m_iSelect_Stage;

public:
	StageMenu();
	virtual ~StageMenu();
};

