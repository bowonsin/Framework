#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

	Enemy();
	virtual ~Enemy();
};

