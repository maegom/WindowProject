#include "LevelManager.h"
#include "MainLevel.h"

CLevelManager* CLevelManager::mInst = nullptr;

CLevelManager::CLevelManager()
{
}

CLevelManager::~CLevelManager()
{
	SAFE_DELETE(mLevel);
}

void CLevelManager::Init()
{
	mLevel = new CMainLevel;

	mLevel->Init();
}

void CLevelManager::Input(float DeltaTime)
{
	mLevel->Input(DeltaTime);
}

void CLevelManager::Update(float DeltaTime)
{
	mLevel->Update(DeltaTime);
}

void CLevelManager::Collision(float DeltaTime)
{
	mLevel->Collision(DeltaTime);
}

void CLevelManager::Render(HDC hDC)
{
	mLevel->Render(hDC);
}
