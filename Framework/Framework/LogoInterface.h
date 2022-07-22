#pragma once
#include "UserInterface.h"
class LogoInterface : public UserInterface
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	vector<char*> Make_Box();

public:
	LogoInterface();
	LogoInterface(Transform _info);
	virtual ~LogoInterface();
};

