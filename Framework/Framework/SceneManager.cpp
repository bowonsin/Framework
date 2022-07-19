#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "StageMenu.h"
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
	case LOGO:
		Scene_Id = new Logo;
		break;
	case MENU:
		Scene_Id = new Menu;
		break;

	case STAGE:
		//Scene_Id = new StageMenu;
		Scene_Id = new Stage;
		// switch �߰��ؼ� �߰� STage �������� 
		break;
	case EXIT:
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
