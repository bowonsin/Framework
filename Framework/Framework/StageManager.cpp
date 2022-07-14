#include "StageManager.h"

StageManager* StageManager::Instance = nullptr;

StageManager::StageManager():Stage_Id(nullptr) {}
StageManager::~StageManager() { Release(); }

void StageManager::GetStage()
{

}

void StageManager::Update()
{
}

void StageManager::Render()
{
}

void StageManager::Release()
{
}

