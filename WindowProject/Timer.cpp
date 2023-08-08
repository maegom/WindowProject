#include "Timer.h"

float CTimer::mDeltaTime = 0.f;
float CTimer::mFPS = 0.f;
float CTimer::mFPSTime = 0.f;
int CTimer::mTick = 0;

LARGE_INTEGER CTimer::mSecond = {};
LARGE_INTEGER CTimer::mPrevTime = {};

void CTimer::Init()
{
	// 윈도우 고해상도 타이머의 초당 값을 얻어온다.
	QueryPerformanceFrequency(&mSecond);

	// 윈도우 고해상도 타이머의 현재 값을 얻어온다.
	QueryPerformanceCounter(&mPrevTime);
}

float CTimer::Update()
{
	LARGE_INTEGER	Time;
	QueryPerformanceCounter(&Time);

	// (현재 고해상도 타이머값 - 이전프레임 고해상도 타이머값) / 초당 타이머값
	mDeltaTime = (Time.QuadPart - mPrevTime.QuadPart) / (float)mSecond.QuadPart;

	// 다음 프레임에서는 현재의 타이머값이 이전프레임의 타이머 값이 되어야
	// 하므로 mPrevTime을 현재 타이머값으로 갱신해준다.
	mPrevTime = Time;

	// 시간을 누적시켜서 저장한다.
	mFPSTime += mDeltaTime;
	++mTick;

	if (mTick == 60)
	{
		// 60만큼 프레임이 반복될동안 몇초가 흘렀는지를 이용해서 1초가 흘렀을경우
		// 기대되는 프레임 수를 구한다.
		// 예를 들어 60프레임이 흐를 동안 mFPSTime이 0.2라면 0.2초가 흘렀다는
		// 것이다. 그렇다면 1초가 되었을 때 예상할 수 있는 프레임은 300프레임이
		// 될 것이다.
		mFPS = mTick / mFPSTime;
		mFPSTime = 0.f;
		mTick = 0;
	}

	return mDeltaTime;
}