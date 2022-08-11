#include "BossEnemy.h"
#include "CursorManager.h"

BossEnemy::BossEnemy() {}
BossEnemy::~BossEnemy() {}

void BossEnemy::Initialize()
{
    m_iColor = 15;
    m_iSpeed = 0.5f;
    m_eState = OBJECT_STATE::STATE_NORMAL;

    Image_Initialize();


    
    //Disable
    InputImage(OBJECT_STATE::STATE_NORMAL);
}

int BossEnemy::Update(Transform& Info)
{
    Info.Direction.x = -1;
    Info.Position += Info.Direction * m_iSpeed;

    return 0;
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
    else if (Hp < 4)
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
    Image_Data.Dot_Image.clear();
    m_vecImageList.push_back(Image_Data);

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
    Image_Data.Dot_Image.clear();
    m_vecImageList.push_back(Image_Data);


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
    Image_Data.Dot_Image.clear();
    m_vecImageList.push_back(Image_Data);


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
    Image_Data.Dot_Image.clear();
    m_vecImageList.push_back(Image_Data);
}

void BossEnemy::Shoot_Bullet()
{
}
