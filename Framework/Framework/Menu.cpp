#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "MenuInterface.h"

Menu::Menu(){}
Menu::~Menu(){}

void Menu::Initialize()
{
	UI = new MenuInterface;
	UI->Initialize();
}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_ENETER)
		SceneManager::GetInstance()->SetScene(STAGE);
}

void Menu::Render()
{
	UI->Render();
}

void Menu::Release()
{
}


