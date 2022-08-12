#include "BossEnemy.h"

#include "CursorManager.h"
#include "EnemyNormalBullet.h"
#include "HomingBullet.h"
#include "ObjectManager.h"

BossEnemy::BossEnemy() {}
BossEnemy::~BossEnemy() {}

void BossEnemy::Initialize()
{
    m_iColor = 15;
    m_iSpeed = 0.5f;
    m_eState = OBJECT_STATE::STATE_NORMAL;

    Image_Initialize();

    m_lTimer = GetTickCount64();
    m_eMoving = MONSTER_MOVING::MOVE_FORNT;
    //Disable
    InputImage(OBJECT_STATE::STATE_NORMAL);
}

int BossEnemy::Update(Transform& Info)
{
    if (m_eState != OBJECT_STATE::STATE_DIE1 && m_eState != OBJECT_STATE::STATE_DIE2)
    {
        switch (m_eMoving)
        {
        case MONSTER_MOVING::MOVE_FORNT:
            if (m_lTimer + 50 < GetTickCount64()) // 1000 을 1초 기준으로 이동 
            {
                m_lTimer = GetTickCount64();
                Info.Position.x -= 1 * m_iSpeed;
                if (Info.Position.x == 145)
                    m_eMoving = MONSTER_MOVING::MOVE_STOP;
            }
            break;
        case MONSTER_MOVING::MOVE_STOP: // 일정 시간마다 공격 하도록 
            if (m_lTimer + 650 < GetTickCount64())
            {
                Hit_Check();
                m_lTimer = GetTickCount64();
                Bridge* N_Bullet = new EnemyNormalBullet;
                Vector3 BulletPosition = Info.Position;
                BulletPosition.y += m_vecImage.size() / 2;
                ObjectManager::GetInstance()->AddObject_Bullet("EnemyNormalBullet", N_Bullet, BulletPosition);
                N_Bullet = new EnemyNormalBullet;
                BulletPosition.y -= m_vecImage.size() / 2;
                ObjectManager::GetInstance()->AddObject_Bullet("EnemyNormalBullet", N_Bullet, BulletPosition);
                BulletPosition.y += m_vecImage.size();
                N_Bullet = new EnemyNormalBullet;
                ObjectManager::GetInstance()->AddObject_Bullet("EnemyNormalBullet", N_Bullet, BulletPosition);

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
void BossEnemy::Hit_Check()
{
    switch (m_eState)
    {
    case OBJECT_STATE::STATE_HIT:
        if (m_iState_Time >= 2)
        {
            m_eState = OBJECT_STATE::STATE_NORMAL;
            m_iState_Time = 0;
            InputImage(OBJECT_STATE::STATE_NORMAL);
        }
        ++m_iState_Time;
        break;
        break;
    }
}

void BossEnemy::Render()
{
    for (int i = 0; i < m_vecImage.size(); ++i)
        CursorManager::GetInstance()->WriteBuffer(
            pObject->Getposition().x,
            pObject->Getposition().y + i,
            m_vecImage[i], m_iColor);

}

void BossEnemy::Release()
{
}

void BossEnemy::Survival_Check(int Hp)
{
     if (Hp == 0)
    {
        m_eState = OBJECT_STATE::STATE_DIE1;
        InputImage(OBJECT_STATE::STATE_DIE1);
        m_iState_Time = 0;
    }
    else if (Hp == 15)
    {
        m_eState = OBJECT_STATE::STATE_HIT;
        InputImage(OBJECT_STATE::STATE_HIT);
        m_iState_Time = 0;
    }
}

void BossEnemy::InputImage(OBJECT_STATE State)
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

void BossEnemy::Image_Initialize()
{
    Image_State Image_Data;
    Image_Data.Dot_Image.push_back((char*)"                                   +***.                      ");
    Image_Data.Dot_Image.push_back((char*)"                                =+=+**:                       ");
    Image_Data.Dot_Image.push_back((char*)"                               +==**:                         ");
    Image_Data.Dot_Image.push_back((char*)"                              .==++=::                        ");
    Image_Data.Dot_Image.push_back((char*)"                  ..   .++   =.=++:.:+*.    ==+               ");
    Image_Data.Dot_Image.push_back((char*)"                 #*=   =*#: +==:::=+=.=+*.  ***:              ");
    Image_Data.Dot_Image.push_back((char*)"               ..==::::::..=+.:::.:+**:...=:....:=*::..       ");
    Image_Data.Dot_Image.push_back((char*)"         =****#+.::.:=:.:..:#*+++**+===.:.::*#++==*+.++.      ");
    Image_Data.Dot_Image.push_back((char*)"       =*+****#*::::.....:...:++****++======*##==***:*+=....  ");
    Image_Data.Dot_Image.push_back((char*)"      .#*#+##+*+ ...::...=.:::::==::.:.:=++=:=*#+**==+=+####*:");
    Image_Data.Dot_Image.push_back((char*)"     .#+=#*#*+#+.:+...:=::.=++=#=+++==+=:..   .=+*::==:::**##:");
    Image_Data.Dot_Image.push_back((char*)"     .*#***+*+*+......=:+:.:::=::.:*=.... =+=*=+=+*+=####+:=#+");
    Image_Data.Dot_Image.push_back((char*)"   :++#+=++*#+*+.:::=++:++=.:.=...+: :::+==+==+++**+=+++++*==+");
    Image_Data.Dot_Image.push_back((char*)" =#++#*****##+**====::+*++:+:==:=+*::+**##*++++****+=****+#*=+");
    Image_Data.Dot_Image.push_back((char*)"  .###**#***#+*#**++=====+==+*+*+*#+==+*++++##**#*+:=#*#+*#+*+");
    Image_Data.Dot_Image.push_back((char*)" :+##*+++***##*####*+++++***+++**+**+==+++++++**#*************");
    Image_Data.Dot_Image.push_back((char*)"  *******+****+****#**###*+++++*++**##*++++++*****************");
    Image_Data.Dot_Image.push_back((char*)"  ***++++****#***************+**++**###***##**#**++***++**+**+");
    Image_Data.Dot_Image.push_back((char*)" %#****#######%#######%#***+*#**#####%++*##=***%+=+#*=*#***++*");
    Image_Data.Dot_Image.push_back((char*)"  ===========+****=*#**%###+*######%*.=**:   ..:###=+++=#*=+++");
    Image_Data.Dot_Image.push_back((char*)"                 =#+*   +%#%%%####%*  :**        :*#*+*###**+*");
    Image_Data.Dot_Image.push_back((char*)"                  ::.     **+:+*##                   :##*##==#");
    Image_Data.Dot_Image.push_back((char*)"                          ==: ===+*=                         .");
    Image_Data.Dot_Image.push_back((char*)"                               =:=*##=                 =+*+*+*");
    Image_Data.Dot_Image.push_back((char*)"                                  :=:.                :=+**++*");
    Image_Data.Dot_Image.push_back((char*)"                                                            ..");
    Image_Data.State = OBJECT_STATE::STATE_NORMAL;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();

    Image_Data.Dot_Image.push_back((char*)"                                 . :##*#                       ");
    Image_Data.Dot_Image.push_back((char*)"                                .*=++*=                        ");
    Image_Data.Dot_Image.push_back((char*)"                               +=+*#+                          ");
    Image_Data.Dot_Image.push_back((char*)"                              ::==+===                         ");
    Image_Data.Dot_Image.push_back((char*)"                  ..    ++:  :::+*+..:#+    .+++               ");
    Image_Data.Dot_Image.push_back((char*)"                 ***   :#** :+=:.::++=:=*+. =+*#               ");
    Image_Data.Dot_Image.push_back((char*)"               ..==:::.:.:.:*..=:.:+**+...::..:.::=*::..       ");
    Image_Data.Dot_Image.push_back((char*)"       =*****%#*..=::::..:..+*+++**++++=::::=#*++==*=.*=       ");
    Image_Data.Dot_Image.push_back((char*)"     :*+****#%=*:::.. ...:....=++***++===:==+##*:+*#+=#+=::::  ");
    Image_Data.Dot_Image.push_back((char*)"     #*#+##*+%=+ ....:...=.::=.==:::::..=++==:=**+**:+==+##%#*:");
    Image_Data.Dot_Image.push_back((char*)"    *#:#*#***%+*.:+...:==:..++=+*=*=*:++:... . :=+*::+=:::+*##:");
    Image_Data.Dot_Image.push_back((char*)"   .+#***+***%+*.....:=:+=::.=:=:::=+:... .=*++=*:*#=+####+:=#+");
    Image_Data.Dot_Image.push_back((char*)" :+***=++*#**%+*.::::++:+++::.=:..=+. =:=+=++===+***=++++++*==+");
    Image_Data.Dot_Image.push_back((char*)"#*+*#****#***%:*====::+*++:+=:+:==*===***#**++++****=+****+#++*");
    Image_Data.Dot_Image.push_back((char*)":%##****#*#**%+#**+++====+==++***+#*===+++++*##*##*=.+#*#+**+*+");
    Image_Data.Dot_Image.push_back((char*)" :+*:+=+==##%%=####**++++***++++*+*#*+==+++++++**#*************");
    Image_Data.Dot_Image.push_back((char*)"   . .    *##%+#******###*+++++*+++*###++++++******************");
    Image_Data.Dot_Image.push_back((char*)"          *##%:#*******#*****++*++***##***##***#*++****+***+**+");
    Image_Data.Dot_Image.push_back((char*)":=++:*=++**##%*%%###%#%#****+*#*#####%#++*#+***##+=*#+=*#***++*");
    Image_Data.Dot_Image.push_back((char*)"***********###:+**=+#**%###***%*####%:.**+.  ...=###=+++=#*=+++");
    Image_Data.Dot_Image.push_back((char*)"##########%%%.   :#**   =%#########%.  **+        =*#*+*###**+*");
    Image_Data.Dot_Image.push_back((char*)" ...........      ::.     =**:=+*#+                   :##*##==#");
    Image_Data.Dot_Image.push_back((char*)"                          :== :+=++*:                         .");
    Image_Data.Dot_Image.push_back((char*)"                               =:=***#                 .=**+*+*");
    Image_Data.Dot_Image.push_back((char*)"                                  .:::                 :=+**++*");
    Image_Data.Dot_Image.push_back((char*)"                                                             ..");
    Image_Data.State = OBJECT_STATE::STATE_HIT;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();


    Image_Data.Dot_Image.push_back((char*)"                   .=++++++++++.                            ");
    Image_Data.Dot_Image.push_back((char*)"                 :###***++++***##+:                         ");
    Image_Data.Dot_Image.push_back((char*)"                +#**++==:::::==::=##                        ");
    Image_Data.Dot_Image.push_back((char*)"        :=*########**++:.     .:=. .*=+#******#==.          ");
    Image_Data.Dot_Image.push_back((char*)"     .#####***++++++++=:==:      ::  +==:=++++***###:       ");
    Image_Data.Dot_Image.push_back((char*)"    ###*++====:.:::.:=:=. .:.     :. ..     .:==+==+#*      ");
    Image_Data.Dot_Image.push_back((char*)"   ##*++=::.            ...  .                .:=++ =##     ");
    Image_Data.Dot_Image.push_back((char*)" ###*+=..                ....                    =++ :#+    ");
    Image_Data.Dot_Image.push_back((char*)"+#*=**=:..  .        .:+++++==..                  += :**    ");
    Image_Data.Dot_Image.push_back((char*)".#+*##**++=:....    .++:..++:.                   .=  :+##:  ");
    Image_Data.Dot_Image.push_back((char*)" +#*==+++=::.:.::...=+.  +=                      .  :+++*#* ");
    Image_Data.Dot_Image.push_back((char*)"#*..=+=:.  :::..    .=.  .:                        ..=++.+#=");
    Image_Data.Dot_Image.push_back((char*)"#:.++:.  ..  .       ..    .                        .:=++.##");
    Image_Data.Dot_Image.push_back((char*)"#.=+=:.            .               +:   +:     ..  .:=+= +# ");
    Image_Data.Dot_Image.push_back((char*)"#*:++=::        .::   ..         .:+: .=+:::::=. .:=+=:.+#: ");
    Image_Data.Dot_Image.push_back((char*)"=#*+++. ..     .:+.  :+       ..:=+=:+++:....::==+++***##:  ");
    Image_Data.Dot_Image.push_back((char*)"  *#=: .=       .=+:..++:    . .:=++==:   .....::==+*#*=+#: ");
    Image_Data.Dot_Image.push_back((char*)"   **: ++.       .=++==+=::..                      .=*#**#= ");
    Image_Data.Dot_Image.push_back((char*)"   ##. ++=         ..:===:.                      ..:=+###=  ");
    Image_Data.Dot_Image.push_back((char*)"    ##+.=+=:.           .    ..  .:.          .:==++*##:    ");
    Image_Data.Dot_Image.push_back((char*)"     =##++++==:.:.  .. .:.    .:=..::======:===+++*###:     ");
    Image_Data.Dot_Image.push_back((char*)"       =*####****++++*. :=.      ==++********#######:       ");
    Image_Data.Dot_Image.push_back((char*)"           .========..++. ==:.     .=++**####===:           ");
    Image_Data.Dot_Image.push_back((char*)"                       +#*=:=++====++++*##.                 ");
    Image_Data.Dot_Image.push_back((char*)"                         .*####****#####=                   ");
    Image_Data.Dot_Image.push_back((char*)"                            ...........                     ");
    Image_Data.State = OBJECT_STATE::STATE_DIE1;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();



    Image_Data.Dot_Image.push_back((char*)"                     . . =::=  ..    . . =::= . .");
    Image_Data.Dot_Image.push_back((char*)"                :#####**#####:  :#####**#####:");
    Image_Data.Dot_Image.push_back((char*)"              .###*+++++==:+******+:==+++++*###.");
    Image_Data.Dot_Image.push_back((char*)"              ###*+++==:...  ::::  ...:==+++*###");
    Image_Data.Dot_Image.push_back((char*)"     :++*::=**##*+++:                    :+++*##**=::**");
    Image_Data.Dot_Image.push_back((char*)"    ##=.*##**+*#=+==                      ==+=#*+**##*.");
    Image_Data.Dot_Image.push_back((char*)"   #= ###*++==:+= :                        : =+:==++*##* .#");
    Image_Data.Dot_Image.push_back((char*)"   * ##*++==...  .                          .  ...==++*## *");
    Image_Data.Dot_Image.push_back((char*)"    ##*++==.                                      .==++*##");
    Image_Data.Dot_Image.push_back((char*)"   :##+++=.                       .:=+++.          .=+++##:");
    Image_Data.Dot_Image.push_back((char*)" = =##:+:=.      ..::.              :+.:+=.        .=:+:##= =");
    Image_Data.Dot_Image.push_back((char*)" %. ##+.+ .    .++:++:..             :: .+.        . +.+## .%");
    Image_Data.Dot_Image.push_back((char*)" *# .##= .    .+: :+                    .           . =##. #*");
    Image_Data.Dot_Image.push_back((char*)"  +: :#+=.     :.  :                                .=+#: :+ ");
    Image_Data.Dot_Image.push_back((char*)"   :  .#=:                                          :=#.  :  ");
    Image_Data.Dot_Image.push_back((char*)"  #. +#+=                                            =+#+ .# ");
    Image_Data.Dot_Image.push_back((char*)" #* =##...                               .  .:      ...##= *#");
    Image_Data.Dot_Image.push_back((char*)" #  ##=:=..                               +  =:    ..=:=##  #");
    Image_Data.Dot_Image.push_back((char*)" . +##=+:+.           :.  .            .:+=:++.    .+:+=##+ .");
    Image_Data.Dot_Image.push_back((char*)"    ##*++=..         :=  +             .:==:.     ..=++*##");
    Image_Data.Dot_Image.push_back((char*)"    *##*++=..        .++:=+:.                    ..=++*##*");
    Image_Data.Dot_Image.push_back((char*)"   # ##**+==:.....     .:==:.               .....:==+**## #");
    Image_Data.Dot_Image.push_back((char*)"   ** +##*++===*:.=.                      .=.:*===++*##+ **");
    Image_Data.Dot_Image.push_back((char*)"    +#+ =*###*##=*+=                      =+*=##*###*= +#+");
    Image_Data.Dot_Image.push_back((char*)"      :=*. .=+##*+++=.  .            .  .=+++*##:=. .*=:");
    Image_Data.Dot_Image.push_back((char*)"              *##*++++==::. .=::=. .::==++++*##*");
    Image_Data.Dot_Image.push_back((char*)"               +##**+++++=+*##==##*+=+++++**##+");
    Image_Data.Dot_Image.push_back((char*)"                 +*########*+    +*########*+");
    Image_Data.Dot_Image.push_back((char*)"                 .:.      .:.    .:.      .:.");
    Image_Data.State = OBJECT_STATE::STATE_DIE2;
    m_vecImageList.push_back(Image_Data);
    Image_Data.Dot_Image.clear();

}

