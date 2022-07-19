#pragma once
#include "Scene.h"
class Object;
class Stage : public Scene
{
private:
	Object* pPlayer;
	list<Object*>* EnemyList;
	list<Object*>* BulletList;

	//�� Stage���� Enemy�� ����� ���� �ƴϸ�  -> �̰��� ���� �� Stage ���� ��ü�� �� �� �ִ� �� ������.
	//Menu���� Enemy�� ���� ��ü������ ���� �� ������ ������ ���ƾ� �Ұ� ����.
public:
	virtual void Initialize()PURE; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

protected:
	void Stage_Collision_Check();

public:
	Stage();
	virtual ~Stage();
};