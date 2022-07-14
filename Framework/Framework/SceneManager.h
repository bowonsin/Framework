#pragma once
#include "Headers.h"

class Scene; // ��� ������ ���µ� Scene��� ����?
/*
	Ŭ������ ���� ���� ����µ� ���Ӽ��� ���Ƽ� 
	���Ǹ� �س��� private�� ����� �δµ� ( ����� �������� �ε� ) 
	header ���Ͽ��� ������� �ʰ� �ִ� ô�� �ҷ��� 
*/
class SceneManager
{
private:
	static SceneManager* Instance;

public:

	void SetScene(SCENEID _SceneState); // set�� get �� �ζ������� ����µ� ���� �� �Լ��� �׷� �ʿ� ����.

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

