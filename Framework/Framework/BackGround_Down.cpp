#include "BackGround_Down.h"

BackGround_Down::BackGround_Down() {}
BackGround_Down::~BackGround_Down() { Release();  }

Object* BackGround_Down::Initialize(string _Key)
{
    strKey = _Key;


    return this;
}

int BackGround_Down::Update()
{
    return 0;
}

void BackGround_Down::Render()
{
}

void BackGround_Down::Release()
{
}


