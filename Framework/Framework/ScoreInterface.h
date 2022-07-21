#pragma once
#include "UserInterface.h"
class ScoreInterface : public UserInterface
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual vector<char*> Make_Box(int Font_Size)override;

public:
	ScoreInterface();
	virtual ~ScoreInterface();
};

