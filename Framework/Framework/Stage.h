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
	ULONGLONG m_LTimer;
	int m_iTime_Setting;

	void Stage_Collision_Check();

	void Player_Enemy_Collision_Check(list<Object*>* NormalEnemy);
	void Player_EnemyBullet_Collision_Check(list<Object*>* EnemyBullet);
	void PlayerBullet_Enemy_Collision_Check(list<Object*>* Player_Bullet, list<Object*>* EnemyList);
	void Enemy_Check(list<Object*>* EnemyList);

	void Monster_Setting();
	void Obejct_Disable();

	virtual void Time_to_RegenMonster()PURE;
	virtual void Regen_Enemy(string EnemyName, Vector3 _Position)PURE;

public:
	Stage();
	virtual ~Stage();
};