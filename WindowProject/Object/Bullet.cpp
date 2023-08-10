#include "Bullet.h"
#include "../GameManager.h"
#include "GuidedBullet.h"

CBullet::CBullet() :
	mDir(0)
{
	// CBullet의 고유한 번호를 저장한다.
	mTypeID = typeid(CBullet).hash_code();
}

CBullet::CBullet(const CBullet& Obj) :
	CObject(Obj)
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

	else if (mDir == 1)
	{
		Resolution	RS = CGameManager::GetInst()->GetResolution();

		if (mPos.y >= RS.Height)
			SetActive(false);
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

void CBullet::Collision(CObject* Dest)
{
	if (Dest->GetTypeID() == typeid(CBullet).hash_code() ||
		Dest->GetTypeID() == typeid(CGuidedBullet).hash_code())
		return;

	SetActive(false);
}
