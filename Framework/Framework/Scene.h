#pragma once
#include "Headers.h"

class Scene
{
public:
	virtual void Initialize()PURE; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	Scene();
	~Scene();
};