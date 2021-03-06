#include "Prototype.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BackGround.h"
#include "InputManager.h"

Prototype* Prototype::Instance = nullptr ;

Prototype::Prototype() {}
Prototype::~Prototype() {}


void Prototype::Initialize()
{

	Transform Info;

	string Key = "Player";
	//((new Player(Info))->Initialize(Key) 나 자신을 할당하면서 Initialize 같이 하는것
	ProtoTypeList[Key] = (new Player(Info))->Initialize(Key);

	Key = "NormalEnemy";
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "NormalItemEnemy";
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "NamedEnemy";
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "BossEnemy";
	ProtoTypeList[Key] = (new Enemy(Info))->Initialize(Key);

	Key = "Bullet";
	ProtoTypeList[Key] = (new Bullet(Info))->Initialize(Key);

	Key = "BackGround";
	ProtoTypeList[Key] = (new BackGround(Info))->Initialize(Key);
}

Object* Prototype::ProtoTypeObject(string _Key)
{
	map<string, Object*>::iterator iter = ProtoTypeList.find(_Key);

	if (iter == ProtoTypeList.end())
		return nullptr;
	//ProtoTypeList
	return iter->second;
}


