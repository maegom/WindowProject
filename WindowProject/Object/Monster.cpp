#include "Monster.h"

#include "../GameManager.h"

CMonster::CMonster() :
	mDir(1)
{
}

CMonster::CMonster(const CMonster& Obj)	:
	CCharacter(Obj)
{
}

CMonster::~CMonster()
{
}

void CMonster::Init()
{
	CCharacter::Init();

	SetMoveSpeed(300.f);
}

void CMonster::Input(float DeltaTime)
{
	CCharacter::Input(DeltaTime);

	Move((float)mDir, 0.f);

	//Vector2D	MoveDir;

	//static bool horizRight = true;

	////화면 크기
	//Resolution RS = CGameManager::GetInst()->GetResolution();

	//if (horizRight)
	//	Move(1.0f, 0.f);
	//else 
	//	Move(-1.0f, 0.f);
	//
	//if(mPos.x + mSize.x >= RS.Width )
	//	horizRight = false;

	//if (mPos.x <= 0.f)
	//	horizRight = true;
	 
}

void CMonster::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);

	// GameManager가 가지고 있는 윈도우 크기를 얻어온다.
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	// CObject의 Update에서 이동이 되었을 것이다.
	if (mPos.x + mSize.x >= RS.Width)
	{
		mPos.x = RS.Width - mSize.x;
		mDir = -1;
	}

	else if (mPos.x <= 0.f)
	{
		mPos.x = 0.f;
		mDir = 1;
	}
}

void CMonster::Collision(float DeltaTime)
{
	CCharacter::Collision(DeltaTime);
}

void CMonster::Render(HDC hDC)
{
	CCharacter::Render(hDC);
}

