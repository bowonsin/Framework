#include "NamedEnemy.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "EnemyNormalBullet.h"

NamedEnemy::NamedEnemy() { Image_Initialize(); }
NamedEnemy::~NamedEnemy() { Release(); }

void NamedEnemy::Initialize()
{
    m_iColor = 15;
    m_iSpeed = 0.5f;
    m_eState = OBJECT_STATE::STATE_NORMAL;

    m_lTimer = GetTickCount64();

    m_eMoving = MONSTER_MOVING::MOVE_FORNT;

    m_iState_Time = 0;
    InputImage(OBJECT_STATE::STATE_NORMAL);


}

int NamedEnemy::Update(Transform& Info)
{
    if (m_eState != OBJECT_STATE::STATE_DIE1 && m_eState != OBJECT_STATE::STATE_DIE2)
    {
        switch (m_eMoving)
        {
        case MONSTER_MOVING::MOVE_FORNT:
            if (m_lTimer + 50 < GetTickCount64()) // 1000 을 1초 기준으로 이동 
            {
                m_lTimer = GetTickCount64();
                Info.Direction.x = -1;
                Info.Position += Info.Direction * m_iSpeed;
                if (Info.Position.x == NamedMonster_Maximum_Width)
                    m_eMoving = MONSTER_MOVING::MOVE_STOP;

                if (m_eState == OBJECT_STATE::STATE_MOVE)
                    InputImage(OBJECT_STATE::STATE_NORMAL);
                else if (m_eState == OBJECT_STATE::STATE_NORMAL)
                    InputImage(OBJECT_STATE::STATE_MOVE);
            }
            break;
        case MONSTER_MOVING::MOVE_STOP: // 일정 시간마다 공격 하도록 
            if (m_lTimer + 650 < GetTickCount64())
            {
                Hit_Check();
                m_lTimer = GetTickCount64();
                if (m_iState_Time == 60)
                {
                    m_iState_Time = 0;
                    m_eMoving = MONSTER_MOVING::MOVE_BACK;
                }
                Bridge* N_Bullet = new EnemyNormalBullet;
                Vector3 BulletPosition = pObject->Getposition();
                BulletPosition.y += m_vecImage.size() / 2;
                ObjectManager::GetInstance()->AddObject_Bullet("EnemyNormalBullet", N_Bullet, BulletPosition);
                BulletPosition.y -= m_vecImage.size() / 2;
                N_Bullet = new EnemyNormalBullet;
                ObjectManager::GetInstance()->AddObject_Bullet("EnemyNormalBullet", N_Bullet, BulletPosition);
                BulletPosition.y += m_vecImage.size();
                N_Bullet = new EnemyNormalBullet;
                ObjectManager::GetInstance()->AddObject_Bullet("EnemyNormalBullet", N_Bullet, BulletPosition);

                ++m_iState_Time;
            }
            break;
        case MONSTER_MOVING::MOVE_BACK: // 뒤로 가기 만약 뒤로 끝까지 가면 사망
            if (m_lTimer + 250 < GetTickCount64()) // 1000 을 1초 기준으로 이동 
            {
                Hit_Check();
                // 제거
                if (Info.Position.x == InGameConsole_WidthSize)
                    return BUFFER_OVER;

                m_lTimer = GetTickCount64();
                Info.Direction.x = +1;
                Info.Position += Info.Direction * m_iSpeed;

            }
            break;
        }
    }
    else
    {
        if (m_eState == OBJECT_STATE::STATE_DIE1)
        {
            if (m_lTimer + 500 < GetTickCount64())
            {
                m_lTimer = GetTickCount64();
                if (m_iState_Time >= 2)
                {
                    m_eState = OBJECT_STATE::STATE_DIE2;
                    m_iState_Time = 0;
                    InputImage(OBJECT_STATE::STATE_DIE2);
                }
                ++m_iState_Time;
            }
        }
        else if (m_eState == OBJECT_STATE::STATE_DIE2)
        {
            if (m_lTimer + 500 < GetTickCount64())
            {
                m_lTimer = GetTickCount64();
                if (m_iState_Time >= 2)
                    return BUFFER_OVER;
                Info.Position.x += 0.5f;
                ++m_iState_Time;
            }
        }
    }

    return 0;
}

void NamedEnemy::Render()
{
    for (int i = 0; i < m_vecImage.size(); ++i)
        CursorManager::GetInstance()->WriteBuffer(
            pObject->Getposition().x,
            pObject->Getposition().y + i,
            m_vecImage[i], m_iColor);
}

void NamedEnemy::Release()
{
}

void NamedEnemy::Hit_Check()
{
    switch (m_eState)
    {
    case OBJECT_STATE::STATE_HIT:
        if (m_iState_Time >= 2)
        {
            m_eState = OBJECT_STATE::STATE_HIT2;
            m_iState_Time = 0;
            InputImage(OBJECT_STATE::STATE_HIT2);
        }
        ++m_iState_Time;
        break;
    case OBJECT_STATE::STATE_HIT2:
        if (m_iState_Time >= 2)
        {
            m_eState = OBJECT_STATE::STATE_NORMAL;
            m_iState_Time = 0;
            InputImage(OBJECT_STATE::STATE_NORMAL);
        }
        ++m_iState_Time;
        break;
    }
}


void NamedEnemy::Survival_Check(int Hp)
{
    if (Hp == 0)
    {
        m_eState = OBJECT_STATE::STATE_DIE1;
        InputImage(OBJECT_STATE::STATE_DIE1);
        m_iState_Time = 0;
    }
    else if (Hp == 5)
    {
        m_eState = OBJECT_STATE::STATE_HIT;
        InputImage(OBJECT_STATE::STATE_HIT);
        m_iState_Time = 0;
    }
}

void NamedEnemy::InputImage(OBJECT_STATE State)
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

void NamedEnemy::Image_Initialize()
{
    Image_State Image_Data;
    Image_Data.Dot_Image.push_back((char*)"              .  ");
    Image_Data.Dot_Image.push_back((char*)"          ,;,... ");
    Image_Data.Dot_Image.push_back((char*)"          -!*!:* ");
    Image_Data.Dot_Image.push_back((char*)" ,,    , -,=*;!* ");
    Image_Data.Dot_Image.push_back((char*)" - .-,.. ..=****,");
    Image_Data.Dot_Image.push_back((char*)" .,-, .,   ;****~");
    Image_Data.Dot_Image.push_back((char*)" ,-:,  -   ~!=**=");
    Image_Data.Dot_Image.push_back((char*)",  -:.,-   ~-.:*-");
    Image_Data.Dot_Image.push_back((char*)"-,:,.::~,,~,~    ");
    Image_Data.Dot_Image.push_back((char*)" ,:~ ...,::~:    ");
    Image_Data.Dot_Image.push_back((char*)"  -.-;..***~.    ");
    Image_Data.Dot_Image.push_back((char*)"   -:,,,***;- .. ");
    Image_Data.Dot_Image.push_back((char*)"   -~.,-***=~~*- ");
    Image_Data.Dot_Image.push_back((char*)"   ,..,,==*==*=. ");
    Image_Data.Dot_Image.push_back((char*)"   ~.::~;::***!  ");
    Image_Data.Dot_Image.push_back((char*)"   -::,~-;~**=.  ");
    Image_Data.Dot_Image.push_back((char*)"     ,--~::!.,   ");
    Image_Data.Dot_Image.push_back((char*)"         .~      ");
    Image_Data.State = OBJECT_STATE::STATE_HIT;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();

    Image_Data.Dot_Image.push_back((char*)"   ..      -:.   ");
    Image_Data.Dot_Image.push_back((char*)"   ,.-     **=~  ");
    Image_Data.Dot_Image.push_back((char*)"   -.,. ,,-:*!!- ");
    Image_Data.Dot_Image.push_back((char*)"    ,~.~. .,***~ ");
    Image_Data.Dot_Image.push_back((char*)"   -~;  -   ~**=-");
    Image_Data.Dot_Image.push_back((char*)"   .-,,.~   :;==,");
    Image_Data.Dot_Image.push_back((char*)" ,,. *-:. .-. .  ");
    Image_Data.Dot_Image.push_back((char*)" ,-, , : :*=*    ");
    Image_Data.Dot_Image.push_back((char*)"    ,-,~.**!,    ");
    Image_Data.Dot_Image.push_back((char*)"    ,~~,.**-:..  ");
    Image_Data.Dot_Image.push_back((char*)"     ~- ,**=:*   ");
    Image_Data.Dot_Image.push_back((char*)"     .-:~;.-=*   ");
    Image_Data.Dot_Image.push_back((char*)"      :-~;~~=;   ");
    Image_Data.Dot_Image.push_back((char*)"      .---.~.    ");
    Image_Data.Dot_Image.push_back((char*)"          ..     ");
    Image_Data.State = OBJECT_STATE::STATE_HIT2;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();


    Image_Data.Dot_Image.push_back((char*)"         ---  -.         ");
    Image_Data.Dot_Image.push_back((char*)"       .;==*~;**- ..,    ");
    Image_Data.Dot_Image.push_back((char*)"   .. -*:=***==!!=**!-   ");
    Image_Data.Dot_Image.push_back((char*)"  .:;;==!:--~;*=*****-   ");
    Image_Data.Dot_Image.push_back((char*)"  ,:==~.     ..,=***!.   ");
    Image_Data.Dot_Image.push_back((char*)"   :*~,,.       ,**=-    ");
    Image_Data.Dot_Image.push_back((char*)"    :.  ,        ~=:.    ");
    Image_Data.Dot_Image.push_back((char*)"    -.  ..       ,:.     ");
    Image_Data.Dot_Image.push_back((char*)"   ,:,.,~.       .-      ");
    Image_Data.Dot_Image.push_back((char*)"  ,.,~-~,        .-      ");
    Image_Data.Dot_Image.push_back((char*)" ~.  .:.         .~.     ");
    Image_Data.Dot_Image.push_back((char*)" ~ .~..,       .~,.--    ");
    Image_Data.Dot_Image.push_back((char*)" ,-:. -.    .,-,..,-,    ");
    Image_Data.Dot_Image.push_back((char*)"  ,:-~-.   .,, .,~!,     ");
    Image_Data.Dot_Image.push_back((char*)"    .;:-. .*!.-:!**-     ");
    Image_Data.Dot_Image.push_back((char*)"    -,,~:.;=*=!****;     ");
    Image_Data.Dot_Image.push_back((char*)" .,~..--.,:,.,:*****,    ");
    Image_Data.Dot_Image.push_back((char*)".-,,..~. .;:, -*;***~    ");
    Image_Data.Dot_Image.push_back((char*)".,,...-:-~-.~,-!****;    ");
    Image_Data.Dot_Image.push_back((char*)" -----~:~,.,~~!****!;    ");
    Image_Data.Dot_Image.push_back((char*)"  :::-,:,:-=*********    ");
    Image_Data.Dot_Image.push_back((char*)"  ~-, .~:,--=*******,    ");
    Image_Data.Dot_Image.push_back((char*)"   :,.,-;~-:,*******     ");
    Image_Data.Dot_Image.push_back((char*)"   .-~-::-..--~:!=*~     ");
    Image_Data.Dot_Image.push_back((char*)"     .:;..-~~::--.~      ");
    Image_Data.Dot_Image.push_back((char*)"        -,.              ");
    Image_Data.State = OBJECT_STATE::STATE_NORMAL;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();


    Image_Data.Dot_Image.push_back((char*)"             .~~~~::.  ");
    Image_Data.Dot_Image.push_back((char*)"        .::!**!!* ,.~  ");
    Image_Data.Dot_Image.push_back((char*)"        ,=,!***=-,=*-  ");
    Image_Data.Dot_Image.push_back((char*)"     ~!-**!-,,:=****:  ");
    Image_Data.Dot_Image.push_back((char*)"     :**;,.     -=*=~  ");
    Image_Data.Dot_Image.push_back((char*)"     ,*:...,     ,=*   ");
    Image_Data.Dot_Image.push_back((char*)"      -,.  ,      ;.   ");
    Image_Data.Dot_Image.push_back((char*)"      --- .,      ,    ");
    Image_Data.Dot_Image.push_back((char*)"      :~,..-      .    ");
    Image_Data.Dot_Image.push_back((char*)"     ,.,~-~       .    ");
    Image_Data.Dot_Image.push_back((char*)"    -   .~.       ,~   ");
    Image_Data.Dot_Image.push_back((char*)"    - ,;~,,     ,,..-  ");
    Image_Data.Dot_Image.push_back((char*)"     --  ,   ..-..,:   ");
    Image_Data.Dot_Image.push_back((char*)"       -;~.  *==,!*!   ");
    Image_Data.Dot_Image.push_back((char*)"      .~,,:.,***=***   ");
    Image_Data.Dot_Image.push_back((char*)"      -.--,-!;;-,-**   ");
    Image_Data.Dot_Image.push_back((char*)"    ,,, -..;!*~ .,~*-  ");
    Image_Data.Dot_Image.push_back((char*)"    ,.. -..;-*:~~,**!  ");
    Image_Data.Dot_Image.push_back((char*)"    ,.. -:-:.=**- =**  ");
    Image_Data.Dot_Image.push_back((char*)"    .~.,~~;,~=**!.~,:- ");
    Image_Data.Dot_Image.push_back((char*)"     :~-:::!,,*;*::!=  ");
    Image_Data.Dot_Image.push_back((char*)"     :;,~,,-::!*!-:*~  ");
    Image_Data.Dot_Image.push_back((char*)"     -~~-.,-~:-!- .,   ");
    Image_Data.Dot_Image.push_back((char*)"     ---,..-:::;,.,.   ");
    Image_Data.Dot_Image.push_back((char*)"        .---.,,,..     ");
    Image_Data.State = OBJECT_STATE::STATE_MOVE;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();



    Image_Data.Dot_Image.push_back((char*)"       :#*+==+++*");
    Image_Data.Dot_Image.push_back((char*)"  :*##****=:.  ..=++**#+=.");
    Image_Data.Dot_Image.push_back((char*)" #*+:.    ....  .     :+=*:");
    Image_Data.Dot_Image.push_back((char*)"*#=.        ..         .+.#");
    Image_Data.Dot_Image.push_back((char*)"***+=:.. .+=+:.         :.*+");
    Image_Data.Dot_Image.push_back((char*)"+:=:.:.. :. :            :+=#");
    Image_Data.Dot_Image.push_back((char*)".+.             .  .     .+.#");
    Image_Data.Dot_Image.push_back((char*)"++:    .: .     =::+..:.=+=+.");
    Image_Data.Dot_Image.push_back((char*)":* =   .+:+:.  :==:  ..:=**#.");
    Image_Data.Dot_Image.push_back((char*)" #.+.    .::.           .+#+");
    Image_Data.Dot_Image.push_back((char*)" .#=+:.    .  ........:=+#+");
    Image_Data.Dot_Image.push_back((char*)"   :+***++=.:   :=**##**+.");
    Image_Data.Dot_Image.push_back((char*)"           ++**++*#*");
    Image_Data.State = OBJECT_STATE::STATE_DIE1;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();


    Image_Data.Dot_Image.push_back((char*)"       *#*+**#:+#*+**#:");
    Image_Data.Dot_Image.push_back((char*)"  ::.:##+=.   .   .:+*#=...");
    Image_Data.Dot_Image.push_back((char*)" *+#*+==:           .:+++#+ :");
    Image_Data.Dot_Image.push_back((char*)" =#+=                   :+*#");
    Image_Data.Dot_Image.push_back((char*)".*+=:   ::      .===     ==#..");
    Image_Data.Dot_Image.push_back((char*)"# #:  .=::         .     .+*::");
    Image_Data.Dot_Image.push_back((char*)"  :+.                    =* :");
    Image_Data.Dot_Image.push_back((char*)"#.#.                ...  .=*:=");
    Image_Data.Dot_Image.push_back((char*)" *+=:     :        =+=.  ==#.");
    Image_Data.Dot_Image.push_back((char*)" =#+=.    :=+.          :+**");
    Image_Data.Dot_Image.push_back((char*)" ++**++==           ::++*#++:");
    Image_Data.Dot_Image.push_back((char*)"  .: .*#+=..  .. ..:+*#: .:");
    Image_Data.Dot_Image.push_back((char*)"       +#****#:+#***#*.");
    Image_Data.Dot_Image.push_back((char*)"        .:==.   .:=:.");
    Image_Data.State = OBJECT_STATE::STATE_DIE2;
    m_vecImageList.push_back(Image_Data);
}