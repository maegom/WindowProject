#include "Player.h"
//#include "../Level/Level.h"
#include "Bullet.h"

CPlayer::CPlayer()
{
}

CPlayer::CPlayer(const CPlayer& Obj) :
	CCharacter(Obj)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	CCharacter::Init();

	SetMoveSpeed(500.f);
}

void CPlayer::Input(float DeltaTime)
{
	CCharacter::Input(DeltaTime);

	// VK_SPACE : Space Bar
	// VK_RETURN : Enter
	// VK_F1 : F1키

	// GetAsyncKeyState : 키 입력을 감지한다. 키를 누르게 된다면
	// 0x8000 을 반환한다.
	// 0 & 1000 0000 0000 0000 = 0
	// 1000 0000 0000 0000 & 1000 0000 0000 0000 = 1000 0000 0000 0000
	Vector2D	MoveDir;

	if (GetAsyncKeyState('W') & 0x8000)
	{
		MoveDir.y += -1.f;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		MoveDir.y += 1.f;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		MoveDir.x += -1.f;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		MoveDir.x += 1.f;
	}
	class CLevel {};
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		
	//	CreateObj<CBullet>("Bullet", Vector2D(300.f, 500.f), Vector2D(25.f, 25.f));
	}

	MoveDir.Normalize();

	Move(MoveDir);
}

void CPlayer::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);
}

void CPlayer::Collision(float DeltaTime)
{
	CCharacter::Collision(DeltaTime);
}

void CPlayer::Render(HDC hDC)
{
	CCharacter::Render(hDC);
}
