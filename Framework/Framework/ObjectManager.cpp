#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager(){}

ObjectManager::~ObjectManager(){}

void ObjectManager::AddObject(Object* _Object)
{
	//ObjectList
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	if (iter == ObjectList.end())
	{
		list<Object*> TempList;
		TempList.push_back(_Object);
		ObjectList.insert(make_pair(_Object->GetKey(), TempList));
	}
	else
		iter->second.push_back(_Object);
}

void ObjectManager::Redner() // ¾È½áµÎ µÊ
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (list<Object*>::iterator iter2 = iter->second.begin();iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
}
void ObjectManager::Update()
{
	for (map<string, list<Object*>>::iterator iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
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
				++iter2

		}
}
list<Object*>* ObjectManager::GetObject_list(string _Key)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Key);
	if (iter == ObjectList.end())
		return nullptr;
	return &iter->second;
}