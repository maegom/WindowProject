#pragma once
#include "Object.h"
class CBullet :
    public CObject
{
public:
	CBullet();
	CBullet(const CBullet& Obj);
	virtual ~CBullet();

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
};



