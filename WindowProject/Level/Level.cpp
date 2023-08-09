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
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			//메모리주소를 이용해서 할당된 객체를 제거한다. 
			delete* iter;

			//erase 함수는 지운 노드의 다음노드를 반환한다. 
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Input(DeltaTime);
		++iter;
	}
}

void CLevel::Update(float DeltaTime)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			//메모리주소를 이용해서 할당된 객체를 제거한다. 
			delete* iter;

			//erase 함수는 지운 노드의 다음노드를 반환한다. 
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Update(DeltaTime);
		++iter;
	}
}

void CLevel::Collision(float DeltaTime)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			//메모리주소를 이용해서 할당된 객체를 제거한다. 
			delete* iter;

			//erase 함수는 지운 노드의 다음노드를 반환한다. 
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Collision(DeltaTime);
		++iter;
	}
}

void CLevel::Render(HDC hDC)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			//메모리주소를 이용해서 할당된 객체를 제거한다. 
			delete* iter;

			//erase 함수는 지운 노드의 다음노드를 반환한다. 
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Render(hDC);
		++iter;
	}
}
