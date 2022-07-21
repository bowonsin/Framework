#include "BossEnemy.h"

BossEnemy::BossEnemy() {}
BossEnemy::~BossEnemy() {}

void BossEnemy::Initialize()
{
    m_iColor = 15;
    m_iSpeed = 0.5f;
    m_eState = ENEMY_STATE::STATE_NORMAL;

    m_vecImage.push_back((char*)"       .~--.--   ");
    m_vecImage.push_back((char*)"      ;***.=*:--~");
    m_vecImage.push_back((char*)"     --****=-;**-");
    m_vecImage.push_back((char*)"  ~!!*=~..~=****=");
    m_vecImage.push_back((char*)"  :**-      .=**-");
    m_vecImage.push_back((char*)"   :. ,      .*=.");
    m_vecImage.push_back((char*)"   ~.         !~ ");
    m_vecImage.push_back((char*)"   ~...       ~  ");
    m_vecImage.push_back((char*)" ~  -!        .  ");
    m_vecImage.push_back((char*)" , , ~       -,-.");
    m_vecImage.push_back((char*)"  --:.    , .-*~ ");
    m_vecImage.push_back((char*)"   .~-~.:*=.**** ");
    m_vecImage.push_back((char*)"   ,..-,*:=***** ");
    m_vecImage.push_back((char*)" .~. -, -..,**** ");
    m_vecImage.push_back((char*)".,...;,: .;-****~");
    m_vecImage.push_back((char*)" --;-:::,*******=");
    m_vecImage.push_back((char*)"  ~. .;-::****** ");
    m_vecImage.push_back((char*)"  .-,-::~:.=**** ");
    m_vecImage.push_back((char*)"    :;-  ,~:, .. ");
    m_vecImage.push_back((char*)"      ~:         ");
}

int BossEnemy::Update(Transform& Info)
{
    return 0;
}

void BossEnemy::Render()
{
}

void BossEnemy::Release()
{
}

void BossEnemy::InputImage()
{
}

void BossEnemy::MoveImage()
{
    switch (m_eState)
    {
    case ENEMY_STATE::STATE_NORMAL:
    {
        m_vecImage.clear();
        m_vecImage.push_back((char*)"       .~--.--   ");
        m_vecImage.push_back((char*)"      ;***.=*:--~");
        m_vecImage.push_back((char*)"     --****=-;**-");
        m_vecImage.push_back((char*)"  ~!!*=~..~=****=");
        m_vecImage.push_back((char*)"  :**-      .=**-");
        m_vecImage.push_back((char*)"   :. ,      .*=.");
        m_vecImage.push_back((char*)"   ~.         !~ ");
        m_vecImage.push_back((char*)"   ~...       ~  ");
        m_vecImage.push_back((char*)" ~  -!        .  ");
        m_vecImage.push_back((char*)" , , ~       -,-.");
        m_vecImage.push_back((char*)"  --:.    , .-*~ ");
        m_vecImage.push_back((char*)"   .~-~.:*=.**** ");
        m_vecImage.push_back((char*)"   ,..-,*:=***** ");
        m_vecImage.push_back((char*)" .~. -, -..,**** ");
        m_vecImage.push_back((char*)".,...;,: .;-****~");
        m_vecImage.push_back((char*)" --;-:::,*******=");
        m_vecImage.push_back((char*)"  ~. .;-::****** ");
        m_vecImage.push_back((char*)"  .-,-::~:.=**** ");
        m_vecImage.push_back((char*)"    :;-  ,~:, .. ");
        m_vecImage.push_back((char*)"      ~:         ");
        break;
    }
    case ENEMY_STATE::STATE_MOVE:
    {
        m_vecImage.clear();
        m_vecImage.push_back((char*)"          ., .. ");
        m_vecImage.push_back((char*)"     ~;=!;:,-., ");
        m_vecImage.push_back((char*)"    .:-=*==;==~ ");
        m_vecImage.push_back((char*)"  :=;!-..,!**=~ ");
        m_vecImage.push_back((char*)"  ~=;-,    ,*=- ");
        m_vecImage.push_back((char*)"  .!. ..    ~~  ");
        m_vecImage.push_back((char*)"   ~...-    .   ");
        m_vecImage.push_back((char*)"   ::.,.        ");
        m_vecImage.push_back((char*)" .. ,:,     .   ");
        m_vecImage.push_back((char*)" -...,.   ..,,, ");
        m_vecImage.push_back((char*)" .~~--. .,,--:  ");
        m_vecImage.push_back((char*)"   .;~,.;==***  ");
        m_vecImage.push_back((char*)"   ~--~.*=:,;*  ");
        m_vecImage.push_back((char*)"  ..,,,.=:.,-*~ ");
        m_vecImage.push_back((char*)" ., ,-,~=!~-;*; ");
        m_vecImage.push_back((char*)" ,~ -::~~**-:~*,");
        m_vecImage.push_back((char*)"  -:~~~,:*!!~=~ ");
        m_vecImage.push_back((char*)"  ~;-~-~,:!!~*: ");
        m_vecImage.push_back((char*)"  -~-,-::;!, -  ");
        m_vecImage.push_back((char*)"   ..,-~,--. .  ");
        break;
    }
    }
}

void BossEnemy::DieImage()
{
}
