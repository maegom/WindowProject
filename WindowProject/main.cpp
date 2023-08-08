#include "GameManager.h"

//windows API
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    //�ʱ�ȭ
    if (!CGameManager::GetInst()->Init(hInstance))
    {
        CGameManager::DestroyInst();
        return 0;
    }

    //����
    int Result = CGameManager::GetInst()->Run();

    //����
    CGameManager::DestroyInst();

    return Result;
}