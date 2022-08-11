#pragma once
#include "Headers.h"
#include "Object.h"

class Bridge
{
protected:
	Object* pObject;
	vector<char*> m_vecImage;

	int Console_OutSide_Check()
	{
		if (pObject->Getposition().x >= InGameConsole_WidthSize + 1)
			return BUFFER_OVER;
		else if (pObject->Getposition().x <= 0)
			return BUFFER_OVER;
		if (pObject->Getposition().y >= (float)ConsoleHeightSize)
			return BUFFER_OVER;
		else if (pObject->Getposition().y <= 0)
			return BUFFER_OVER;

		return 0;
	}

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release() { m_vecImage.clear();};
	virtual void Survival_Check(int Hp)PURE;

public:
	void SetObject(Object* _Object)	{	pObject = _Object;	}
	Vector3 Get_Scale() { return Vector3(strlen(m_vecImage.front()), m_vecImage.size()); }
	

	virtual vector<char*> GetImageShape() const { return m_vecImage; } // ???? ³ª ÀÌ°Å ¿Ö¾¸?

public:
	Bridge() :pObject(nullptr) {}
	virtual ~Bridge() { Release(); }
};