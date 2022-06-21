#include "Parent.h"
class Child : public Parent
{
public:
	void Initialize();
	// ** 공개된 상태
	void Output();
	void Update();
};