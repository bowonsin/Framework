#pragma once
#include "Headers.h"
#include "Object.h"

class CollisionManager
{
public:
	
	static bool Collision(Object* _ObjA, Object* _ObjB)
	{
		// ** Positoin �޾ƿ�.
		Vector3 Position_A = _ObjA->Getposition();
		Vector3 Position_B = _ObjB->Getposition();

		// ** Scale �޾ƿ�.
		Vector3 Scale_A = _ObjA->GetScale();
		Vector3 Scale_B = _ObjB->GetScale();

		// ** �浹�� �Ǿ��ٸ�...
		/*
		// ** ž�� (������)
		if (Position_A.x + Scale_A.x > Position_B.x &&
			Position_B.x + Scale_B.x > Position_A.x &&
			Position_A.y == Position_B.y)
			return true;
		*/

		// ** Ⱦ��ũ�� ���ӿ����� ���� �ִ� ������ ��� (����)
		if ((Position_A.x + (Scale_A.x * 0.5f)) > (Position_B.x - (Scale_B.x * 0.5f)) &&
			(Position_B.x + (Scale_B.x * 0.5f)) > (Position_A.x - (Scale_A.x * 0.5f)) &&
			(Position_A.y + (Scale_A.y * 0.5f)) == (Position_B.y + (Scale_B.y * 0.5f)))
			return true;

		/*
		* // ** ���̵�� ���� (������)
		if ((Position_A.x + (Scale_A.x * 0.5f)) > (Position_B.x - (Scale_B.x * 0.5f)) &&
			(Position_B.x + (Scale_B.x * 0.5f)) > (Position_A.x - (Scale_A.x * 0.5f)) &&
			(Position_A.y + (Scale_A.y * 0.5f)) > (Position_B.y - (Scale_B.y * 0.5f)) &&
			(Position_B.y + (Scale_B.y * 0.5f)) > (Position_A.y - (Scale_A.y * 0.5f)))
			return true;
		*/


		// ** �ƴ϶��..
		return false;
	}
};