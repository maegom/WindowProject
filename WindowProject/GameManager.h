#pragma once

#include "GameInfo.h"

//���� �Ŵ��� Ŭ����
class CGameManager
{
	//�̱��� 
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
	HINSTANCE	mhInst; //���α׷� �������� ID�� instance Handle
	HWND		mhWnd;  //���α׷����� ������ �ڵ� (number) 
	Resolution	mRS;	//ȭ�� ũ�� (�ػ�)
	HDC			mhDC;	//��¿� �ʿ��� ����

	static bool	mLoop;  //�ݺ� ���� �Ǵ� bool

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
	ATOM MyRegisterClass(); //������ ���� ���� 
	bool AddWindow();		//������ ����

private:
	//������ �޽����� ó��
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); //static ���� �����ϸ� �Լ��̸��� �ּ�.
}; 