#include "StageMenu.h"
#include "StageMenuInterface.h"

StageMenu::StageMenu() {}
StageMenu::~StageMenu() {}

void StageMenu::Initialize()
{
	UI = new StageMenuInterface;
	UI->Initialize();
}

void StageMenu::Update()
{
	if (UI)
		UI->Update();
}

void StageMenu::Render()
{
	if (UI)
		UI->Render();
}

void StageMenu::Release()
{

}