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

	if (dwKey & KEY_RIGHT && m_iSelectMenu != 1)
		++m_iSelectMenu;
	else if (dwKey & KEY_LEFT && m_iSelectMenu != 0)
		--m_iSelectMenu;
	if (UI)
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
	if (UI)
		UI->Render();
}

void Menu::Release()
{
	::Safe_Delete(UI);
}


