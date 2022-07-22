#pragma once
#include "UserInterface.h"
class ScoreInterface : public UserInterface
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	vector<char*> Make_Box(int Font_Size);

public:
	ScoreInterface();
	virtual ~ScoreInterface();
};

