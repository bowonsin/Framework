#pragma once
#include "Parent.h"
class Bullet : public Parent
{
public:
	void Initialize();
	// ** 공개된 상태
	void Output();
	void Update();
};

