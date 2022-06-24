#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

Logo::Logo(){}
Logo::~Logo(){}

void Logo::Initialize()
{
	str = "Logo";
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_ENETER)
		SceneManager::GetInstance()->SetScene(MENU);
}

void Logo::Render()
{
	cout << "Logo" << endl;
}

void Logo::Release()
{
}


