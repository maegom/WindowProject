#pragma once

#include "Character.h"



class CMonster :
    public CCharacter
{
public :
	CMonster();
	CMonster(const CMonster& Obj);
	virtual ~CMonster();

private:
	// 이동 방향을 선언한다.
	// 이동 방향이 1일 경우 오른쪽 -1일 경우 왼쪽으로 움직인다.
	int		mDir;
	float	mAccTime;
	int		mCount;

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);

};
 