#pragma once
#include "Headers.h"

class Scene; // 헤더 파일이 없는데 Scene어떻게 쓰나?
/*
	클레스를 정의 없이 만드는데 속임수와 같아서 
	정의만 해놓고 private에 만들어 두는데 ( 허수로 없는형태 인데 ) 
	header 파일에서 사용하지 않고 있는 척만 할려고 
*/
class SceneManager
{
private:
	static SceneManager* Instance;

public:

	void SetScene(SCENEID _SceneState); // set나 get 은 인라인으로 만드는데 현지 이 함수는 그럴 필요 없다.

	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;

		return Instance;
	}
private:
	Scene* Scene_Id;
public:
	void Update();
	void Render();
	void Release();

private:
	SceneManager();
public:
	~SceneManager();
};

