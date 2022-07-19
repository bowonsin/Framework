#include "StageMenu.h"
#include "StageMenuInterface.h"
#include "InputManager.h"
#include "SceneManager.h"

StageMenu::StageMenu(): m_iSelect_Stage(0){}
StageMenu::~StageMenu() { Release(); }

void StageMenu::Initialize()
{
	UI = new StageMenuInterface;
	UI->Initialize();
	m_iSelect_Stage = 0;;
}

void StageMenu::Update()
{
	if (UI)
		UI->Update();
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RIGHT && m_iSelect_Stage != 4)
		++m_iSelect_Stage;
	else if (dwKey & KEY_LEFT && m_iSelect_Stage != 0)
		--m_iSelect_Stage;
	if (UI)
		UI->Update();
	if (dwKey & KEY_ENETER)
	{
		switch (m_iSelect_Stage)
		{
		case SCENEID::MENU:
			SceneManager::GetInstance()->SetScene(SCENEID::MENU);
			break;
		case SCENEID::STAGE_1:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE_1);
			break;
		case SCENEID::STAGE_2:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE_2);
			break;
		case SCENEID::STAGE_3:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE_3);
			break;
		default:
			SceneManager::GetInstance()->SetScene(SCENEID::MENU);
		}
	}

}

void StageMenu::Render()
{
	if (UI)
		UI->Render();
}

void StageMenu::Release()
{
	::Safe_Delete(UI);
}