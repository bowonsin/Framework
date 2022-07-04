#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFActory.h"

#include "Player.h"
#include "Enemy.h"


Logo::Logo(){}
Logo::~Logo(){}

void Logo::Initialize()
{

	//Object* pEnemy= new Enemy;
	//pEnemy->Initialize();
	//ObjectManager::GetInstance()->AddObject(pEnemy);
	// -> 여기서 오브젝트 팩토리르로 그냥 다이렉트로 넣기 
	ObjectManager::GetInstance()->AddObject(ObjectFactory<Player>::CreateObject());
	SceneManager::GetInstance()->SetScene(STAGE);

}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_ENETER)
		SceneManager::GetInstance()->SetScene(MENU);
}

void Logo::Render()
{
	cout << "Logo" << endl;
}

void Logo::Release()
{
}


