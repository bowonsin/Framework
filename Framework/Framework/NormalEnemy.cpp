#include "NormalEnemy.h"

#include "CursorManager.h"
#include "ObjectManager.h"

#include "EnemyNormalBullet.h"

NormalEnemy::NormalEnemy():m_iUpDown(0),m_bUpDown(true) { Image_Initialize(); }
NormalEnemy::~NormalEnemy() { Release(); }

void NormalEnemy::Initialize()
{
    m_iColor = 15;
    m_iSpeed = 0.9f;
    m_eState = OBJECT_STATE::STATE_NORMAL;

    m_lTimer = GetTickCount64();

    m_eMoving = MONSTER_MOVING::MOVE_FORNT;
    m_iState_Time = 0;
    m_iUpDown = 1.0f;
    m_bUpDown = true;
    m_iShoting_Time = 0;
    InputImage(OBJECT_STATE::STATE_NORMAL);
}

int NormalEnemy::Update(Transform& Info)
{
    switch (m_eMoving)
    {
    case MONSTER_MOVING::MOVE_FORNT:
        if (m_lTimer + 50 < GetTickCount64())
        {
            if (m_bUpDown)
            {
                Info.Direction.x = -m_iSpeed;
                Info.Direction.y = m_iUpDown * m_iSpeed;
                if (Info.Position.y >= 35)
                    m_bUpDown = false;
            }
            else
            {
                Info.Direction.x = -m_iSpeed;
                Info.Direction.y = -m_iUpDown * m_iSpeed;
                if (Info.Position.y <= 5)
                    m_bUpDown = true;
            }
            Info.Position += Info.Direction;

            if (m_iShoting_Time == 40) // 한번만 쏘면 좋은데... 쩗
            {
                Bridge* Br = new EnemyNormalBullet;
                ObjectManager::GetInstance()->AddObject_Bullet("EnemyNormalBullet",Br,Info.Position);
                m_iShoting_Time = 0;
            }

            ++m_iShoting_Time;
        }
        break;
    case MONSTER_MOVING::MOVE_STOP:
        break;
    }
    return Bridge::Console_OutSide_Check();
}

void NormalEnemy::Render()
{
    for (int i = 0; i < m_vecImage.size(); ++i)
        CursorManager::GetInstance()->WriteBuffer(
            pObject->Getposition().x,
            pObject->Getposition().y + i,
            m_vecImage[i], m_iColor);
}

void NormalEnemy::Release()
{
}

void NormalEnemy::Survival_Check()
{

}

void NormalEnemy::InputImage(OBJECT_STATE State)
{
    for (int i = 0; i < m_vecImageList.size(); ++i)
    {
        if (m_vecImageList[i].State == State)
        {
            m_eState = State;
            m_vecImage = m_vecImageList[i].Dot_Image;
            break;
        }
    }
}

void NormalEnemy::Image_Initialize()
{
    Image_State Image_Data;
    Image_Data.Dot_Image.push_back((char*)"     :...:=      ");
    Image_Data.Dot_Image.push_back((char*)"+ =#==:.##*#:    ");
    Image_Data.Dot_Image.push_back((char*)" #+=@::==+*+*#   ");
    Image_Data.Dot_Image.push_back((char*)" #+:+:..=::+==  .");
    Image_Data.Dot_Image.push_back((char*)"%#+::==+...==:*= ");
    Image_Data.Dot_Image.push_back((char*)"    :.+*%%%      ");
    Image_Data.Dot_Image.push_back((char*)"        :..      ");
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


    Image_Data.Dot_Image.push_back((char*)" + = : =     + #   = = : = ");
    Image_Data.Dot_Image.push_back((char*)" : * * .    = : # : * * + .");
    Image_Data.Dot_Image.push_back((char*)"     : :  + :  : =   =+");
    Image_Data.Dot_Image.push_back((char*)"  * = = = + ++ :=     .");
    Image_Data.Dot_Image.push_back((char*)" = = + = # * +   .  .:   .");
    Image_Data.Dot_Image.push_back((char*)" : . = + # : . += + . .=  :");
    Image_Data.Dot_Image.push_back((char*)" =.  + + # * + = + + + :");
    Image_Data.Dot_Image.push_back((char*)"  =    =  +  +      =");
    Image_Data.Dot_Image.push_back((char*)"              = = : ");
    Image_Data.State = OBJECT_STATE::STATE_DIE2;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();
}

void NormalEnemy::Shoot_Bullet()
{
}
