#pragma once

// ../ : 이전폴더
#include "../GameInfo.h"

class CLevelManager
{
private:
	CLevelManager();
	~CLevelManager();

private:
	static CLevelManager* mInst;

public:
	static CLevelManager* GetInst()
	{
		if (!mInst)
			mInst = new CLevelManager;

		return mInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(mInst);
	}

private:
	class CLevel* mLevel;

public:
	CLevel* GetLevel()
	{
		return mLevel;
	}

public:
	void Init();
	void Input(float DeltaTime);
	void Update(float DeltaTime);
	void Collision(float DeltaTime);
	void Render(HDC hDC);
};

