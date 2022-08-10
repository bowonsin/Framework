#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "ObjectPool.h"
#include "Prototype.h"
#include "Object.h"
#include "Bullet.h"
#include "Bridge.h"

ObjectManager* ObjectManager::Instance = nullptr;
ObjectManager::ObjectManager(){	EnableList = ObjectPool::GetEnableList();}
ObjectManager::~ObjectManager() { Release(); }

void ObjectManager::AddObject(string _Key) // 있는거 할성화 또는 만들어서 
{
	Object* pObject = ObjectPool::GetInstance()->Recycle(_Key);

	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->ProtoTypeObject(_Key)->Clone();


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

void ObjectManager::AddObject(string _Key, Bridge* _Bridge)
{
	Object* pObject = ObjectPool::GetInstance()->Recycle(_Key);

	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->ProtoTypeObject(_Key)->Clone();

	_Bridge->SetObject(pObject);
	_Bridge->Initialize();

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

void ObjectManager::Active_Unit(string _Key, Vector3 _SetPosition,int _Hp)
{

	Object* pObject = ObjectPool::GetInstance()->Recycle(_Key);
	
	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->ProtoTypeObject(_Key)->Clone();

	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);

	pObject->Setposition(_SetPosition);
	pObject->Unit_Hp_Setting(_Hp);

	if (iter == EnableList->end())
	{
		list<Object*> TempList;
		TempList.push_back(pObject);
		EnableList->insert(make_pair(pObject->GetKey(), TempList));
	}
	else
		iter->second.push_back(pObject);
	
}

void ObjectManager::AddObject_Bullet(string _Key, Bridge* _Bridge, Vector3 _Position)
{
	Object* pObject = ObjectPool::GetInstance()->Recycle(_Key);

	if (pObject == nullptr)
		pObject = Prototype::GetInstance()->ProtoTypeObject(_Key)->Clone();

	pObject->SetBridge(_Bridge);
	pObject->Setposition(_Position);

	_Bridge->SetObject(pObject);
	_Bridge->Initialize();

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

void ObjectManager::Release()
{
	for (auto iter = EnableList->begin(); iter != EnableList->end(); ++iter)
	{
		for (auto iter1 = iter->second.begin(); iter1 != iter->second.end(); ++iter1)
		{
			Object* Temp = (*iter1);
			iter1 = iter->second.erase(iter1);
			::Safe_Delete((Temp));
			if (iter1 == iter->second.end())
				iter = EnableList->erase(iter);
		}
	}
}
