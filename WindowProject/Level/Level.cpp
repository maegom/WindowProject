#include "Level.h"
#include "../Object/Object.h"

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
	// 레벨이 제거될때 레벨이 가지고 있는 모든 오브젝트를 제거한다.
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE((*iter));
	}
}

void CLevel::Init()
{
}

void CLevel::Input(float DeltaTime)
{
}

void CLevel::Update(float DeltaTime)
{
}

void CLevel::Collision(float DeltaTime)
{
}

void CLevel::Render(HDC hDC)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render(hDC);
	}
}
