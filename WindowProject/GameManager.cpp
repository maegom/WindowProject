#include "GameManager.h"
#include "resource.h"
#include "Level/LevelManager.h"
#include "Timer.h"

//초기화 
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

    //타이머 초기화
    CTimer::Init();

    //레벨 관리자 초기화
    CLevelManager::GetInst()->Init();

	return true;
}

int CGameManager::Run()
{
    MSG msg;

    // 기본 메시지 루프입니다: // mLoop 가 참이면 계속 돈다.
    while (mLoop)
    {
       // if (WM_QUIT == msg.message) //따로 예외처리를 해줘야한다.
        //    break;
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Logic();
            //메세지가 없을 때 실행할 일
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

    //FPS 출력
    char    FPS[256] = {};

    //sprintf_s(저장할 버퍼, 포맷 문자열, 형식에 대응하는 데이터들)
    sprintf_s(FPS, "FPS : %.5f", CTimer::GetFPS());

    //TextOutA(핸들, x좌표, y좌표, 문자열 포인터, 문자열 길이)
    TextOutA(mhDC, 1000, 30, FPS, strlen(FPS));
}

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM CGameManager::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;  //메세지가 발생했을때 호출할 함수
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = mhInst;
    wcex.hIcon = LoadIcon(mhInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;// MAKEINTRESOURCEW(IDC_MY0808);
    wcex.lpszClassName = L"TestWindows";  //L"문자열" : 유니코드 문자열
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

//
//   함수: AddWindow( )
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
bool CGameManager::AddWindow()
{ 
    //hWnd : 윈도우 창에 고유한 식별번호 
    mhWnd = CreateWindowW(L"TestWindows", L"새싹 메타버스", WS_OVERLAPPEDWINDOW, //윈도우창 정보
        100, 100, 1000, 600, nullptr, nullptr, mhInst, nullptr);  //CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
    //윈도우창 시작 위치 (좌 상단 기준 0,0) //가로 세로 창크기 
    if (!mhWnd)
    {
        return false;
    }

    RECT    rc = { 0, 0, mRS.Width, mRS.Height };

    // 메뉴, 틱프레임 등을 포함하여 클라이언트 영역의 크기가 지정된 해상도만큼
    // 생성될 수 있게 실제 크기를 구해준다.
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    SetWindowPos(mhWnd, HWND_TOPMOST, -mRS.Width, 100, rc.right - rc.left,
        rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);

    ShowWindow(mhWnd, SW_SHOW);
    UpdateWindow(mhWnd);

    return true;
}

//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
LRESULT CGameManager::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;

        //HDC : 화면에 무언가를 그릴때 사용한다. 
        HDC hdc = BeginPaint(hWnd, &ps);

        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

     
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
