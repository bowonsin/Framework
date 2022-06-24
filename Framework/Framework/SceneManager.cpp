#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
//#include "Scene.h" -> ���� �߻�Ŭ���� �̱� ������ �� �ʿ䰡 ����.
// ������ ������ �Ǿ������� �ݵ�� �ʱ�ȭ�� ������Ѵ�.
SceneManager* SceneManager::Instance = nullptr; 

SceneManager::SceneManager() :SceneState(nullptr){}
SceneManager::~SceneManager() {}

void SceneManager::SetScene(SCENEID _SceneState)
{
	if (SceneState != nullptr)
		// :: �տ� �پ� �ִ� ������ �ζ��� �Լ���� ��� �ϴ� ��찡 ���Ƽ� �ٿ��д�.
		::Safe_Delete(SceneState);

	switch (_SceneState)
	{
	case LOGO:
		SceneState = new Logo;
		break;
	case MENU:
		SceneState = new Menu;
		break;

	case STAGE:
		SceneState = new Stage;

		break;
	case EXIT:
		exit(NULL);
		break;
	}
	SceneState->Initialize();// �ִ°� ���� �ְ� break �� �ް� �ʱ�ȭ
	/*
		Logo �� ������ Logo�� �����͸� �ְ� 
		�� �� ���õ� Initialize �� ����
	*/
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	::Safe_Delete(SceneState);

}
