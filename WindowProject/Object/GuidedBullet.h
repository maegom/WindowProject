#pragma once
#include "Object.h"
class CGuidedBullet :
	public CObject
{
public:
	CGuidedBullet();
	CGuidedBullet(const CGuidedBullet& Obj);
	virtual ~CGuidedBullet();

private:
	Vector2D	mGuidedDir;

public:
	void SetGuidedDir(const Vector2D& Dir)
	{
		mGuidedDir = Dir;
	}

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual void Collision(CObject* Dest);
};

