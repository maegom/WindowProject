#include "GameManager.h"

//windows API
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    //초기화
    if (!CGameManager::GetInst()->Init(hInstance))
    {
        CGameManager::DestroyInst();
        return 0;
    }

    //실행
    int Result = CGameManager::GetInst()->Run();

    //제거
    CGameManager::DestroyInst();

    return Result;
}