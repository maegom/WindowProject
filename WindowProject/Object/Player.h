#pragma once
#include "Character.h"
class CPlayer :
	public CCharacter
{
public:
	CPlayer();
	CPlayer(const CPlayer& Obj);
	virtual ~CPlayer();

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
};

