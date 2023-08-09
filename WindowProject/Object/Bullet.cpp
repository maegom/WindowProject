#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::CBullet(const CBullet& Obj)
	: CObject(Obj)
{
}

CBullet::~CBullet()
{

}

void CBullet::Init()
{
	CObject::Init();

	SetMoveSpeed(800.f);
}

void CBullet::Input(float DeltaTime)
{
	CObject::Input(DeltaTime);
	Move(0.f, -1.0f);
}

void CBullet::Update(float DeltaTime)
{
	CObject::Update(DeltaTime);
}

void CBullet::Collision(float DeltaTime)
{
	CObject::Collision(DeltaTime);
}

void CBullet::Render(HDC hDC)
{
	CObject::Render(hDC);
}
