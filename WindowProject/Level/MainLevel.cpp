#include "MainLevel.h"
#include "../Object/Player.h"

CMainLevel::CMainLevel()
{
}

CMainLevel::~CMainLevel()
{
}

void CMainLevel::Init()
{
	CLevel::Init();

	CreateObj<CPlayer>("Player", Vector2D(300.f, 500.f));
}
