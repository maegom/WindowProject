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
	//���� �ʱ�ȭ
	CLevel::Init();

	//�÷��̾� ����
	CreateObj<CPlayer>("Player", Vector2D(300.f, 500.f));

	//���� ����
	CreateObj<CMonster>("Monster", Vector2D(500.f, 50.f), Vector2D(50.f,50.f));

	//���� ����
	CreateObj<CBullet>("Bullet", Vector2D(300.f, 500.f), Vector2D(25.f, 25.f));
	 
}
