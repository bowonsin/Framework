#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "StageMenu.h"
#include "Stage_1.h"
#include "Stage_2.h"
#include "Stage_3.h"
//#include "Scene.h" -> ���� �߻�Ŭ���� �̱� ������ �� �ʿ䰡 ����.
// ������ ������ �Ǿ������� �ݵ�� �ʱ�ȭ�� ������Ѵ�.
SceneManager* SceneManager::Instance = nullptr; 

SceneManager::SceneManager() :Scene_Id(nullptr){}
SceneManager::~SceneManager() {}

void SceneManager::SetScene(SCENEID _Scene_Id)
{
	if (Scene_Id != nullptr)
		// :: �տ� �پ� �ִ� ������ �ζ��� �Լ���� ��� �ϴ� ��찡 ���Ƽ� �ٿ��д�.
		::Safe_Delete(Scene_Id);

	switch (_Scene_Id)
	{
	case SCENEID::LOGO:
		Scene_Id = new Logo;
		break;
	case SCENEID::MENU:
		Scene_Id = new Menu;
		break;
	case SCENEID::STAGE_MENU:
		Scene_Id = new StageMenu;
		//Scene_Id = new Stage;
		// switch �߰��ؼ� �߰� STage �������� 
		break;
	case SCENEID::STAGE_1:
		Scene_Id = new Stage_1;
		break;
	case SCENEID::STAGE_2:
		Scene_Id = new Stage_2;
		break;
	case SCENEID::STAGE_3:
		Scene_Id = new Stage_3;
		break;
	case SCENEID::EXIT:
		exit(NULL);
		break;
	}
	Scene_Id->Initialize();// �ִ°� ���� �ְ� break �� �ް� �ʱ�ȭ
	/*
		Logo �� ������ Logo�� �����͸� �ְ� 
		�� �� ���õ� Initialize �� ����
	*/
}

void SceneManager::Update()
{
	Scene_Id->Update();
}

void SceneManager::Render()
{
	Scene_Id->Render();
}

void SceneManager::Release()
{
	::Safe_Delete(Scene_Id);

}
