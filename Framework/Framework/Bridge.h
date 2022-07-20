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
	virtual void Release()PURE;

	virtual void InputImage()PURE;

public:
	void SetObject(Object* _Object)	{	pObject = _Object;	}
	virtual vector<char*> GetImageShape() const { return m_vecImage; }

public:
	Bridge() :pObject(nullptr) {}
	virtual ~Bridge() {}
};