#include "GameManager.h"
#include "resource.h"
#include "Level/LevelManager.h"
#include "Timer.h"

//�ʱ�ȭ 
CGameManager* CGameManager::mInst = nullptr;
bool CGameManager::mLoop = true;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
    CLevelManager::DestroyInst();

    ReleaseDC(mhWnd, mhDC);
}

bool CGameManager::Init(HINSTANCE hInst)
{
	mhInst = hInst;

	mRS.Width = 1280;
	mRS.Height = 720;

	MyRegisterClass();
	AddWindow();

    mhDC = GetDC(mhWnd);

    //Ÿ�̸� �ʱ�ȭ
    CTimer::Init();

    //���� ������ �ʱ�ȭ
    CLevelManager::GetInst()->Init();

	return true;
}

int CGameManager::Run()
{
    MSG msg;

    // �⺻ �޽��� �����Դϴ�: // mLoop �� ���̸� ��� ����.
    while (mLoop)
    {
       // if (WM_QUIT == msg.message) //���� ����ó���� ������Ѵ�.
        //    break;
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Logic();
            //�޼����� ���� �� ������ ��
        }
    }
    return (int)msg.wParam;
}

void CGameManager::Logic()
{
    float DeltaTime = CTimer::Update();

    Input(DeltaTime);

    Update(DeltaTime);

    Collision(DeltaTime);

    Render();
}
void CGameManager::Input(float DeltaTime)
{
    CLevelManager::GetInst()->Input(DeltaTime);
}

void CGameManager::Update(float DeltaTime)
{
    CLevelManager::GetInst()->Update(DeltaTime);
}

void CGameManager::Collision(float DeltaTime)
{
    CLevelManager::GetInst()->Collision(DeltaTime);
}


void CGameManager::Render()
{
    CLevelManager::GetInst()->Render(mhDC);

    //FPS ���
    char    FPS[256] = {};

    //sprintf_s(������ ����, ���� ���ڿ�, ���Ŀ� �����ϴ� �����͵�)
    sprintf_s(FPS, "FPS : %.5f", CTimer::GetFPS());

    //TextOutA(�ڵ�, x��ǥ, y��ǥ, ���ڿ� ������, ���ڿ� ����)
    TextOutA(mhDC, 1000, 30, FPS, strlen(FPS));
}

//
//  �Լ�: MyRegisterClass()
//
//  �뵵: â Ŭ������ ����մϴ�.
//
ATOM CGameManager::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;  //�޼����� �߻������� ȣ���� �Լ�
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = mhInst;
    wcex.hIcon = LoadIcon(mhInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;// MAKEINTRESOURCEW(IDC_MY0808);
    wcex.lpszClassName = L"TestWindows";  //L"���ڿ�" : �����ڵ� ���ڿ�
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: AddWindow( )
//
//   �뵵: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   �ּ�:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
bool CGameManager::AddWindow()
{ 
    //hWnd : ������ â�� ������ �ĺ���ȣ 
    mhWnd = CreateWindowW(L"TestWindows", L"���� ��Ÿ����", WS_OVERLAPPEDWINDOW, //������â ����
        100, 100, 1000, 600, nullptr, nullptr, mhInst, nullptr);  //CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
    //������â ���� ��ġ (�� ��� ���� 0,0) //���� ���� âũ�� 
    if (!mhWnd)
    {
        return false;
    }

    RECT    rc = { 0, 0, mRS.Width, mRS.Height };

    // �޴�, ƽ������ ���� �����Ͽ� Ŭ���̾�Ʈ ������ ũ�Ⱑ ������ �ػ󵵸�ŭ
    // ������ �� �ְ� ���� ũ�⸦ �����ش�.
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    SetWindowPos(mhWnd, HWND_TOPMOST, -mRS.Width, 100, rc.right - rc.left,
        rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);

    ShowWindow(mhWnd, SW_SHOW);
    UpdateWindow(mhWnd);

    return true;
}

//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
LRESULT CGameManager::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;

        //HDC : ȭ�鿡 ���𰡸� �׸��� ����Ѵ�. 
        HDC hdc = BeginPaint(hWnd, &ps);

        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

     
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        mLoop = false;
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
