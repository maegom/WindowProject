#include "Bullet.h"
#include "../GameManager.h"

CBullet::CBullet() :
	mDir(0)
{
}

CBullet::CBullet(const CBullet& Obj)
	: CObject(Obj)
{
	mDir = Obj.mDir;
}

CBullet::~CBullet()
{

}

void CBullet::Init()
{
	CObject::Init();

	SetMoveSpeed(400.f);
}

void CBullet::Input(float DeltaTime)
{
	CObject::Input(DeltaTime);
	
	Move(0.f, (float)mDir);
}

void CBullet::Update(float DeltaTime)

{
	CObject::Update(DeltaTime);

	if (mDir == -1)
	{
		if (mPos.y + mSize.y <= 0.f)
		{
			SetActive(false);
		}
	}
	
}

void CBullet::Collision(float DeltaTime)
{
	CObject::Collision(DeltaTime);
}

void CBullet::Render(HDC hDC)
{
	CObject::Render(hDC);
}
