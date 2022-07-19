#pragma once
#include "UserInterface.h"
class MenuInterface : public UserInterface
{
public:
	virtual void Initialize()override; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	void LocationCheck(Vector3& _Position,IMAGE_MOVE_DIRECTION Check);

	vector<char*> Make_Box();
	void ImageDraw(int Order);

public:
	MenuInterface();
	MenuInterface(Transform _info);
	virtual ~MenuInterface();
};

