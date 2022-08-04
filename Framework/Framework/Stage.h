#pragma once
#include "Scene.h"
class Object;
class Stage : public Scene
{
	//�� Stage���� Enemy�� ����� ���� �ƴϸ�  -> �̰��� ���� �� Stage ���� ��ü�� �� �� �ִ� �� ������.
	//Menu���� Enemy�� ���� ��ü������ ���� �� ������ ������ ���ƾ� �Ұ� ����.
public:
	virtual void Initialize()PURE; //PURE  ���� �����Լ��� ��� �ϰ� �ۿ� �ȴ�.
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

protected:

	Object* pPlayer;

	void Stage_Collision_Check();

	void Player_Enemy_Collision_Check(Object* Player,list<Object*>* NormalEnemy);
	void Player_EnemyBullet_Collision_Check(Object* Player,list<Object*>* EnemyBullet);

	void PlayerBullet_Enemy_Collision_Check(list<Object*>* Player_Bullet, list<Object*>* EnemyList);

	void Obejct_Disable();

public:
	Stage();
	virtual ~Stage();
};