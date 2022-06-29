#pragma once
#include "Headers.h"
#include "Object.h"

class CollisionManager
{
public:
	static bool Collision(Object* _ObjA, Object* _ObjB)
	{
		// ** Posisiton ¹Þ¾Æ¿È
		Vector3 Position_A = _ObjA->Getposition();
		Vector3 Position_B = _ObjB->Getposition();

		// ** Sacle ¹Þ¾Æ¿È
		Vector3 Scale_A = _ObjA->GetScale();
		Vector3 Scale_B = _ObjB->GetScale();

		if ( Position_A.x + Scale_A.x> Position_B.x &&Position_B.x + Scale_B.x > Position_A.x &&
			Position_A.y == Position_B.y)
			return true;

		return false;
	}
};