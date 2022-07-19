#pragma once
#include "UserInterface.h"
class StageMenuInterface : public UserInterface
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

private:
	int m_iSelectStage;
	void Location_Check(Vector3 & _Position, IMAGE_MOVE_DIRECTION Check);

	vector<char*> Make_Box(int Font_Size);
	void ImageDraw(int order);
public:
	StageMenuInterface();
	StageMenuInterface(Transform _info);
	virtual ~StageMenuInterface();
};