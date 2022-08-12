#pragma once
#include "UserInterface.h"

class ClearCheckInterface : public UserInterface
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual void OverCheck(bool Check)override;

private:
	vector<char*> Make_Box(int Font_Size);

private:
	int m_iStart;
	int m_iEnd;

public:
	ClearCheckInterface();
	virtual ~ClearCheckInterface();
};

