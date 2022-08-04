#pragma once
#include "Headers.h"
class Object;
class Bridge;
class ObjectManager
{
private:
	static ObjectManager* Instance;

public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;

		return Instance;
	}
private:
	map<string, list<Object*>>* EnableList;
public:
	

	void AddObject(string str);
	void AddObject(string _Key, Bridge* _Bridge);
	void AddObject_Bullet(string _Key, Bridge* _Bridge, Vector3 _Position);

	list<Object*>* GetObject_list(string _Key);
	list<Object*>::iterator ThrowObject(list<Object*>::iterator _Where,Object* _Object);

	void Redner();
	void Update();
private:
	ObjectManager();
public:
	~ObjectManager();
	
};


