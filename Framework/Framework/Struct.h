#pragma once

struct Vector3
{
	float x, y, z;
	Vector3() :x(0), y(0), z(0) {};

	Vector3(float _x, float _y) :x(_x), y(_y), z(0) {};

	Vector3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};

	Vector3 operator+(Vector3 _V1)
	{
		return Vector3(this->x + _V1.x, this->x +_V1.y, this->z+ _V1.y);
	}
};

struct Trasnform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;

};