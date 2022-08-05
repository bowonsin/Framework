#include "NormalEnemy.h"

NormalEnemy::NormalEnemy():m_iUpDown(0) { Image_Initialize(); }
NormalEnemy::~NormalEnemy() { Release(); }

void NormalEnemy::Initialize()
{
    m_iColor = 15;
    m_iSpeed = 1.5f;
    m_eState = OBJECT_STATE::STATE_NORMAL;

    m_lTimer = GetTickCount64();

    m_eMoving = MONSTER_MOVING::MOVE_FORNT;
    m_iState_Time = 0;
    InputImage(OBJECT_STATE::STATE_NORMAL);
}

int NormalEnemy::Update(Transform& Info)
{
    switch (m_eMoving)
    {
    case MONSTER_MOVING::MOVE_FORNT:
        if (m_lTimer + 100 < GetTickCount64())
        {

        }
        break;
    }
    return 0;
}

void NormalEnemy::Render()
{
}

void NormalEnemy::Release()
{
}

void NormalEnemy::InputImage(OBJECT_STATE State)
{
}

void NormalEnemy::Image_Initialize()
{
    Image_State Image_Data;
    Image_Data.Dot_Image.push_back((char*)"       :::...:=        ");
    Image_Data.Dot_Image.push_back((char*)"    ++=++=:.#+:+=      ");
    Image_Data.Dot_Image.push_back((char*)"+ =#===::=:.##*###:    ");
    Image_Data.Dot_Image.push_back((char*)" #+=:*@=:::==+***+*#   ");
    Image_Data.Dot_Image.push_back((char*)" #+::=+..:..=:::=+==  .");
    Image_Data.Dot_Image.push_back((char*)"%#+::::::==+...:===:*= ");
    Image_Data.Dot_Image.push_back((char*)"    =+*++===***%%#++   ");
    Image_Data.Dot_Image.push_back((char*)"      ::..+*%%%=:      ");
    Image_Data.Dot_Image.push_back((char*)"            :..**      ");
    Image_Data.State = OBJECT_STATE::STATE_NORMAL;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();

    Image_Data.Dot_Image.push_back((char*)"          +#: .:+==");
    Image_Data.Dot_Image.push_back((char*)"     :*===*##+++=:  .=.");
    Image_Data.Dot_Image.push_back((char*)"    #*+==.  ##++====+*:");
    Image_Data.Dot_Image.push_back((char*)".==:+++**:..=   *****:..++");
    Image_Data.Dot_Image.push_back((char*)".=:: :+*****.   ==+*****..");
    Image_Data.Dot_Image.push_back((char*)"  **++=...=++++++*#. += #*");
    Image_Data.Dot_Image.push_back((char*)"  =+++=++++*****+===::.");
    Image_Data.Dot_Image.push_back((char*)"      .:=*+==+++=====*:");
    Image_Data.Dot_Image.push_back((char*)"     :*   =*+ +*+++**");
    Image_Data.State = OBJECT_STATE::STATE_DIE1;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();


    Image_Data.Dot_Image.push_back((char*)"+=:=     +# ==:=");
    Image_Data.Dot_Image.push_back((char*)":**.  =: # :**+.");
    Image_Data.Dot_Image.push_back((char*)"    :: +: :=  =+");
    Image_Data.Dot_Image.push_back((char*)"   *===+++ :=     .");
    Image_Data.Dot_Image.push_back((char*)"==+=#*+   .  .:   .");
    Image_Data.Dot_Image.push_back((char*)":.=+#:.+=+..= :");
    Image_Data.Dot_Image.push_back((char*)" =.  ++#*+=+++:");
    Image_Data.Dot_Image.push_back((char*)"  =    = ++    =");
    Image_Data.Dot_Image.push_back((char*)"            ==:");
    Image_Data.State = OBJECT_STATE::STATE_DIE2;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();
}