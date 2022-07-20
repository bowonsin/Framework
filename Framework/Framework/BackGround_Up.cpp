#include "BackGround_Up.h"

BackGround_Up::BackGround_Up() {}
BackGround_Up::BackGround_Up(Transform _Info){}
BackGround_Up::~BackGround_Up() { Release(); }

Object* BackGround_Up::Initialize(string _Key)
{
    return this;
}

int BackGround_Up::Update()
{
    return 0;
}

void BackGround_Up::Render()
{
}

void BackGround_Up::Release()
{
}