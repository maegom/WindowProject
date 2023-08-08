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

public:
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


public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DetlaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);

};

