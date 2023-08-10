#include "MainLevel.h"
#include "../Object/Player.h"
#include "../Object/Monster.h"
#include "../Object/Bullet.h"

CMainLevel::CMainLevel()
{
}

CMainLevel::~CMainLevel()
{
}

void CMainLevel::Init()
{
	//레벨 초기화
	CLevel::Init();

	//플레이어 생성
	CreateObj<CPlayer>("Player", Vector2D(300.f, 500.f));

	//몬스터 생성
	CreateObj<CMonster>("Monster", Vector2D(500.f, 50.f), Vector2D(50.f,50.f));

	 
}
