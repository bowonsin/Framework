#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "StageMenu.h"
//#include "Scene.h" -> 예는 추상클레스 이기 때문에 쓸 필요가 없다.
// 변수가 선언이 되어있으면 반드시 초기화는 해줘야한다.
SceneManager* SceneManager::Instance = nullptr; 

SceneManager::SceneManager() :Scene_Id(nullptr){}
SceneManager::~SceneManager() {}

void SceneManager::SetScene(SCENEID _Scene_Id)
{
	if (Scene_Id != nullptr)
		// :: 앞에 붙어 있는 이유는 인라인 함수라고 명시 하는 경우가 높아서 붙여둔다.
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
		// switch 추가해서 추가 STage 형식으로 
		break;
	case EXIT:
		exit(NULL);
		break;
	}
	Scene_Id->Initialize();// 주는건 따로 주고 break 를 받고 초기화
	/*
		Logo 로 들어오면 Logo의 데이터를 주고 
		그 에 관련된 Initialize 를 실행
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
