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
	map<string, list<Object*>> ObjectList;
public:
	void AddObject(Object* _Object);
	void Redner();
	void Update();
	list<Object*>* GetObject_list(string _Key);

private:
	ObjectManager();
public:
	~ObjectManager();
	
};