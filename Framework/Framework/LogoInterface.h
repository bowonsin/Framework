#pragma once
#include "UserInterface.h"
class LogoInterface : public UserInterface
{
public:
	virtual void Initialize()override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual vector<char*> Make_Box(int Font_Size)override;

public:
	LogoInterface();
	LogoInterface(Transform _info);
	virtual ~LogoInterface();
};

