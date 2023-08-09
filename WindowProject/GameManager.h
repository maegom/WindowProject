#pragma once

#include "GameInfo.h"

//게임 매니저 클래스
class CGameManager
{
	//싱글톤 
private:
	CGameManager();
	~CGameManager();

private:
	static CGameManager* mInst;

public:
	static CGameManager* GetInst()
	{
		if (!mInst)
			mInst = new CGameManager;
		return mInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(mInst); 
	}

private:
	HINSTANCE	mhInst; //프로그램 구별위한 ID값 instance Handle
	HWND		mhWnd;  //프로그램안의 윈도우 핸들 (number) 
	Resolution	mRS;	//화면 크기 (해상도)
	HDC			mhDC;	//출력에 필요한 정보

	static bool	mLoop;  //반복 여부 판단 bool

public:
	bool Init(HINSTANCE hInst); 
	int Run();

public:
	Resolution GetResolution()
	{
		return mRS;
	}

private : 
	void Logic();
	void Input(float DeltaTime);
	void Update(float DeltaTime);
	void Collision(float DeltaTime);
	void Render( );


	

private:
	ATOM MyRegisterClass(); //윈도우 생성 정보 
	bool AddWindow();		//윈도우 생성

private:
	//윈도우 메시지를 처리
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); //static 으로 선언하면 함수이름이 주소.
}; 