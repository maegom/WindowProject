#include "Player.h"

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
}

void CPlayer::Input(float DeltaTime)
{
	CCharacter::Input(DeltaTime);
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
