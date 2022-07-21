#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "Prototype.h"

#include "Player.h"
#include "BackGround.h"
#include "LogoInterface.h"

MainUpdate::MainUpdate() :Count(0),SceneState(0) {}
MainUpdate::~MainUpdate() { Release(); }

void MainUpdate::Initialize()
{
	Prototype::GetInstance()->Initialize();

	CursorManager::GetInstance()->CreateBuffer(ConsoleWidthSize,ConsoleHeightSize);
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->InputKey();
	SceneManager::GetInstance()->Update();
	/*
	if (dwKey & KEY_UP)// 키 입력을 받는 함수 VK(VirtualKey_  방향)
		cout << "KEY_UP" << endl;

	if (dwKey & KEY_DOWN)
		cout << "KEY_DOWN " << endl;

	if (dwKey & KEY_LEFT)
		cout << "KEY_LEFT " << endl;

	if (dwKey & KEY_RIGHT)
		cout << "KEY_RIGHT " << endl;

	if (dwKey & KEY_SPACE)
		cout << "KEY_SPACE " << endl;

	if (dwKey & KEY_ENETER )
	{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

		//cout << "KEY_ENETER " << endl;
		SceneState++;
		SceneManager::GetInstance()->SetScene(SceneState);

		if (SceneState > EXIT)
			SceneState = 0;

	}

	if (dwKey & KEY_CTRL)
		cout << "KEY_CTRL " << endl;

	if (dwKey & KEY_ALT)
		cout << "KEY_ALT " << endl;
	*/

	CursorManager::GetInstance()->FlippingBuffer();

}

void MainUpdate::Render()
{
	//Object* Test = new BakcGround;
	//Test->Initialize("Ground");
	//Test->Render();
	SceneManager::GetInstance()->Render();
	

}

void MainUpdate::Release()
{
}


