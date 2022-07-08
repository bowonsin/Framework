#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ObjectPool.h"
#include "Prototype.h"
#include "Object.h"
#include "Bullet.h"

ObjectManager* ObjectManager::Instance = nullptr;
ObjectManager::ObjectManager()
{
	EnableList = ObjectPool::GetEnableList();
}
ObjectManager::~ObjectManager(){}

void ObjectManager::AddObject(Object* _Object)
{
	//ObjectList
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		EnableList->insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object);
}

void ObjectManager::AddObject(string str)
{
	Object* pObject = ObjectPool::GetInstance()->Recycle(str);

	if (pObject == nullptr)// Bullet 은 임의로 작성 
		pObject = Prototype::GetInstance()->ProtoTypeObject(str)->Clone();


	map<string, list<Object*>>::iterator iter = EnableList->find(str);

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

list<Object*>* ObjectManager::GetObject_list(string _Key)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);
	if (iter == EnableList->end())
		return nullptr;

	return &iter->second;
}

list<Object*>::iterator ObjectManager::ThrowObject(list<Object*>::iterator _Where, Object* _Object)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_Object->GetKey());
	 
	if (iter == EnableList->end())
		return _Where;

	ObjectPool::GetInstance()->CatchObject(_Object);
	return iter->second.erase(_Where);
}

void ObjectManager::Redner() // 안써두 됨
{
	for (map<string, list<Object*>>::iterator iter = EnableList->begin();
		iter != EnableList->end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}
void ObjectManager::Update()
{
	ObjectPool::GetInstance()->Update();
}