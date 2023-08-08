#pragma once
#include "Object.h"
class CCharacter :
    public CObject
{

public:
	CCharacter();
	CCharacter(const CCharacter& obj);
	virtual ~CCharacter();

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DetlaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);

};

