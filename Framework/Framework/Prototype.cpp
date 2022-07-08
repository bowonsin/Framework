#include "Prototype.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include "InputManager.h"

Prototype* Prototype::Instance = nullptr ;

Prototype::Prototype() {}
Prototype::~Prototype() {}


void Prototype::Initialize()
{

	Trasnform Info;

	string Key = "Player";
	//((new Player(Info))->Initialize(Key) �� �ڽ��� �Ҵ��ϸ鼭 Initialize ���� �ϴ°�
	ProtoTypeList[Key] = (new Player(Info))->Initialize(Key);

	Key = "Enemy";
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "Bullet";
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);
}

Object* Prototype::ProtoTypeObject(string _Key)
{
	map<string, Object*>::iterator iter = ProtoTypeList.find(_Key);

	if (iter == ProtoTypeList.end())
		return nullptr;
	//ProtoTypeList
	return iter->second;
}

