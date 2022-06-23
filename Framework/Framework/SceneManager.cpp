#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;

void SceneManager::SetScene(int _SceneState)
{

	switch (_SceneState)
	{
	case SCENEID::LOGO:
		cout << "LOGO" << endl;
		break;
	case SCENEID::MENU:
		cout << "MENU" << endl;
		break;
	case SCENEID::STAGE:
		cout << "STAGE" << endl;
		break;
	case SCENEID::EXIT:
		cout << "EXIT" << endl;
		break;
	}
}
