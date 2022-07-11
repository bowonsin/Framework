#pragma once
#include "Headers.h"
#include "Object.h"
#include "Bridge.h"

class Bridge;
template <typename T>
class ObjectFactory
{
public:
	static Object* CreateObject()
	{
		T* pObject = new T;
		pObject->Initialize("Bullet");

		return pObject;
	}
	static Object* CreateObject(float _x, float _y)
	{
		T* pObject = new T;
		pObject->Initialize("Bullet");

		pObject->Setposition(_x, _y);

		return pObject;
	}

	static Object* CreateObject(float _x, float _y, Bridge* _Bridge)
	{
		Object* pObject = new T;
		pObject->Initialize("Bullet");

		pObject->Setposition(_x, _y);

		_Bridge->Initialize();
		_Bridge->SetObject(pObject);


		pObject->SetBridge(pObject);



		return pObject;
	}
	static Object* CreateObject(Vector3 _Position)
	{
		T* pObject = new T;
		pObject->Initialize("Bullet");

		pObject->Setposition(_Position);

		return pObject;
	}
	static Object* CreateObject(Vector3 _Position, Bridge* _Bridge)
	{
		T* pObject = new T;
		pObject->Initialize("Bullet");

		pObject->Setposition(_Position);

		_Bridge->Initialize();
		_Bridge->SetObject(pObject);

		pObject->SetBridge(_Bridge);


		return pObject;
	}
};