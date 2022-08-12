#include "StageMenu.h"
#include "StageMenuInterface.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ScoreInterface.h"

StageMenu::StageMenu(): m_iSelect_Stage(0), m_iStage_unlock(1){}
StageMenu::~StageMenu() { Release(); }

void StageMenu::Initialize()
{

	UI = new StageMenuInterface;
	UI->Initialize();
	OutSide_UI = new ScoreInterface;
	OutSide_UI->Initialize();
	
	m_iSelect_Stage = STAGE_MENU::SELECT_EXIT;
}

void StageMenu::Update()
{
	
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP && m_iSelect_Stage != STAGE_MENU::SELECT_STAGE_3)
	{
		if (m_iSelect_Stage == STAGE_MENU::SELECT_EXIT)
			m_iSelect_Stage = STAGE_MENU::SELECT_STAGE_1;
		else if (m_iSelect_Stage == STAGE_MENU::SELECT_STAGE_1)
			m_iSelect_Stage = STAGE_MENU::SELECT_STAGE_2;
		else if (m_iSelect_Stage == STAGE_MENU::SELECT_STAGE_2)
			m_iSelect_Stage = STAGE_MENU::SELECT_STAGE_3;
	}
	else if (dwKey & KEY_DOWN && m_iSelect_Stage != STAGE_MENU::SELECT_EXIT)
	{
		if (m_iSelect_Stage == STAGE_MENU::SELECT_STAGE_1)
			m_iSelect_Stage = STAGE_MENU::SELECT_EXIT;
		else if (m_iSelect_Stage == STAGE_MENU::SELECT_STAGE_2)
			m_iSelect_Stage = STAGE_MENU::SELECT_STAGE_1;
		else if (m_iSelect_Stage == STAGE_MENU::SELECT_STAGE_3)
			m_iSelect_Stage = STAGE_MENU::SELECT_STAGE_2;
	}

	if (UI)
		UI->Update();
	if (OutSide_UI)
		OutSide_UI->Update();

	if (dwKey & KEY_ENETER)
	{
		switch (m_iSelect_Stage)
		{
		case STAGE_MENU::SELECT_EXIT:
			SceneManager::GetInstance()->SetScene(SCENEID::MENU);
			break;
		case STAGE_MENU::SELECT_STAGE_1:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE_1);
			break;
		case STAGE_MENU::SELECT_STAGE_2:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE_2);
			break;
		case STAGE_MENU::SELECT_STAGE_3:
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
	if (OutSide_UI)
		OutSide_UI->Render();
}

void StageMenu::Release()
{
	::Safe_Delete(UI);
	::Safe_Delete(OutSide_UI);
}