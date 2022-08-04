#pragma once
#include "Scene.h"
class Object;
class Stage : public Scene
{
	//각 Stage에서 Enemy를 만들것 인지 아니면  -> 이것이 좀더 각 Stage 별로 색체를 줄 수 있는 거 같은데.
	//Menu에서 Enemy를 만들어서 전체적으로 관리 할 것인지 생각해 보아야 할거 같다.
public:
	virtual void Initialize()PURE; //PURE  순수 가상함수와 비슷 하게 작용 된다.
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