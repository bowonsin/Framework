#pragma once
#include "Headers.h"
class Object;
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
	void AddObject(Object* _Object);
	void AddObject(string str);

	list<Object*>* GetObject_list(string _Key);
	list<Object*>::iterator ThrowObject(list<Object*>::iterator _Where,Object* _Object);

	void Redner();
	void Update();
private:
	ObjectManager();
public:
	~ObjectManager();
	
};