#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	Object* pObject;
	vector<char*> m_vecImage;
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& Info)PURE;
	virtual void Render()PURE;
	virtual void Release() { m_vecImage.clear(); ::Safe_Delete(pObject); };

public:
	void SetObject(Object* _Object)	{	pObject = _Object;	}
	virtual vector<char*> GetImageShape() const { return m_vecImage; }

	Vector3 Get_Scale(){ return Vector3(strlen(m_vecImage.front()) - 4, m_vecImage.size() - 2);}

public:
	Bridge() :pObject(nullptr) {}
	virtual ~Bridge() {}
};