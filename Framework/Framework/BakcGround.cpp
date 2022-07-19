#include "BakcGround.h"

#include "CursorManager.h"

BakcGround::BakcGround() {}
BakcGround::BakcGround(Transform _info) {}
BakcGround::~BakcGround() {}

Object* BakcGround::Initialize(string _Key)
{

    TransInfo.Position = Vector3(0.0f, 0.0f);
    TransInfo.Rotation = Vector3(0.0f, 0.0f);
    TransInfo.Scale = Vector3(2.0f, 2.0f);

    GroundOne.push_back((char*)"!!!!!~,,,-~;!!***;:~,,,~;!;~~:!*;;!*;~,.");
    GroundOne.push_back((char*)":-:!;~-~:;!!!:~-~;!;:~-~;;--~;*;~~!!~,--");
    GroundOne.push_back((char*)"!;;!!~~:!!*!-,..-:!!!;;!*!~~:!!!;;!!:~~~");
    GroundOne.push_back((char*)"-~~-,~;--,,.,-::~~~-.,--:-,--,.,,----,,-");
    GroundOne.push_back((char*)".::-        ,~.-~~-,.             -~,   ");
    GroundOne.push_back((char*)" -             .,.,               ,,    ");
    GroundOne.push_back((char*)"                                        ");
    GroundOne.push_back((char*)"--~~~~~~~~~~------''''-------~~~~~~~~---");
    GroundOne_Info.Position = Vector3(0.0f, 0.0f, 0.0f);

    GroundTwo.push_back((char*)"--~~~~~~~~~~------,,,,-------~~~~~~~~---");
    GroundTwo.push_back((char*)"                                        ");
    GroundTwo.push_back((char*)" -             .,.,               ,,    ");
    GroundTwo.push_back((char*)".::-        ,~.-~~-,.             -~,   ");
    GroundTwo.push_back((char*)"-~~-,~;--,,.,-::~~~-.,--:-,--,.,,----,,-");
    GroundTwo.push_back((char*)"!;;!!~~:!!*!-,..-:!!!;;!*!~~:!!!;;!!:~~~");
    GroundTwo.push_back((char*)":-:!;~-~:;!!!:~-~;!;:~-~;;--~;*;~~!!~,--");
    GroundTwo.push_back((char*)"!!!!!~,,,-~;!!***;:~,,,~;!;~~:!*;;!*;~,.");
    GroundTwo_Info.Position = Vector3(0.0f, (float)(ConsoleHeightSize - GroundTwo.size()), 0.0f);

    return nullptr;
}

int BakcGround::Update()
{
    return 0;
}

void BakcGround::Render()
{
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < GroundOne.size(); ++i)
        {
            CursorManager::GetInstance()->WriteBuffer(
                GroundOne_Info.Position.x,
                GroundOne_Info.Position.y + i,
                GroundOne[i], 15);
        }
        GroundOne_Info.Position.x += 40;

    
        for (int i = 0; i < GroundTwo.size(); ++i)
        {
            CursorManager::GetInstance()->WriteBuffer(
                GroundTwo_Info.Position.x,
                GroundTwo_Info.Position.y + i,
                GroundTwo[i], 15);

        }
        GroundTwo_Info.Position.x += 40;
    }
}

void BakcGround::Release()
{
}


