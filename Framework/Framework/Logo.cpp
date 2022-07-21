#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "LogoInterface.h"
#include "ScoreInterface.h"


Logo::Logo(){}
Logo::~Logo() { Release(); }

void Logo::Initialize()
{
	pUI = new ScoreInterface;
	UI= new LogoInterface;
	pUI->Initialize();
	UI->Initialize();
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_ENETER)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);

	if (dwKey & KEY_ESCAPE)
		SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
}

void Logo::Render()
{
	pUI->Render();
	UI->Render();
}

void Logo::Release()
{
	::Safe_Delete(UI);
}


