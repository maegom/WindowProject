#include "Object.h"

CObject::CObject() :
	mSize(100.f, 100.f),
	mName{}
{
}

CObject::CObject(const CObject& obj)
{
}

CObject::~CObject()
{
}

void CObject::Init()
{
}

void CObject::Input(float DeltaTime)
{
}

void CObject::Update(float DetlaTime)
{
}

void CObject::Collision(float DeltaTime)
{
}

void CObject::Render(HDC hDC)
{
	Rectangle(hDC, (int)mPos.x, (int)mPos.y, (int)(mPos.x + mSize.x),
		(int)(mPos.y + mSize.y));
}