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
	// -> ���⼭ ������Ʈ ���丮���� �׳� ���̷�Ʈ�� �ֱ� 
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


