#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ObjectPool.h"
#include "Prototype.h"
#include "Object.h"
#include "Bullet.h"
#include "Bridge.h"

ObjectManager* ObjectManager::Instance = nullptr;
ObjectManager::ObjectManager()
{
	EnableList = ObjectPool::GetEnableList();
}
ObjectManager::~ObjectManager(){}

void ObjectManager::AddObject(string str)
{
	Object* pObject = ObjectPool::GetInstance()->Recycle(str);

	if (pObject == nullptr)
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

void ObjectManager::AddObject(string _Key, Bridge* _Bridge)
{
	Object* pObject = ObjectPool::GetInstance()->Recycle(_Key);

	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->ProtoTypeObject(_Key)->Clone();

	_Bridge->Initialize();
	_Bridge->SetObject(pObject);

	pObject->SetScale(_Bridge->Get_Scale());
	pObject->SetBridge(_Bridge);

	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
}

void ObjectManager::AddBullet(Bridge* _Bridge, Vector3 _Position)
{
	Object* pObject = ObjectPool::GetInstance()->Recycle("Bullet");

	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->ProtoTypeObject("Bullet")->Clone();

	_Bridge->Initialize();
	_Bridge->SetObject(pObject);

	pObject->SetBridge(_Bridge);
	pObject->Setposition(_Position);

	map<string, list<Object*>>::iterator iter = EnableList->find("Bullet");

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

void ObjectManager::Redner() // ¾È½áµÎ µÊ
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