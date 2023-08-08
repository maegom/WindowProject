#pragma once

#include "GameInfo.h"

class CTimer
{
private :
	static LARGE_INTEGER	mSecond;
	static LARGE_INTEGER	mPrevTime;
	static float	mDeltaTime;

	static float	mFPS;
	static float	mFPSTime;
	static int		mTick;

public :
	static float GetDeltaTime()
	{
		return mDeltaTime;
	}

	static float GetFPS()
	{
		return mFPS;
	}

public :
	
	static void Init();
	static float Update();
};

