#include "ObjectPool.h"
#include "Object.h"
#include "CursorManager.h"

ObjectPool* ObjectPool::Instance = nullptr;
map<string, list<Object*>> ObjectPool::EnableList;

ObjectPool::ObjectPool()
{

}

ObjectPool::~ObjectPool()
{

}

void ObjectPool::CatchObject(Object* _Object)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Object->GetKey());

	if (Disableiter == DisableList.end())
	{
		list<Object*> TempList;
		TempList.push_back((_Object));
		DisableList.insert(make_pair((_Object)->GetKey(), TempList));
	}
	else
		Disableiter->second.push_back((_Object));
}

Object* ObjectPool::Recycle(string _Key)
{
	map<string, list<Object*>>::iterator Disableiter = DisableList.find(_Key);

	if (Disableiter != DisableList.end() && Disableiter->second.size())
	{
		list<Object*>::iterator EnableObject = Disableiter->second.begin();
		Object* Tmep = Disableiter->second.front();
		Disableiter->second.erase(EnableObject);
		return Tmep;
	}

	return nullptr;

}

void ObjectPool::Update() // 전체 업데이트 관리 
{
	//CursorManager::GetInstance()->WriteBuffer(85.0f, 0.0f, (char*)"DisableList : ");
	//CursorManager::GetInstance()->WriteBuffer(100.0f, 0.0f, DisableList["Bullet"].size());

	//CursorManager::GetInstance()->WriteBuffer(85.0f, 2.0f, (char*)"EnableList : ");
	//CursorManager::GetInstance()->WriteBuffer(100.0f, 2.0f, EnableList["Bullet"].size());

	//CursorManager::GetInstance()->WriteBuffer(10.0f, 10.0f);
	//CursorManager::GetInstance()->WriteBuffer(10.0f, 10.0f);

	for (map<string, list<Object*>>::iterator Enable = EnableList.begin();
		Enable != EnableList.end(); ++Enable)
	{
		for (list<Object*>::iterator iter2 = Enable->second.begin();
			iter2 != Enable->second.end(); )
		{
			int result = (*iter2)->Update();
			switch (result)
			{
			case BUFFER_OVER:
			{
				map<string, list<Object*>>::iterator Disableiter = DisableList.find((*iter2)->GetKey());

				if (Disableiter == DisableList.end())
				{
					list<Object*> TempList;
					TempList.push_back((*iter2));
					DisableList.insert(make_pair((*iter2)->GetKey(), TempList));
				}
				else
					Disableiter->second.push_back((*iter2));

				iter2 = (*Enable).second.erase(iter2); // 오류가 하나 있었내 
			}
			break;

			case 2: // 충돌 확인 
			{
				CursorManager::GetInstance()->WriteBuffer(50.0f, 1.0f, (char*)"충돌입니다.");

				iter2++;
				
				//map<string, list<Object*>>::iterator Disableiter = DisableList.find((*iter2)->GetKey());
				//iter2 = (*iter).second.erase(iter2);
			}
			break;

			default:
				++iter2;
			}
		}
	}
}


