#pragma once
#include "Headers.h"
#include "Object.h"


template <typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		T* pObject = new T;
		pObject->Initialize();

		return pObject;
	}
	static Object* CreateObject(float _x, float _y)
	{
		T* pObject = new T;
		pObject->Initialize();

		pObject->Setposition(_x, _y);

		return pObject;
	}
	static Object* CreateObject(Vector3 _Position)
	{
		T* pObject = new T;
		//pObject->Initialize();

		pObject->Setposition(_Position);

		return pObject;
	}
};