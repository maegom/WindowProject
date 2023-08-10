#include "GuidedBullet.h"
#include "../GameManager.h"
#include "Bullet.h"

CGuidedBullet::CGuidedBullet()
{
	//mTypeID = typeid(CBullet).hash_code();
}

CGuidedBullet::CGuidedBullet(const CGuidedBullet& Obj) :
	CObject(Obj)
{
}

CGuidedBullet::~CGuidedBullet()
{
}

void CGuidedBullet::Init()
{
	CObject::Init();

	SetMoveSpeed(500.f);
}

void CGuidedBullet::Input(float DeltaTime)
{
	CObject::Input(DeltaTime);

	Move(mGuidedDir);
}

void CGuidedBullet::Update(float DeltaTime)
{
	CObject::Update(DeltaTime);

	Resolution	RS = CGameManager::GetInst()->GetResolution();

	// 위로 빠져나갔을 경우 
	if (mPos.y + mSize.y <= 0.f || mPos.y >= RS.Height ||
		mPos.x + mSize.x <= 0.f || mPos.x >= RS.Width)
	{
		SetActive(false);
	}
}

void CGuidedBullet::Collision(float DeltaTime)
{
	CObject::Collision(DeltaTime);
}

void CGuidedBullet::Render(HDC hDC)
{
	CObject::Render(hDC);
}

void CGuidedBullet::Collision(CObject* Dest)
{
	if (Dest->GetTypeID() == typeid(CBullet).hash_code() ||
		Dest->GetTypeID() == typeid(CGuidedBullet).hash_code())
		return;

	SetActive(false);
}
