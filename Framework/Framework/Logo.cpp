#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Prototype.h"
#include "LogoInterface.h"


Logo::Logo(){}
Logo::~Logo(){}

void Logo::Initialize()
{

	UI= new LogoInterface;
	UI->Initialize();

	//Object* pEnemy= new Enemy;
	//pEnemy->Initialize();
	//ObjectManager::GetInstance()->AddObject(pEnemy);
	// -> ���⼭ ������Ʈ ���丮���� �׳� ���̷�Ʈ�� �ֱ� 
	//SceneManager::GetInstance()->SetScene(STAGE);

}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_ENETER)
		SceneManager::GetInstance()->SetScene(MENU);
}

void Logo::Render()
{
	UI->Render();
}

void Logo::Release()
{
}


