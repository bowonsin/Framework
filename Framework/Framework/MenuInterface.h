#pragma once
#include "UserInterface.h"
class MenuInterface : public UserInterface
{
public:
	virtual void Initialize()override; //PURE  순수 가상함수와 비슷 하게 작용 된다.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	int m_iSelectMenu;

	vector<char*> Make_Box();
	void ImageDraw(int Order);

public:
	MenuInterface();
	MenuInterface(Transform _info);
	virtual ~MenuInterface();
};

