#pragma once

#include "../GameInfo.h"

class CObject
{

public : 
	CObject();
	CObject(const CObject& obj);
	virtual ~CObject();

protected:
	char		mName[32];
	Vector2D	mPos;
	Vector2D	mSize;
	Vector2D	mMoveDir;
	float		mMoveSpeed;
	bool		mActive; //살아있나 죽어있나 판단,  true = 살아있다. 

public:
	bool GetActive()	const
	{
		return mActive;
	}

	const char* GetName()	const
	{
		return mName;
	}

	const Vector2D& GetPos()	const
	{
		return mPos;
	}

	const Vector2D& GetSize()	const
	{
		return mSize;
	}

	void SetPos(const Vector2D& Pos)
	{
		mPos = Pos;
	}

	void SetPos(float x, float y)
	{
		mPos.x = x;
		mPos.y = y;
	}

	void SetSize(const Vector2D& Size)
	{
		mSize = Size;
	}

	void SetSize(float x, float y)
	{
		mSize.x = x;
		mSize.y = y;
	}

	void SetName(const char* Name)
	{
		strcpy_s(mName, Name);
	}

	void SetActive(bool Active)
	{
		mActive = Active;
	}

	void SetMoveSpeed(float Speed)
	{
		mMoveSpeed = Speed;
	}

public:
	void Move(const Vector2D& MoveDir)
	{
		mMoveDir = MoveDir;
	}

	void Move(float x, float y)
	{
		mMoveDir.x = x;
		mMoveDir.y = y;
	}

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
};

