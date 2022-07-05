#include "ObjectManager.h"
#include "ObjectPool.h"
#include "Object.h"

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

void ObjectManager::Redner() // �Ƚ�� ��
{
	for (map<string, list<Object*>>::iterator iter = EnableList->begin(); iter != EnableList->end(); ++iter)
		for (list<Object*>::iterator iter2 = iter->second.begin();iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
}
void ObjectManager::Update()
{
	for (map<string, list<Object*>>::iterator iter = EnableList->begin(); iter != EnableList->end(); ++iter)
		for (list<Object*>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end();)
		{
			int result = (*iter2)->Update();


			if (result == BUFFER_OVER)
			{
				Object* Temp = *iter2;
				iter2 = iter->second.erase(iter2);
				delete Temp;
				Temp = nullptr;
			}
			else
				++iter2;
		}
}
list<Object*>* ObjectManager::GetObject_list(string _Key)
{
	map<string, list<Object*>>::iterator iter = EnableList->find(_Key);
	if (iter == EnableList->end())
		return nullptr;
	return &iter->second;
}