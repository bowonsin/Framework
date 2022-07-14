#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "MenuInterface.h"

Menu::Menu() : m_iSelectMenu(0){}
Menu::~Menu() { Release(); }

void Menu::Initialize()
{
	UI = new MenuInterface;
	UI->Initialize();
	m_iSelectMenu = 0;
}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (m_iSelectMenu <= 0 && (dwKey & KEY_RIGHT))
		++m_iSelectMenu;
	else if (m_iSelectMenu >= 1 && (dwKey & KEY_LEFT)) //Menu 갯수가 추가될수록 늘리기
		--m_iSelectMenu;
	UI->Update();
	if (dwKey & KEY_ENETER)
	{
		switch (m_iSelectMenu)
		{
		case MENU_KIND::GAME_START:
			SceneManager::GetInstance()->SetScene(STAGE);
			break;
		case MENU_KIND::EIXT:
			SceneManager::GetInstance()->SetScene(LOGO);
			break;
		}
	}

}

void Menu::Render()
{
	UI->Render();
}

void Menu::Release()
{
	::Safe_Delete(UI);
}


